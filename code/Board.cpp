//
// Created by: Ehiremen Ekore on 9/20/2019.
// Modified by: Ehiremen Ekore on 12/11/2019.
// File name:  Board.cpp
//

#include "Board.hpp"
#include "Cluster.hpp"

//Pre:  Pointer to array of Squares (bd) not pointing at an array
//Post: bd now points to an array of numRows*numRows Squares, and getPuzzle is called to
//      initialize each of these squares

Board:: Board(int numRows, ifstream& puzFile, int nClusters) :
 CanView(), sizeOfPuzzle(numRows), puzzleData(puzFile), numClusters(nClusters){
     
    bd = new Square[numRows * numRows];
    getPuzzle();
    bdCluster.reserve(nClusters);   //since we already know how many clusters to make
    makeClusters();
    cerr << endl << "created " << numRows << " by " << numRows << " board" << endl << endl;
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
            sub(line, col) = Square(ch, line, col, sizeOfPuzzle);
        }
    }
}
//------------------------------------------------------------------------------

Square& Board:: sub(int j, int k) const{
    int indexInArray = (sizeOfPuzzle*(j-1)) + (k-1);
    return bd[indexInArray];
}
//------------------------------------------------------------------------------

void Board:: mark(){
    short row, col, tempRowCol;
    char value;

    tempRowCol = initMark();
    col = tempRowCol % 10;
    row = tempRowCol / 10;
    cout << "Input value to mark: ";
    cin >> value;
    sub(row, col).mark(value);
    sub(row, col).shoop(value);
}
//------------------------------------------------------------------------------

bool Board::validSquare(int row, int col){
    if (row>0 && row<=sizeOfPuzzle){
        if(col>0 && col<=sizeOfPuzzle) { return true;}
    }
    return false;
}
//------------------------------------------------------------------------------

ostream& Board::print(ostream &out) {
    out << setw(80) << setfill('*') << " " << endl;
    for( Cluster* cl: bdCluster){ out << *cl << endl; }
    out  << setw(80) << setfill('*') << " " << endl;
    return out;
}
//------------------------------------------------------------------------------

//create row and col clusters
void Board:: makeClusters(){
    cerr << endl;
    for(short j=1; j<=sizeOfPuzzle; j++){
        bdCluster.push_back(createRow(j));
    }
    for(short k=1; k<=sizeOfPuzzle; k++){
        bdCluster.push_back(createColumn(k));
    }
}
//------------------------------------------------------------------------------

Cluster* Board:: createRow(short j){
    clusterSqPtr = new Square*[sizeOfPuzzle];
    
    for(short k=1; k<=sizeOfPuzzle; k++){
        clusterSqPtr[k-1] = &sub(j,k);
    }
    
    Cluster* cluster = new Cluster(row, clusterSqPtr, sizeOfPuzzle);
    
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
    
    Cluster* cluster = new Cluster(column, clusterSqPtr, sizeOfPuzzle);
    
    for(int n=0; n<sizeOfPuzzle; n++){
        clusterSqPtr[n]->addCluster(cluster);
        cluster->shoop(clusterSqPtr[n]->getValue());
    }
    
    return cluster;
}
//------------------------------------------------------------------------------

Frame* Board::createFrame(){
    int sizeSquared = sizeOfPuzzle*sizeOfPuzzle;
    Frame* outFrame = new Frame(sizeSquared);

    for (int index = 0; index < sizeSquared; index++){
        outFrame->copyState(bd[index].getState(), index);
    }
    
    for (int k=0; k<sizeSquared; k++){
        outFrame->getState(k);
    }
    
    return outFrame;
}
//------------------------------------------------------------------------------

void Board::restoreState (Frame* fr){
    for(int k=0; k<fr->getSize(); k++){ setState(bd[k], fr->getState(k)); }
}
//------------------------------------------------------------------------------

//Post: A value has been removed from the posList of the Square at [row, col].
//      Nothing happens if the value being turned off is already off.
void Board::turnOff() {
    short row, col, tempRowCol;
    int value;

    try{
        tempRowCol = initMark();
        col = tempRowCol % 10;
        row = tempRowCol / 10;
        cout << "Input value to turn off: ";
        cin >> value;
        sub(row, col).turnOff(value);
    }
    catch (BadLogic &bl) {bl.print();}
}
//------------------------------------------------------------------------------

//Post: returns a 2-digit number ([row][col]) representing the intended row and
//      column to be marked/ turned off
//Error: throws an error if Square[row, col] is already marked or doesn't exist
short Board::initMark() {
    int rowCol;
    short row, col;

    cout << "Input row and column" << endl;
    cin >> row >> col;
    if (validSquare(row, col)) {
        if (sub(row, col).getPos() == 0) throw SquareMarked(row, col, sizeOfPuzzle);
        cout << sub(row, col);
        
        //store row and col as a 2-digit pair
        rowCol = (10*row) + col;
    }
    
    else { throw BadSquare(row, col, sizeOfPuzzle);}

    return rowCol;
}
//------------------------------------------------------------------------------

string Board::getPossibilityString(int row, int col) const {
    string temp = sub(row, col).poslistString();
    
    //cover up impossible values from posList
    if (sizeOfPuzzle != 9) {
        //used a lambda function for practice
        transform(temp.begin(), temp.begin() + 3, temp.begin(),
                [](char c) { return ' '; });
    }
    
    return temp;
}
