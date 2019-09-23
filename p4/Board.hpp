//
// Created by: Ehiremen Ekore on 9/20/2019.
// File name:  Board.hpp
//

#pragma

#include "State.hpp"

class Board{
private:
    int sizeOfPuzzle;
    ifstream& puzzleData;
    short left;
    void getPuzzle();
    Square* bd;

public:
    Board(int n, ifstream& puzFile);
    ~Board(){
        delete [] bd;
        cerr << "Deleting board" << endl;
    }

    //Board& operator=(Board&&) = default;
    Board( Board&&) = default;

    Square& sub(int j, int k);
    ostream& print(ostream& out);

};
inline ostream& operator << (ostream & out, Board& b){
    return b.print(out);
}