//
// Created by: Ehiremen Ekore on 9/11/2019.
// Modified by: Ehiremen Ekore on 9/20/2019.
// File name:  Game.hpp
//

/*
 * CHANGES FROM P4:
 *      1. Changed "#define"s to "const int"s
 *      2. Modified Game::run() to call Board::mark() when appropriate
 */

#pragma once

#include "Board.hpp"

const int TRADITIONAL_GAME_SIZE = 9;
const int SIXY_GAME_SIZE = 6;

class Game{
private:
    const string ValidGameTypes = "tds";
    const char* MenuOptions = "murseq"; //corresponds to the 1st letter of each
                            //menu item (2nd letter if 1st letter already in use)
    const char* menu[6] = {"Mark Square", "Undo Move (not implemented)",
                           "Redo Move (not implemented)", "Save Game (not implemented)",
                           "Restore Game (not implemented)", "Quit Game"};
    Board* GameBd;
    int gameSize;
    char gameType;
    ifstream inputFileContent;

public:
    Game(const string& inputFileName);
    ~Game() { delete GameBd;}
    void run();
    Board* getBoard(){ return GameBd;}
    ostream& print(ostream& out);
};
inline ostream& operator << (ostream & out, Game& gm){
    return gm.print(out);
}