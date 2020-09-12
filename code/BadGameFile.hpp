//
// Created by:  Ehiremen Ekore on 10/20/2019.
// Modified by: Ehiremen Ekore on 12/11/2019.
// File name:   BadGameFile.hpp
//

#pragma once

#include "tools.hpp"

class BadGameFile{
public:
    string fileName;
    BadGameFile(string s) : fileName(s){}
    virtual ~BadGameFile() = default;
    
    //-------------file not opened
    virtual void print(){
        pr();
        cerr << "\t\tThe file could not be opened" << endl << "\t\tPlease retry";
        br();
    }
    
    void pr(){
        br();
        cerr << "\tError with " << fileName << ":" << endl;
    }
    void br(){
        cerr << endl << setw(60) << setfill('=') << " " << endl;
    }
};

class BadGameType: public BadGameFile{
public:
    char gameType;
    BadGameType(string s, char t): gameType(t), BadGameFile(s){}
    
    //-------------file opened, but bad type
    virtual void print(){
        pr();
        
        cerr << "\t\tGame type: " << gameType << endl
        << "\t\tValid game types are: t, s, d" << endl
        << "\t\tPlease fix this (in file) and retry";
        
        br();
    }
};

class BadFileLength: public BadGameFile{
public:
    BadFileLength(string s): BadGameFile(s){}
    
    //-------------file had more/less than required data
    virtual void print(){
        pr();
        cerr << "\t\tIssue: Problem with file size" << endl << "\t\tPlease retry";
        br();
    }
};

class BadGameData: public BadGameFile{
public:
    BadGameData(string s) : BadGameFile(s){}
    
    virtual void print(){
        pr();
        cerr << "\t\tIssue: Corrupt data in file." << endl << "\t\tPlease retry";
        br();
    }
};

class BadRedoType: public BadGameFile{
public:
    char gameType;
    int typeInFile;
    
    BadRedoType(string s, char t, int typeInFile):
        typeInFile(typeInFile), gameType(t), BadGameFile(s){}
    
    //-------------file opened, but bad type
    virtual void print(){
        pr();
        
        cerr << "\t\tGame type: " << gameType << endl
             << "\t\tGiven size in file: " << typeInFile << endl
             << "\t\tRestore unsuccessful";
        
        br();
    }
};
