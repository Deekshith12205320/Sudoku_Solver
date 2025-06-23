# Sudoku_Solver
A C++ program that generates and solves 9x9 Sudoku puzzles, offering both random puzzle generation with configurable difficulty and manual puzzle input, using a backtracking algorithm to ensure valid solutions.

Key Features
Random Puzzle Generation: Generates 9x9 Sudoku puzzles with unique solutions, offering Easy (30-40 empty cells) and Hard (45-55 empty cells) difficulty levels.
Manual Puzzle Input: Allows users to input custom Sudoku puzzles, with 0 representing empty cells.
Backtracking Solver: Solves puzzles using a recursive backtracking algorithm, ensuring valid solutions or reporting if none exist.
Solution Uniqueness Check: Verifies that randomly generated puzzles have exactly one solution for fair play.
Clear Display: Prints both the initial and solved Sudoku boards in a readable grid format.

Technologies Used
C++: Core programming language for implementing the Sudoku solver and generator logic.
Standard Template Library (STL): Utilizes vector, algorithm, and iostream for input/output operations.
Random Number Generation: Employs cstdlib and ctime for seeding and generating random numbers to create puzzles.
Object-Oriented Programming: Leverages inheritance and polymorphism with base  and derived classes (RandomSudoku, ManualSudoku).
Backtracking Algorithm: Core technique for solving Sudoku puzzles and ensuring unique solutions.

Instalation
## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/sudoku-solver.git
   ```
2. Navigate to the project directory:
   ```bash
   cd sudoku-solver
   ```
3. Compile the program using a C++ compiler (e.g., g++):
   ```bash
   g++ -o sudoku main.cpp
   ```
4. Run the executable:
   ```bash
   ./sudoku
   ```

 How to Use

Random Puzzle Generation Features

Select Random Mode: Choose option 1 to generate a random Sudoku puzzle with a unique solution.
Choose Difficulty: Pick between Easy (30-40 empty cells) or Hard (45-55 empty cells) to customize the challenge level.
View and Solve: See the generated puzzle displayed, followed by its solved version using the backtracking algorithm.
Manual Puzzle Input Features

Select Manual Mode: Choose option 2 to input your own 9x9 Sudoku puzzle.
Enter Cell Values: Provide values (1-9 for filled cells, 0 for empty cells) for each cell when prompted.
View Solution: See the initial puzzle displayed, followed by the solved puzzle or a message if no solution exists.

ScreenShots
<img width="1470" alt="1" src="https://github.com/user-attachments/assets/f31d146c-2f11-4c78-aa8f-becd621c3b7b" />

![image](https://github.com/user-attachments/assets/de48efef-04e9-4f6b-bcd1-243ae6bc8d66)

![image](https://github.com/user-attachments/assets/1ce8fc19-869b-445a-8221-5b355019664f)

![image](https://github.com/user-attachments/assets/51f0bcd7-5643-402e-b7c5-ca8886c02e06)

![image](https://github.com/user-attachments/assets/c44fa186-9417-4c06-95c0-bff27dd83c61)

Licence
This project is licensed under the MIT License. See the LICENSE file for details.
