//
// Created by: Ehiremen Ekore on 11/08/2019.
// Modified by: Ehiremen Ekore on 11/15/2019.
// File name:  Frame.hpp
//

#pragma once
#include "State.hpp"

class Frame: public FrameHelper {
private:
    vector<State> frameVec;
    int len;

public:
    Frame(int nSquared) :len(nSquared) {
        frameVec.resize(nSquared);
        cerr << "Created frame of size " << nSquared << endl;}
    ~Frame() { cerr << "Deleting frame" << endl;}

    // copy State s into slot k in frameVec
    void copyState(const State& s, int k){
        frameVec[k] = s;
    }

    void serialize( ofstream& gameOut){
        gameOut << frameVec[0].getNumPos() << endl;
        for (const State& st: frameVec){
            gameOut << st.getValue() << " " << st.getPos() << endl;
        }
        cerr << "Frame serialized" << endl;
    }
    
    Frame* realize( ifstream& gameIn){
        int posLen;
        gameIn >> posLen;
        for (int k=0; k<frameVec.size(); k++){
            char val;
            short pos;
            gameIn >> val >> pos;
            helpRealize(frameVec[k], val, pos, posLen);
        }
        return this;
    }

    int getSize() { return frameVec.size();}
    State getState(int n) { return frameVec[n];}
};
