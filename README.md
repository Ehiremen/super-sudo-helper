# super-sudo-helper
A C++ project that helps (not solves!) when solving Sudoku puzzles.

This is me showing you the product of my Object Oriented Programming Practices class. 

This project was built in 11 modules over the course of three months, with each module being an improvement on a previous module. However, only the final product is uploaded here.

The end goal is to have something that one can use to organize their life when solving a sudoku puzzle (less mental work, and no more having to physically erase your previous solutions, YAY!)

This is/was an in-class project, and some code stubs and files (tools.cpp, tools.hpp) were supplied by my professor (Alice E. Fischer).

- - - - 

## Project Structure
While this project uses an mvc design pattern, I moved all the code to one folder to simplify compiling for users who may have trouble compiling between directories.

### Model Files:
- ***Parent Board Class***
    - [Board.cpp](code/Board.cpp)
    - [Board.hpp](code/Board.hpp)

    ***Children Board Classes***
    - ***9x9 Diagonal Board***
        - [BoardDiag.cpp](code/BoardDiag.cpp)
        - [BoardDiag.hpp](code/BoardDiag.hpp)
    - ***6x6 "Sixy" Board***
        - [BoardSixy.cpp](code/BoardSixy.cpp)
        - [BoardSixy.hpp](code/BoardSixy.hpp)
    - ***9x9 Traditional Board***
        - [BoardTrad.cpp](code/Board.cpp)
        - [BoardTrad.hpp](code/Board.hpp)

- [Cluster.cpp](code/Cluster.cpp)
- [Cluster.hpp](code/Cluster.hpp)
- [Frame.hpp](code/Frame.hpp)
- [Square.cpp](code/Square.cpp)
- [Square.hpp](code/Square.hpp)
- [Stack.cpp](code/Stack.cpp)
- [Stack.hpp](code/Stack.hpp)
- [State.cpp](code/State.cpp)
- [State.hpp](code/State.hpp)


### View Files:
- [Canvas.cpp](code/Canvas.cpp)
- [Canvas.hpp](code/Canvas.hpp)
- [CanView.hpp](code/CanView.hpp)
- [GridChar.cpp](code/GridChar.cpp)
- [GridChar.hpp](code/GridChar.hpp)
- [MixedChar.cpp](code/MixedChar.cpp)
- [MixedChar.hpp](code/MixedChar.hpp)
- [Viewer.cpp](code/Viewer.cpp)
- [Viewer.hpp](code/Viewer.hpp)


### Controller Files:
- [Game.cpp](code/Game.cpp)
- [Game.hpp](code/Game.hpp)
- [Main.cpp](code/Main.cpp)

### Utility Files
- [tools.cpp](code/tools.cpp)
- [tools.hpp](code/tools.hpp)

### Error Handling Files:
- [BadGameFile.hpp](code/BadGameFile.hpp)
- [BadLogic.hpp](code/BadLogic.hpp)

### Sample Input Files:
- [puz1.txt](puzzles/puz1.txt) (9x9 standard puzzle)
- [puzd.txt](puzzles/puzd.txt) (9x9 diagonal puzzle)
- [puzs1.txt](puzzles/puzs1.txt) (6x6 sixy puzzle)
- [puzs2.txt](puzzles/puzs2.txt) (6x6 sixy puzzle)

- - - - 

**NOTE:**
If you get a "Corrupt file" message when you try the input files linked above, edit them, take out each newline and put it in again.
The issue has to do with Windows' CR.

*Thank you*
