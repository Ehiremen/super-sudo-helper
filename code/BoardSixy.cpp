//
// Created by:  Ehiremen Ekore on 11/21/2019.
// File name:   BoardSixy.cpp
//

#include "BoardSixy.hpp"
#include "Cluster.hpp"

SixyBoard:: SixyBoard(int numRows, ifstream& puzFile, int nClusters):
                Board(numRows, puzFile, nClusters){
    makeBoxClusters();
}
//------------------------------------------------------------------------------

Cluster* SixyBoard:: createHBox(short j, short k){
    clusterSqPtr = new Square*[sizeOfPuzzle];
    int index=0;
    short indexLimit = sizeOfPuzzle/2;
    
    for(short m=0; m<indexLimit; m++){
        for(short n=0; n<indexLimit-1; n++){
            clusterSqPtr[index] = &sub(j+m, k+n);
            index++;
        }
    }
    
    Cluster* cluster = new Cluster(hbox, clusterSqPtr, sizeOfPuzzle);
    
    for(int n=0; n<sizeOfPuzzle; n++){
        clusterSqPtr[n]->addCluster(cluster);
        cluster->shoop(clusterSqPtr[n]->getValue());
    }
    return cluster;
}
//------------------------------------------------------------------------------

Cluster* SixyBoard:: createVBox(short j, short k){
    clusterSqPtr = new Square*[sizeOfPuzzle];
    int index=0;
    short indexLimit = sizeOfPuzzle/3;
    for(short m=0; m<indexLimit; m++){
        for(short n=0; n<indexLimit+1; n++){
            clusterSqPtr[index] = &sub(j+m, k+n);
            index++;
        }
    }
    Cluster* cluster = new Cluster(vbox, clusterSqPtr, sizeOfPuzzle);
    for(int n=0; n<sizeOfPuzzle; n++){
        clusterSqPtr[n]->addCluster(cluster);
        cluster->shoop(clusterSqPtr[n]->getValue());
    }
    return cluster;
}
//------------------------------------------------------------------------------

void SixyBoard:: makeBoxClusters(){
    //make h-boxes
    for(short j=1; j<=sizeOfPuzzle; j+=3){
        for(short k=1; k<=sizeOfPuzzle; k+=2){
            bdCluster.push_back(createHBox(j, k));
        }
    }

    //make v-boxes
    for(short j=1; j<=sizeOfPuzzle; j+=2){
        for(short k=1; k<=sizeOfPuzzle; k+=3){
            bdCluster.push_back(createVBox(j, k));
        }
    }
}
