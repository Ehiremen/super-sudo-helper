//
// Created by:  Ehiremen Ekore on 9/20/2019.
// Modified by: Ehiremen Ekore on 11/21/2019.
// File name:   Board.hpp
//

#pragma once

#include "Square.hpp"
#include "CanView.hpp"
#include "Frame.hpp"
#include "Stack.hpp"

class Cluster;
class Board : public CanView, public HelperBoard{
private:
    ifstream& puzzleData;

    Square* bd;
    void getPuzzle();
    void makeClusters();
    Cluster* createRow(short j);
    Cluster* createColumn(short k);

protected:
    short sizeOfPuzzle;
    int numClusters;
    vector<Cluster*>bdCluster;
    Square** clusterSqPtr;

public:
    Board(int numRows, ifstream& puzFile, int nClusters = 27);
    ~Board();

    Square& sub(int j, int k) const;
    bool validSquare(int row, int col);
    short initMark();
    void mark();
    void turnOff();
    ostream& print(ostream& out);

    char getMarkChar(int row, int col) const { return sub(row, col).getValue();}
    string getPossibilityString(int row, int col) const;
    Frame* createFrame();
    void restoreState (Frame* fr);
};

// overloading << so I can do things like "cout << someBoard
inline ostream& operator << (ostream & out, Board& b){
    return b.print(out);
}
