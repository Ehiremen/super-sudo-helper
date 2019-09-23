//
// Created by: Ehiremen Ekore on 9/11/2019.
// File name:  Game.cpp
//

#include "Game.hpp"

/*
    Pre:    Currently have only inputFileName (should be a text file!)
    Post:   A new Game item initialized with its gameType coming from the
            file at inputFileName
    Errors: Invalid filename; Invalid gameType
 */
Game::Game(const string& inputFileName){
    inputFileContent.open(inputFileName);
    if (inputFileContent){ //checks if the file was opened
        char tempType;

        //keep reading one char at a time till we find the first non-whitespace
        while((inputFileContent >> tempType) && (tempType != '\n')){
            if(!isspace(tempType)) {
                tempType = tolower(tempType);
                break;
            }
        }

        size_t valid = ValidGameTypes.find(tempType);

        //only update gameType if type in line 1 of file is valid
        if (valid!=string::npos){
            gameType = tempType;
            switch (gameType){
                case 't': gameSize = 9; break;
                case 's': gameSize = 6; break;
                case 'd': gameSize = 9; break;
                //not sure what size 'd' should be right now
            }
        }
        else{
            fatal("Invalid game-type");
        }
    }
    else {
        fatal("Unable to open file");
    }
}

/*
    Pre:    A Game exists and has been initialized with a text file
    Post:   A Game has gone on until the user chooses to Quit the game
    Error:  No error handling occurs directly here, menu_c handles that for now
            (in terms of invalid option chosen)
*/
void Game::run(){
    char menuChoice;
    while (menuChoice != 'q') {
        menuChoice = menu_c("Super-Sudo-Helper", 6, menu, MenuOptions);
        switch (menuChoice) {
            case 'm':
                break;
            case 'u':
                break;
            case 'r':
                break;
            case 's':
                break;
            case 'q':
                cout << "Quitting game...";
                break;
        }
    }
}