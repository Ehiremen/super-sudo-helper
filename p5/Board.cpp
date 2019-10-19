//
// Created by: Ehiremen Ekore on 9/20/2019.
// Modified by: Ehiremen Ekore on 9/27/2019.
// File name:  Board.cpp
//

#include "Board.hpp"
#include "Cluster.hpp"

const char* Board:: clusterStrings[] = {"row", "column", "box"};

//Pre:  Pointer to array of Squares (bd) not pointing at an array
//Post: bd now points to an array of n*n Squares, and getPuzzle is called to
//      initialize each of these squares
Board:: Board(int n, ifstream& puzFile) : sizeOfPuzzle(n), puzzleData(puzFile){
    bd = new Square[n * n];
    getPuzzle();
    makeClusters();
    cerr  << endl << "created " << n << " by " << n << " board" << endl << endl;
}
//------------------------------------------------------------------------------

Board:: ~Board(){
    delete [] clusterSqPtr;
    for(Cluster* cl: bdCluster){
        delete cl;
    }
    cerr << endl;
    delete [] bd;
    cerr << endl << "Deleting board" << endl;
}
//------------------------------------------------------------------------------

//Pre:      There's n^2 Squares on the Board, but not yet initialized any
//Post:     All squares on the Board have been initialized with a char
//Error:    "File too short" if there's not enough data to initialize all squares
//          "Unused data in file" if file has more data than required for n^2 squares
void Board:: getPuzzle(){
    flush(puzzleData);
    char ch;
    for (short line=1; line<=sizeOfPuzzle; line++){
        for(short col=1; col<=sizeOfPuzzle; col++){
            puzzleData >> ch;
            //reading into ch before checking if at EOF.
            if(puzzleData.eof()){ fatal("File too short");}
            //if I get to the end of file before filling ALL squares, BAD
            sub(line, col) = Square(ch, line, col);
        }
    }
    if(puzzleData.get() != EOF){ fatal("Unused data in file");}
}
//------------------------------------------------------------------------------
Square& Board:: sub(int j, int k){
    int indexInArray = (sizeOfPuzzle*(j-1)) + (k-1);
    return bd[indexInArray];
}

void Board:: mark(){
    short row, col;
    char value;
    cout << "Input row and column to mark" << endl;
    cin >> row >> col;
    if((row>0) && (row<10) && (col>0) && (col<10)){
        cout << sub(row, col);
        cout << "Input value to mark: ";
        cin >> value;
        sub(row, col).mark(value);
        sub(row, col).shoop(value);
    }
    else{
        cerr << "Invalid square chosen" << endl;
    }
}
ostream& Board::print(ostream &out) {
    cout << setw(80) << setfill('*') << " " << endl;
    for(Cluster* cl: bdCluster){
        out << *cl << endl;
    }
    cout  << setw(80) << setfill('*') << " " << endl;
    return out;
}
//------------------------------------------------------------------------------
void Board:: makeClusters(){
    cerr << endl;
    for(short j=1; j<=sizeOfPuzzle; j++){
        bdCluster.push_back(createRow(j));
    }
    for(short k=1; k<=sizeOfPuzzle; k++){
        bdCluster.push_back(createColumn(k));
    }
    for(short j=1; j<=sizeOfPuzzle; j+=3){
        for(short k=1; k<=sizeOfPuzzle; k+=3){
            bdCluster.push_back(createBox(j, k));
        }
    }
}
//------------------------------------------------------------------------------
Cluster* Board:: createRow(short j){
    clusterSqPtr = new Square*[sizeOfPuzzle];
    for(short k=1; k<=sizeOfPuzzle; k++){
        clusterSqPtr[k-1] = &sub(j,k);
    }
    Cluster* cluster = new Cluster(row, clusterSqPtr);
    for(int n=0; n<sizeOfPuzzle; n++){
        clusterSqPtr[n]->addCluster(cluster);
        cluster->shoop(clusterSqPtr[n]->getValue());
    }
    return cluster;
}
//------------------------------------------------------------------------------
Cluster* Board:: createColumn(short k){
    clusterSqPtr = new Square*[sizeOfPuzzle];
    for(short j=1; j<=sizeOfPuzzle; j++){
        clusterSqPtr[j-1] = &sub(j,k);
    }
    Cluster* cluster = new Cluster(column, clusterSqPtr);
    for(int n=0; n<sizeOfPuzzle; n++){
        clusterSqPtr[n]->addCluster(cluster);
        cluster->shoop(clusterSqPtr[n]->getValue());
    }
    return cluster;
}
//------------------------------------------------------------------------------
Cluster* Board:: createBox(short j, short k){
    clusterSqPtr = new Square*[sizeOfPuzzle];
    int index=0;
    short indexLimit = sizeOfPuzzle/3;
    for(short m=0; m<indexLimit; m++){
        for(short n=0; n<indexLimit; n++){
            clusterSqPtr[index] = &sub(j+m, k+n);
            index++;
        }
    }
    Cluster* cluster = new Cluster(box, clusterSqPtr);
    for(int n=0; n<sizeOfPuzzle; n++){
        clusterSqPtr[n]->addCluster(cluster);
        cluster->shoop(clusterSqPtr[n]->getValue());
    }
    return cluster;
}