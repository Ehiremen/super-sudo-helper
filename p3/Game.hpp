//
// Created by: Ehiremen Ekore on 9/11/2019.
// File name:  Game.hpp
//

#pragma once

#include "State.hpp"

class Board;
class Game{
private:
    const string ValidGameTypes = "tds";
    const char* MenuOptions = "murseq"; //corresponds to the 1st letter of each
                            //menu item (2nd letter if 1st letter already in use)
    const char* menu[6] = {"Mark Square", "Undo Move", "Redo Move",
                           "Save Game", "Restore Game", "Quit Game"};
    Board* bd;
    int gameSize;
    char gameType;
    ifstream inputFileContent;

public:
    Game(const string& inputFileName);
    ~Game() = default;
    void run();

};