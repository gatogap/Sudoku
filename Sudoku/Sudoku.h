#pragma once
#include <iostream>
using namespace std;

class Game
{
private:
    string arrayNumbers[8][8];
    string arrayBlanks[8][8];
    string displayedArray[8][8]; 

    int spaceArraysOptions[3];
    int rowChecker = 0;
    int size = 0;

public:

    void setup();

    void sizeDifficulty();

    void spaceDifficulty();
    
    void displayAssignment();

    void blankAssignment(int difficulty);

    void numberInitializer();

    void blankInitializer();

    void horizontalAssignment(int row); 

    void verticalChecker();

    int LeftA();

    int LeftB();

    int RightA();

    int RightB();

    int DownA();

    int DownB();

    int UpA();

    int UpB();

    void gameplay();

    bool inputChecker();

    void gridDisplay();
    
    void ending(int seconds);
    
};

