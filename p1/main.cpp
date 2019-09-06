//
// Created by ehise on 8/30/2019.
//
#include "State.hpp"

void unitTest(){
    cout << "State initialized with '-'" << endl;
    State st1('-');
    cout << st1;
    st1.mark('2');
    st1.mark('8');
    st1.mark('8');
    cout << endl << "CHECKING FINAL VALUE" << endl;
    cout << st1;

    cout << "********************************************" << endl;
    cout << "State initialized with null constructor" << endl;
    State st2;
    cout << st2;
    st2.mark('-');
    st2.mark(' ');
    st2.mark('a');
    st2.mark('0');
    st2.mark('6');
    cout << endl << "CHECKING FINAL VALUE" << endl;
    cout << st2;

    cout << "********************************************" << endl;
    cout << "State initialized with fixed value '3'" << endl;
    State st3('3');
    cout << st3;
    st3.mark('5');
    st3.mark('k');
    cout << endl << "CHECKING FINAL VALUE" << endl;
    cout << st3;

    cout << "********************************************" << endl;
    cout << "State initialized with a invalid value" << endl;
    State st4('k');
    cout << st4;

    cout << "********************************************" << endl;
    cout << "Testing a non-uniform possibility list" << endl;
    State st5;
    st5.setSpecialPossibilities(0x23e);
    cout << st5;
    st5.mark('8');
    cout << st5;
    st5.mark('2');
    cout << endl << "CHECKING FINAL VALUE" << endl;
    cout << st5;
}

int main(){
    banner();
    unitTest();

    //the bye() function was distorting my output
    cout << endl << "Normal termination." << endl;
    return 0;
}