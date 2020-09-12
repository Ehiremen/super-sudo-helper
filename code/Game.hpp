//
// Created by:  Ehiremen Ekore on 9/11/2019.
// Modified by: Ehiremen Ekore on 11/08/2019.
// File name:   Game.hpp
//

#pragma once

#include "Board.hpp"
#include "BoardDiag.hpp"
#include "BoardTrad.hpp"
#include "BoardSixy.hpp"
#include "Viewer.hpp"

const int TRADITIONAL_GAME_SIZE = 9;
const int SIXY_GAME_SIZE = 6;
const int NUM_DIAG_CLUSTERS = 29;
const int NUM_SIXY_CLUSTERS = 24;

class Game{
private:
    const string ValidGameTypes = "tds";
    const char* MenuOptions = "mtursepq";   //corresponds to the 1st letter of each
                                            //menu item (2nd letter if 1st letter already in use)
    
    const char* menu[8] = {"Mark Square", "Turn off", "Undo Move",
                           "Redo Move", "Save Game",
                           "Restore Game", "Print board", "Quit Game"};
    int gameSize;
    Board* GameBd;
    char gameType;
    string iFileName;
    ifstream inputFileContent;
    Stack undoStack, redoStack;

    void catchInvalidInput(string rowLine);
    void undo();
    void redo();
    void mark();
    void save();
    void restore();
    string getFileName();
    void showBoard();
    bool validateFile(const string& puzFile, int boardSize);
    bool validateRestoreFile(const string& redoFile);

public:
    Game(const string& inputFileName);
    ~Game() { undoStack.zap(); redoStack.zap(); delete GameBd; }
    void run();
    ostream& print(ostream& out);
};

inline ostream& operator << (ostream & out, Game& gm){
    return gm.print(out);
}
