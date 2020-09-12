//
// Created by: Ehiremen Ekore on 9/27/2019.
// File name:  Cluster.hpp
//

#pragma once

#include "Square.hpp"

enum ClusterT {row, column, box, diag, hbox, vbox};

class Cluster{
private:
    const char* clusterName;
    Square* squarePtr[9];
    int bdLen;

public:
    static const char* clusterStrings[6];
    Cluster(ClusterT cType, Square** sqPtr, int length);
    ~Cluster(){ cerr << "Deleting " << clusterName << " cluster" << endl; }
    Cluster(Cluster&) = default;
    ostream& print(ostream& out);
    void shoop(char val);
};

inline ostream& operator << (ostream & out, Cluster& cl){ return cl.print(out); }
