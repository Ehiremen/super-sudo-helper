//
// Created by: Ehiremen Ekore on 11/08/2019.
// File name:  Stack.hpp
//

#pragma once

#include "Frame.hpp"

using namespace std;

class Stack: private vector<Frame>{
public:
    Stack(){ reserve(20); cerr << "Created stack" << endl;}
    ~Stack(){ cerr << "Deleting stack" << endl;}

    void pop() { pop_back();}
    Frame* top() { return &back();}
    void push (Frame* f) { push_back(*f);}
    int size() { return vector<Frame>::size();}
    void zap() { for(Frame f: *this) pop();}
};
