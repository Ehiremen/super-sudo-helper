//
// Created by: Ehiremen Ekore on 11/1/2019.
// File name:  BoardDiag.hpp
//

#include "BoardTrad.hpp"
#pragma once

class DiagBoard : public TradBoard{
private:
    void addDiagClusters();
    Cluster* createDiag(int r, int c);

public:
    DiagBoard(int numRows, ifstream& puzFile, int nClusters);
    ~DiagBoard() {}
};
