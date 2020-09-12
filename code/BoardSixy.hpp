//
// Created by:  Ehiremen Ekore on 11/21/2019.
// File name:   BoardSixy.hpp
//

#pragma once

#include "Board.hpp"

class Cluster;
class SixyBoard: public Board{
private:
    Cluster* createHBox(short j, short k);
    Cluster* createVBox(short j, short k);
    void makeBoxClusters();
    
public:
    SixyBoard(int numRows, ifstream& puzFile, int nClusters=24);
    ~SixyBoard() {}
};
