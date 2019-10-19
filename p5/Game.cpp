//
// Created by: Ehiremen Ekore on 9/11/2019.
// Modified by: Ehiremen Ekore on 9/20/2019.
// File name:  Game.cpp
//

#include "Game.hpp"

/*
    Pre:    Currently have only inputFileName (should be a text file!)
    Post:   A new Game item initialized with its gameType coming from the
            file at inputFileName and its n^2 board initialized by Board class
    Errors: Invalid filename; Invalid gameType
 */
Game::Game(const string& inputFileName){
    inputFileContent.open(inputFileName);
    if (!inputFileContent){ fatal("Unable to open file");}
    inputFileContent >> gameType;
    gameType = tolower(gameType);

    size_t valid = ValidGameTypes.find(gameType);
    //only update gameType if type in line 1 of file is valid
    if (valid==string::npos){ fatal("Invalid game-type");}

    gameSize = (gameType == 's') ? SIXY_GAME_SIZE : TRADITIONAL_GAME_SIZE;
    GameBd = new Board(gameSize, inputFileContent);
    inputFileContent.close();
}
//------------------------------------------------------------------------------

/*
    Pre:    A Game exists and has been initialized with a text file
    Post:   A Game has gone on until the user chose to Quit the game
    Error:  No error handling occurs directly here, menu_c handles that for now
            (in terms of invalid option chosen)
*/
void Game::run(){
    char menuChoice;
    while (menuChoice != 'q') {
        menuChoice = menu_c("Super-Sudo-Helper", 6, menu, MenuOptions);
        switch (menuChoice) {
            case 'm': GameBd->mark(); break;
            case 'u': break;
            case 'r': break;
            case 's': break;
            case 'q': cout << "Quitting game..." << endl; break;
        }
    }
}
//------------------------------------------------------------------------------

ostream& Game:: print(ostream& out){
    out << *GameBd;
    return out;
}