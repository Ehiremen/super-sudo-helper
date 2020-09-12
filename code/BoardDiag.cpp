//
// Created by: Ehiremen Ekore on 11/1/2019.
// File name:  BoardDiag.cpp
//

#include "BoardDiag.hpp"
#include "Cluster.hpp"

DiagBoard:: DiagBoard(int numRows, ifstream& puzFile, int nClusters) :
        TradBoard(numRows, puzFile, nClusters){ addDiagClusters();}
//------------------------------------------------------------------------------

void DiagBoard:: addDiagClusters() {
    //creates the diagonal cluster from Square (1,1) to (9,9) (top left to bottom right)
    bdCluster.push_back(createDiag(1, 1));
    
    //creates the diagonal cluster from top right to bottom left
    bdCluster.push_back(createDiag(9, 1));
}
//------------------------------------------------------------------------------

/*
 * Create a diagonal cluster
 * Takes in a row value and a column value. These values tell whether the diagonal will be top-left to bottom-right or top-right to bottom-left (using 5,5 will default to the former)
 * Returns a Cluster pointer
 */
Cluster* DiagBoard::createDiag(int r, int c) {
    clusterSqPtr = new Square*[sizeOfPuzzle];
    
    if(r==c){
        //go from (1,1) to (9,9)
        for(short k=1; k<=sizeOfPuzzle; k++){
            clusterSqPtr[k-1] = &sub(k,k);
        }
    }
    
    else{
        //go from (9, 1) to (1,9)
        for(short k=1; k<=sizeOfPuzzle; k++){
            short row = sizeOfPuzzle - k + 1;
            clusterSqPtr[k-1] = &sub(row,k);
        }
    }

    Cluster* cluster = new Cluster(diag, clusterSqPtr, sizeOfPuzzle);
    
    for(int n=0; n<sizeOfPuzzle; n++){
        clusterSqPtr[n]->addCluster(cluster);
        cluster->shoop(clusterSqPtr[n]->getValue());
    }
    return cluster;
}
