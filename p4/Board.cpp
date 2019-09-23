//
// Created by: Ehiremen Ekore on 9/20/2019.
// File name:  Board.cpp
//

#include "Board.hpp"

//Pre:  Pointer to array of Squares (bd) not pointing at an array
//Post: bd now points to an array of n*n Squares, and getPuzzle is called to
//      initialize each of these squares
Board:: Board(int n, ifstream& puzFile) : sizeOfPuzzle(n), puzzleData(puzFile){
    bd = new Square[n * n];
    getPuzzle();
    cerr  << endl << "created " << n << " by " << n << " board" << endl << endl;
}

//Pre:      There's n^2 Squares on the Board, but not yet initialized any
//Post:     All squares on the Board have been initialized with a char
//Error:    "File too short" if there's not enough data to initialize all squares
//          "Unused data in file" if file has more data than required for n^2 squares
void Board:: getPuzzle(){
    flush(puzzleData);
    char ch;
    for (int line=1; line<=sizeOfPuzzle; line++){
        for(int col=1; col<=sizeOfPuzzle; col++){
            puzzleData >> ch;
            /*reading into ch before checking if at EOF.
             *the idea is that .eof() checks if there's anything AFTER the current
              item in the stream. calling .eof() before reading in a char wouldn't
              catch on if there's only ONE missing char.
            */
            if(puzzleData.eof()){
                fatal("File too short");
            }
            else{
                sub(line, col) = move(Square(ch, line, col));
            }
        }
    }
    if(puzzleData.get() != EOF){
        fatal("Unused data in file");
    }
}

Square& Board:: sub(int j, int k){
    int indexInArray = (9*(j-1)) + (k-1);
    return bd[indexInArray];
}

ostream& Board::print(ostream &out) {
    int numLines = sizeOfPuzzle * sizeOfPuzzle;
    for(int k=0; k<numLines; k++){
        out << bd[k];
        if ((k>0) && (k%sizeOfPuzzle == (sizeOfPuzzle-1))){
            out << endl;
        }
    }

    return out;
}

