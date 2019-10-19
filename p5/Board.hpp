//
// Created by:  Ehiremen Ekore on 9/20/2019.
// Modified by: Ehiremen Ekore on 9/27/2019.
// File name:   Board.hpp
//

/*
 * CHANGES FROM P4:
 *      1. Added a forward declaration of Class Cluster
 *      2. Added bdCluster: a private vector of Cluster*
 *      3. Added the following private helper functions for cluster generation:
            makeClusters(), createRow(), createColumn(), createBox;
 *      4. Added clusterSqPtr: a private Square** to store pointers to all Squares
            in a Cluster while the Cluster is being made
 *      5. Modified ~Board() to also delete clusterSqPtr and Cluster* in bdCluster
 *      6. Added mark(): a public function to allow a user mark a Square
 */

#pragma once

#include "Square.hpp"
//enum ClusterT {row, column, box};

class Cluster;
class Board{
private:
    short sizeOfPuzzle;
    ifstream& puzzleData;
    short left;
    void getPuzzle();
    Square* bd;
    vector<Cluster*>bdCluster;

    void makeClusters();
    Cluster* createRow(short j);
    Cluster* createColumn(short k);
    Cluster* createBox(short j, short k);
    Square** clusterSqPtr;

public:
    static const char* clusterStrings[3];
    Board(int n, ifstream& puzFile);
    ~Board();
    Square& sub(int j, int k);
    ostream& print(ostream& out);
    void mark();
};
inline ostream& operator << (ostream & out, Board& b){
    return b.print(out);
}