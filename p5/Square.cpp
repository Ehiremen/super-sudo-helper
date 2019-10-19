//
// Created by: Ehiremen Ekore on 9/27/2019.
// File name:  Square.cpp
//

#include "Square.hpp"
#include "Cluster.hpp"
//------------------------------------------------------------------------------

Square::Square(char ch, short row, short col) : st(ch){
    if ((1 <= row) && (row <= 9) && (1 <= col) && (col <= 9)) {
        //first check that row and col are valid numbers
        if (st.getValue() == BAD_VALUE){
            //also, was State successfully initialized?
            cerr << "Square not properly initialized" << endl;
        }
        else {
            rowNumber = row;
            columnNumber = col;
            cerr << "Square " << row << ", " << col << " constructed." << endl;
        }
    }
    else {
        st = State(BAD_VALUE);
        //set the state to a bad state so we know the square is invalid
        cerr << "Square not properly initialized" << endl;
    }
}
//------------------------------------------------------------------------------

Square:: ~Square() {
    cerr <<"Deleting square " << rowNumber << ", " << columnNumber << endl;
}
//------------------------------------------------------------------------------

ostream& Square:: print(ostream& out){
    out << "Square [" << rowNumber << ", " << columnNumber << "] " << st;
    return out;
}
//------------------------------------------------------------------------------

//Pre:  val is marked in Square A, but might still seen as a valid possibility
//      in the poslist of another Square B in the same cluster as Square A
//Post: val has been removed from all Clusters of Square A
void Square:: shoop(char val){
    for(auto &cluster: myClusters){ cluster->shoop(val);}
}