//
// Created by: Ehiremen Ekore on 9/27/2019.
// File name:  Cluster.cpp
//

#include "Cluster.hpp"

const char* Cluster:: clusterStrings[] = {"row", "column", "box"};

Cluster::Cluster(ClusterT cType, Square* sqPtr[9]){
    clusterName = clusterStrings[cType];
    for(int k=0; k<9; k++){
        squarePtr[k] = sqPtr[k];
    }
    cerr << "New " << clusterName << " cluster created" << endl;
}
//------------------------------------------------------------------------------

ostream& Cluster:: print(ostream& out){
    out << clusterName << endl;
    for(int k=0; k<9; k++){
        out << *squarePtr[k];
    }
}
//------------------------------------------------------------------------------

void Cluster:: shoop(char val){
    if(val!='-') {
        int valueInt = val - '0';
        for (auto &sq: squarePtr) {
            sq->turnOff(valueInt);
        }
    }
}