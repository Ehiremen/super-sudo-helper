//
// Created by:  Ehiremen Ekore on 11/21/2019.
// File name:   BoardTrad.hpp
//

#pragma once

#include "Board.hpp"

class TradBoard: public Board{
protected:
    Cluster* createBox(short j, short k);
    void makeBoxClusters();
    
public:
    TradBoard(int numRows, ifstream& puzFile, int nClusters = 27);
    ~TradBoard() {}
};
