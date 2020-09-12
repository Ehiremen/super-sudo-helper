//
// Created by:  Ehiremen Ekore on 9/11/2019.
// Modified by: Ehiremen Ekore on 11/08/2019.
// File name:   Game.cpp

#include "Game.hpp"

/*
    Pre:    Currently have only inputFileName (should be a text file!)
    Post:   A new Game item initialized with its gameType coming from the
            file at inputFileName and its n^2 board initialized by Board class
    Errors: Invalid filename; Invalid gameType
 */
Game::Game(const string& inputFileName) : iFileName(inputFileName){
    inputFileContent.open(inputFileName);
    
    if (!inputFileContent){ throw BadGameFile(inputFileName); }
    
    inputFileContent >> gameType;
    gameType = tolower(gameType);
    size_t valid = ValidGameTypes.find(gameType);
    
    //only update gameType if type in line 1 of file is valid
    if (valid==string::npos){ throw BadGameType(inputFileName, gameType);}

    gameSize = (gameType == 's') ? SIXY_GAME_SIZE : TRADITIONAL_GAME_SIZE;
    
    if(!validateFile(inputFileName, gameSize)) {
        //let it be known that there's an error with the file length
        inputFileContent.close();
        throw BadFileLength(inputFileName);
    }
    
    else {
        switch (gameType){
            case 't' : GameBd = new TradBoard(gameSize, inputFileContent);
                                break;
            case 'd' : GameBd =  new DiagBoard(gameSize, inputFileContent, NUM_DIAG_CLUSTERS);
                                break;
            case 's' : GameBd = new SixyBoard(gameSize, inputFileContent, NUM_SIXY_CLUSTERS);
            break;
        }
        undoStack.push(GameBd->createFrame());
        showBoard();            //display the board ONCE after creating board
    }
    inputFileContent.close();
}
//------------------------------------------------------------------------------

//  Post:   Control reaches the end of function IF all chars in row are legal
void Game::catchInvalidInput(string rowLine){
    const string legalValues = string(allLegalVal.begin(), allLegalVal.begin() + 1 + gameSize); //   "-123456789";
    
    for (char c : rowLine) {
        size_t valid = legalValues.find(c);
        if (valid == string::npos) {
            throw BadGameData(iFileName);
        }
    }
}
//------------------------------------------------------------------------------

/*
    Pre:    A Game file is specified, and gameType has been deduced from this file
            Want to check for any possible errors with the file
    Post:   returns false if there's an error with file size
*/
bool Game::validateFile(const string& puzFile, int boardSize){
    ifstream temp(puzFile);
    int thisLength = 0, count = 0;
    bool isValid = true;
    string thisRow;
    getline(temp, thisRow);

    while(!temp.eof()){
        getline(temp, thisRow);
        thisRow.erase(remove(thisRow.begin(), thisRow.end(), '\0'), thisRow.end());
        thisRow.erase(remove(thisRow.begin(), thisRow.end(), '\n'), thisRow.end());
        
        // ignore length if thisRow is empty
        if (!thisRow.empty()) {
            thisLength = thisRow.size();
            catchInvalidInput(thisRow);
            thisLength == boardSize ? (count += thisLength) : (isValid = false);
        }
    }
    
    if (count != (boardSize*boardSize)){
        isValid = false;
    }

    return isValid;
}
//------------------------------------------------------------------------------

/*
    Pre:    A Game exists and has been initialized with a text file
    Post:   A Game has gone on until the user chose to Quit the game
*/
void Game::run(){
    char menuChoice;
    while (menuChoice != 'q') {
        menuChoice = menu_c("Super-Sudo-Helper", 8, menu, MenuOptions);
        
        switch (menuChoice) {
            case 'm':   mark(); break;
            case 't':   GameBd->turnOff(); break;
            case 'u':   try{ undo(); break; }
                        catch (BadUndoMove &bum) {bum.print(); break;}
            case 'r':   redo(); break;
            case 's':   save(); break;
            case 'e':   try {restore(); break; }
                        catch (BadGameFile &bad) {bad.print(); break;}
            case 'p':   cout << *GameBd; break;
            case 'q':   cout << "Quitting game..." << endl; break;
        }
        
        if(menuChoice!='q' && menuChoice!='p') showBoard();
    }
}
//------------------------------------------------------------------------------

ostream& Game:: print(ostream& out){
    out << *GameBd;
    return out;
}
//------------------------------------------------------------------------------

void Game::showBoard() {
    cerr << endl;
    Viewer fancyView(gameSize, gameSize, *GameBd);
    fancyView.show(cout);
}
//------------------------------------------------------------------------------

void Game::undo(){
    if(undoStack.size() < 2) throw BadUndoMove(undoStack.size());
    redoStack.push(undoStack.top());
    undoStack.pop();
    GameBd->restoreState(undoStack.top());
}
//------------------------------------------------------------------------------

void Game::redo(){
    if (redoStack.size() != 0){
        undoStack.push(redoStack.top());
        redoStack.pop();
        GameBd->restoreState(undoStack.top());
    }
}
//------------------------------------------------------------------------------

void Game::mark(){
    try{
        GameBd->mark();
        undoStack.push(GameBd->createFrame());
        redoStack.zap();
    }
    catch (BadLogic &bl) { bl.print(); }
}
//------------------------------------------------------------------------------

void Game::save(){
    string outFileName = getFileName();
    ofstream outFile(outFileName);
    undoStack.top()->serialize(outFile);
    outFile.close();
}
//------------------------------------------------------------------------------

void Game::restore() {
    string inFileName = getFileName();

    if(!validateRestoreFile(inFileName)){ throw BadFileLength(inFileName);}
    ifstream inFile(inFileName);
    undoStack.zap();
    redoStack.zap();
    undoStack.push(new Frame(gameSize*gameSize));
    undoStack.top()->realize(inFile);
    undoStack.push(undoStack.top());
    undo();
    inFile.close();
}
//------------------------------------------------------------------------------

string Game::getFileName(){
    string fileName;
    cout << "Please input the name of your save/restore file, including the extension" << endl;
    cin >> flush;
    getline(cin, fileName);
    return fileName;
}
//------------------------------------------------------------------------------

bool Game::validateRestoreFile(const string& redoFile){
    ifstream temp(redoFile);
    if (!temp){ throw BadGameFile(redoFile); }
    
    int count = -1, typeInFile;
    bool isValid = true;
    temp >> typeInFile;
    string val; // char
    short pos;
    if(typeInFile != gameSize){ throw BadRedoType(redoFile, gameType, typeInFile);}

    while(!temp.eof()){
        temp >> val >> pos;
        catchInvalidInput(val);
        count++;
    }
    
    if (count != (gameSize*gameSize)) isValid = false;
    return isValid;
}
