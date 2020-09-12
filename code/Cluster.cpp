//
// Created by:  Ehiremen Ekore on 9/27/2019.
// Modified by: Ehiremen Ekore on 11/21/2019.
// File name:   Cluster.cpp
//

#include "Cluster.hpp"

const char* Cluster:: clusterStrings[] = {"row", "column", "box", "diag", "hbox", "vbox"};

Cluster::Cluster(ClusterT cType, Square** sqPtr, int length) : bdLen(length){
    clusterName = clusterStrings[cType];
    for(int k=0; k < bdLen; k++){
        squarePtr[k] = sqPtr[k];
    }
    cerr << "New " << clusterName << " cluster created" << endl;
}
//------------------------------------------------------------------------------

ostream& Cluster:: print(ostream& out){
    out << clusterName << endl;
    out << "squares in cluster: " << bdLen << endl;

    for(int k=0; k<bdLen; k++){
        out << *squarePtr[k];
    }

    return out;
}
//------------------------------------------------------------------------------

void Cluster:: shoop(char val){
    if(val != '-') {
        int valueInt = val - '0';
        for (int k=0; k < bdLen; k++){
            squarePtr[k]->turnOff(valueInt);
        }
    }
}