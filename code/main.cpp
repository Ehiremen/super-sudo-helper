//
// Created by:  Ehiremen Ekore on 9/02/2019.
// Modified by: Ehiremen Ekore on 11/11/2019.
// File name:   main.cpp
//

#include "Game.hpp"

//  Post: creates a line of '*'s
void newTestBreak(){
    cout << endl << setw(60) << setfill('*') << " " << endl;
}
//------------------------------------------------------------------------------

/*
 * Pre: No idea if currently running on Windows or not, thus no idea if Viewer
        displays board properly.
 * Post: Runs the "chcp 65001" command if on Windows OS so the Viewer class can
        display properly
 */
void setupWindowsEnv(){
    try{ if(getenv("windir") != NULL) system("chcp 65001");}
    catch(...) {cerr << "Can't apply Windows OS fix for non-Windows OS" << endl;}
}
//------------------------------------------------------------------------------

string getFileName();
void unitTestGame();
//------------------------------------------------------------------------------

int main(){
    banner();
    setupWindowsEnv();
    unitTestGame();
    bye();
    return 0;
}
//------------------------------------------------------------------------------

//Post: The filename the user inputs is returned to the caller UNVALIDATED
string getFileName(){
    string inputFileName;
    cout << "Please input the name of your file, including the extension" << endl;
    cout << "If the file is not in the same folder as this program's executable\n"
            "--or if you're not sure--you are free to"
            " use an explicit file name" << endl;

    getline(cin, inputFileName);

    return inputFileName;
}
//------------------------------------------------------------------------------

void unitTestGame(){
    bool success = false;
    while(!success) {
        try {
            string gameFile = getFileName();
            Game gb(gameFile);
            success = true;
            gb.run();
        }
        catch (BadGameFile& badF) { badF.print();}
        catch (BadLogic& badL) {badL.print(); }
        catch (...) {cerr << "Some unchecked exception caught" << endl; }
    }
}
//------------------------------------------------------------------------------
