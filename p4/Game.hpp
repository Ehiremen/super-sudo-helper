//
// Created by: Ehiremen Ekore on 9/20/2019.
// File name:  Game.hpp
//

#pragma once

#include "State.hpp"
#include "Board.hpp"

#define TRADITIONAL_GAME_SIZE 9;
#define SIXY_GAME_SIZE 6;

//class Board;
class Game{
private:
    const string ValidGameTypes = "tds";
    const char* MenuOptions = "murseq"; //corresponds to the 1st letter of each
                            //menu item (2nd letter if 1st letter already in use)
    const char* menu[6] = {"Mark Square", "Undo Move", "Redo Move",
                           "Save Game", "Restore Game", "Quit Game"};
    Board* GameBd;
    int gameSize;
    char gameType;
    ifstream inputFileContent;

public:
    Game(const string& inputFileName);
    ~Game() {
        delete GameBd;
    }
    void run();
    Board* getBoard(){
        return GameBd;
    }
    ostream& print(ostream& out);
};
inline ostream& operator << (ostream & out, Game& gm){
    return gm.print(out);
}