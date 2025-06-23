#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 9;

class Sudoku {
protected:
    int board[N][N];   
    void printBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "|";
            }
            cout << endl;
        }
    }
    bool isSafe(int row, int col, int num) {
        for (int x = 0; x < N; x++)
            if (board[row][x] == num)
                return false;
        for (int x = 0; x < N; x++)
            if (board[x][col] == num)
                return false;
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i + startRow][j + startCol] == num)
                    return false;
        return true;
    }
    int countSolutions(int &solutions) {
        if (solutions > 1) return solutions;
        int row = -1, col = -1;
        bool empty = false;
        for (int i = 0; i < N && !empty; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 0) {
                    row = i;
                    col = j;
                    empty = true;
                    break;
                }
            }
        }
        if (!empty) {
            solutions++;
            return solutions;
        }
        
        for (int num = 1; num <= N; num++) {
            if (isSafe(row, col, num)) {
                board[row][col] = num;
                countSolutions(solutions);
                board[row][col] = 0;
            }
        }
        return solutions;
    }
    bool solveSudoku() {
        int row = -1, col = -1;
        bool empty = false;
        for (int i = 0; i < N && !empty; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 0) {
                    row = i;
                    col = j;
                    empty = true;
                    break;
                }
            }
        }
        if (!empty) return true;

        for (int num = 1; num <= N; num++) {
            if (isSafe(row, col, num)) {
                board[row][col] = num;
                if (solveSudoku()) return true;
                board[row][col] = 0;
            }
        }
        return false;
    }
    void copyBoard(int src[N][N], int dest[N][N]) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dest[i][j] = src[i][j];
    }
public:
    virtual void initializeBoard() = 0;
    virtual void generateOrInput() = 0; 
    void solveAndDisplay() {
        cout << "\nInitial Sudoku board:\n";
        printBoard();

        int solvedBoard[N][N];
        copyBoard(board, solvedBoard);
        if (solveSudoku()) {
            cout << "\nSolved Sudoku:\n";
            printBoard();
        } else {
            cout << "\nNo solution exists\n";
        }
    }
};
class RandomSudoku : public Sudoku {
private:
    int minZeros, maxZeros;
    bool generateFullBoard() {
        int row = -1, col = -1;
        bool empty = false;
        for (int i = 0; i < N && !empty; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 0) {
                    row = i;
                    col = j;
                    empty = true;
                    break;
                }
            }
        }
        if (!empty) return true;
        int nums[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = N - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(nums[i], nums[j]);
        }
        for (int i = 0; i < N; i++) {
            int num = nums[i];
            if (isSafe(row, col, num)) {
                board[row][col] = num;
                if (generateFullBoard()) return true;
                board[row][col] = 0;
            }
        }
        return false;
    }
public:
    RandomSudoku(int min, int max) : minZeros(min), maxZeros(max) {
        srand(time(0));
    }
    void initializeBoard() override {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = 0;
    }
    void generateOrInput() override {
        generateFullBoard();
        int solvedBoard[N][N];
        copyBoard(board, solvedBoard);
        int targetZeros = minZeros + rand() % (maxZeros - minZeros + 1);
        vector<pair<int, int>> cells;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cells.push_back({i, j});
        for (int i = cells.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(cells[i], cells[j]);
        }
        int zeros = 0;
        for (auto cell : cells) {
            int row = cell.first, col = cell.second;
            if (zeros >= targetZeros) break;
            int temp = board[row][col];
            board[row][col] = 0;
            zeros++;
            int tempBoard[N][N];
            copyBoard(board, tempBoard);
            int solutions = 0;
            countSolutions(solutions);
            if (solutions != 1) {
                board[row][col] = temp;
                zeros--;
            }
        }
        while (zeros < minZeros) {
            for (auto cell : cells) {
                int row = cell.first, col = cell.second;
                if (board[row][col] == 0) continue;
                int temp = board[row][col];
                board[row][col] = 0;
                zeros++;
                int tempBoard[N][N];
                copyBoard(board, tempBoard);
                int solutions = 0;
                countSolutions(solutions);
                if (solutions != 1) {
                    board[row][col] = temp;
                    zeros--;
                }
                if (zeros >= minZeros) break;
            }
        }
    }
};
class ManualSudoku : public Sudoku {
public:
    void initializeBoard() override {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = 0;
    }
    void generateOrInput() override {
        cout << "Enter the Sudoku board values (0 for empty cells):\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int num;
                cout << "Enter value for cell (" << i + 1 << ", " << j + 1 << ") [0-9]: ";
                cin >> num;
                if (num < 0 || num > 9) {
                    cout << "Invalid input, using 0\n";
                    num = 0;
                }
                board[i][j] = num;
            }
        }
    }
};
int main() {
    int choice;
    cout << "Choose Sudoku input method:\n";
    cout << "1. Random Sudoku\n";
    cout << "2. Manual Sudoku\n";
    cout << "Enter choice (1-2): ";
    cin >> choice;
    Sudoku* sudoku = nullptr;
    if (choice == 1) {
        int difficulty;
        cout << "Select difficulty level:\n";
        cout << "1. Easy (30-40 zeros)\n";
        cout << "2. Hard (45-55 zeros)\n";
        cout << "Enter choice (1-3): ";
        cin >> difficulty;
        int minZeros, maxZeros;
        switch (difficulty) {
            case 1:
                minZeros = 30;
                maxZeros = 40;
                cout << "Generating Easy Sudoku puzzle...\n";
                break;
            case 2:
                minZeros = 45;
                maxZeros = 55;
                cout << "Generating Medium Sudoku puzzle...\n";
                break;
            default:
                cout << "Invalid choice. Defaulting to Easy.\n";
                minZeros = 30;
                maxZeros = 40;
        }
        sudoku = new RandomSudoku(minZeros, maxZeros);
    } else if (choice == 2) {
        sudoku = new ManualSudoku();
    } else {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }
    sudoku->initializeBoard();
    sudoku->generateOrInput();
    sudoku->solveAndDisplay();
    return 0;
}
