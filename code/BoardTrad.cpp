//
// Created by:  Ehiremen Ekore on 11/21/2019.
// File name:    BoardTrad.cpp
//

#include "BoardTrad.hpp"
#include "Cluster.hpp"

TradBoard::TradBoard(int numRows, ifstream& puzFile, int nClusters) :
                Board(numRows, puzFile, nClusters){
    makeBoxClusters();
}
//------------------------------------------------------------------------------

Cluster* TradBoard:: createBox(short j, short k){
    clusterSqPtr = new Square*[sizeOfPuzzle];
    int index=0;
    short indexLimit = sizeOfPuzzle/3;
    
    for(short m=0; m<indexLimit; m++){
        for(short n=0; n<indexLimit; n++){
            clusterSqPtr[index] = &sub(j+m, k+n);
            index++;
        }
    }
    
    Cluster* cluster = new Cluster(box, clusterSqPtr, sizeOfPuzzle);
    
    for(int n=0; n<sizeOfPuzzle; n++){
        clusterSqPtr[n]->addCluster(cluster);
        cluster->shoop(clusterSqPtr[n]->getValue());
    }
    return cluster;
}
//------------------------------------------------------------------------------

void TradBoard:: makeBoxClusters(){
    for(short j=1; j<=sizeOfPuzzle; j+=3){
        for(short k=1; k<=sizeOfPuzzle; k+=3){
            bdCluster.push_back(createBox(j, k));
        }
    }
}
