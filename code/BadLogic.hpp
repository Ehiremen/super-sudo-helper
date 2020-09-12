//
// Created by:  Ehiremen Ekore on 10/20/2019.
// Modified by: Ehiremen Ekore on 12/11/2019.
// File name:   BadLogic.hpp
//

#pragma once

#include "tools.hpp"

class BadLogic{
public:
    int row, col, boardLen;
    char value;
    short posList;

    BadLogic(int bLen, int r=0, int c=0, char v='-', short pos=0x0):
            boardLen(bLen), row(r), col(c), value(v), posList(pos){}
    virtual ~BadLogic() = default;
    virtual void print(){
        pr();
    }
    
    void pr(){
        br();
        cerr << "\tError! Tried marking: ";
    }
    
    void br(){
        cerr << endl << setw(60) << setfill('=') << " " << endl;
    }
    
    void printPos(){
        cerr << "\t\t";
        
        for (int k=boardLen; k>0; k--){
            bool possibleVal = (posList >> k) & 1;
            if(possibleVal){ cerr << right << "" << k << "  ";}
            else{ cerr << right << "" << '-' << "  ";}
        }
        cerr << endl;
    }
};

class BadPos: public BadLogic{
public:
    BadPos(char val, short pos, int bLen): BadLogic(bLen, 0, 0, val, pos){}

    virtual void print(){
        pr();
        cerr << value << endl;
        cerr << "\t\tValid possibilities are:" << endl;
        printPos();
        br();
    }
};

class BadSquare: public BadLogic{
public:
    BadSquare(int r, int c, int bLen): BadLogic(bLen, r, c){}

    virtual void print(){
        pr();
        cerr << " [" << row << ", " << col << "]" << endl;
        cerr << "\t\tValid squares are [1..." << boardLen << ", 1...";
        cerr << boardLen << "]" << endl;
        br();
    }
};

class BadSquareInit: public BadLogic{
public:
    BadSquareInit(int r, int c, int bLen): BadLogic(bLen, r, c){}

    virtual void print(){
        pr();
        cerr << " [" << row << ", " << col << "]" << endl;
        cerr << "\t\tSquare not properly initialized" << endl;
        br();
    }
};

class SquareMarked: public BadLogic{
public:
    SquareMarked(int r, int c, int bLen): BadLogic(bLen, r, c){}

    virtual void print(){
        pr();
        cerr << " [" << row << ", " << col << "]" << endl;
        cerr << "\t\tSquare already marked" << endl;
        br();
    }
};

class BadUndoMove: public BadLogic{
public:
    int stackLen;
    string stackType = "undo";
    BadUndoMove(int n) : stackLen(n), BadLogic(0){}

    virtual void print(){
        br();
        cerr << "\tTried making move: undo" << endl;
        cerr << "\t\t" << stackLen << " frame(s) in undo stack." << endl;
        cerr << "\t\tNeed at least 2 frames in stack to undo moves." << endl;
        br();
    }
};
