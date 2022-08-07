/*IMPLEMENTATION FILE*/

#include "Sudoku.h"

#include <string>
#include <algorithm>
#include <chrono>

/*keyboard interaction*/
#include <conio.h> 
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESCAPE 27
#define KEY_ENTER 13

/*Sleep function library*/
#include <iomanip>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*randomizing library*/
#include <cstdlib>
using namespace std::chrono;



    void Game::setup()
    {
        /*SOMETHING ABOUT THE ORDER PREVENTS IT FROM RUNNING PROPERLY*/
        numberInitializer();
        blankInitializer();
        sizeDifficulty();
        srand(time(NULL));
        horizontalAssignment(0);

        for (int countRow = 1; countRow < size; countRow++)
        {
            horizontalAssignment(countRow); //countRow is the line that will be compared with all the previous lines
            rowChecker = countRow + 1;
            verticalChecker();

            displayAssignment(); //debugger
            gridDisplay();  //debugger
        }

        displayAssignment();
        spaceDifficulty();
        system("CLS");
    }

    void Game::sizeDifficulty()
    {
        int decision = 0;

        cout << "[Choose the size of your grid]" << endl << endl;
        cout << " 1) 4x4" << endl;
        cout << " 2) 6x6" << endl;
        cout << " 3) 8x8" << string(2, '\n');
        cout << " Enter your decision here: ";
        cin >> decision;
        cout << endl;

        switch (decision)
        {
        case 1:
            size = 4;
            spaceArraysOptions[0]= 4;
            spaceArraysOptions[1] = 8;
            spaceArraysOptions[2] = 12;
            spaces = "---------------";
            break;

        case 2:
            size = 6;
            spaceArraysOptions[0] = 6;
            spaceArraysOptions[1] = 18;
            spaceArraysOptions[2] = 30;
            spaces = "-----------------------";
            break;

        case 3:
            size = 8;
            spaceArraysOptions[0] = 8;
            spaceArraysOptions[1] = 36;
            spaceArraysOptions[2] = 49;
            spaces = "-------------------------------";
            break;

        default:
            cout << "~[TRY AGAIN: Choose options 1-3]~" << string(2, '\n');
            Sleep(2050);
            system("CLS");
            sizeDifficulty();
        }  
    }

    void Game::spaceDifficulty()
    {
        cout << "[Choose the number of blank spots you would like to solve on your grid]" << endl << endl;
        int spaces = 0; //user input  

        cout << " 1) " << spaceArraysOptions[0]<< " Blank Slots" << endl;
        cout << " 2) " << spaceArraysOptions[1] << " Blank Slots" << endl;
        cout << " 3) " << spaceArraysOptions[2] << " Blank Slots" << string(2, '\n');
        cout << " Enter your decision here: ";
        cin >> spaces;
        cout << endl;

        switch (spaces)
        {
        case 1:
            blankAssignment(spaceArraysOptions[0]);
            break;

        case 2:
            blankAssignment(spaceArraysOptions[1]);
            break;

        case 3:
            blankAssignment(spaceArraysOptions[2]);
            break;

        default:
            cout << "~[TRY AGAIN: Choose options 1-3]~" << string(2, '\n');
            Sleep(2050);
            system("CLS");
            spaceDifficulty();
        }
    }

    void Game::displayAssignment()
    {

        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                displayedArray[b][a] = arrayNumbers[b][a];
            }
        }
    }

    void Game::blankAssignment(int difficulty)
    {
        int index1 = 0;
        int index2 = 0;
        index1 = rand() % size;
        index2 = rand() % size;
        int count = 0;

        while (count < difficulty)
        {
            index1 = rand() % size;
            index2 = rand() % size;

            while (displayedArray[index1][index2] == " ")
            {
                index1 = rand() % size;
                index2 = rand() % size;
            }

            if (displayedArray[index1][index2] != " ")
            {
                displayedArray[index1][index2] = " ";
                count++;
            }

        }
    }

    void Game::numberInitializer() //very helpful for debugging. Maybe necessary to help initialize though. 
    {
        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                arrayNumbers[b][a] = "0";
            }
        }
    }

    void Game::blankInitializer() //very helpful for debugging. Maybe necessary to help initialize though. 
    {
        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                arrayBlanks[b][a] = " ";
            }
        }
    }

    void Game::horizontalAssignment(int row) //at start, row is zero MAKE HORIZONTAL ARRAY DYNAMIC
    {
        string horizontal[8] = {"1","2","3","4","5","6","7","8"};
        string* ptrHorizontal = new string[size]; //dynamic array

        for (int dynamicIndex = 0; dynamicIndex < size; dynamicIndex++)
        {
            ptrHorizontal[dynamicIndex] = horizontal[dynamicIndex];
            //cout << ptrHorizontal[dynamicIndex];
        }

        /*------START OF ROW HERE-----*/
        int index = 0; //horizontal index
        int a = 0; //column (x-axis

        while (a < size) //column - x axis
        {
            index = rand() % size;

            while (ptrHorizontal[index] == "0")
            {
                index = rand() % size;
            }

            if (ptrHorizontal[index] != "0")
            {
                arrayNumbers[row][a] = ptrHorizontal[index];
                ptrHorizontal[index] = "0";

                a++;
            }
        }
    }

    void Game::verticalChecker()
    {
        for (int column = 0; column < size; column++)
        {
            for (int firstRow = 0; firstRow < rowChecker - 1; firstRow++)
            {
                for (int secondRow = firstRow + 1; secondRow < rowChecker; secondRow++)
                {
                    if (arrayNumbers[firstRow][column] == arrayNumbers[secondRow][column])
                    {
                        horizontalAssignment(secondRow);
                        column = 0;
                        firstRow = 0;
                        secondRow = 1;
                    }
                }
            }
        }
    }

    int Game::LeftA()
    {
        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                if (displayedArray[b][a] == " ")
                {   
                        return a; 
                }
            }
        }
    }

    int Game::LeftB()
    {
        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                if (displayedArray[b][a] == " ")
                {
                        return b;
                }
            }
        }
    }

    int Game::RightA()
    {
        for (int b = size; b >= 0; b--) //row
        {
            for (int a = size; a >=0; a--) //column
            {
                if (displayedArray[b][a] == " ")
                {
                    return a;
                }
            }
        }
    }

    int Game::RightB()
    {
        for (int b = size; b>=0; b--) //row
        {
            for (int a = size; a >=0; a--) //column
            {
                if (displayedArray[b][a] == " ")
                {
                    return b;
                }
            }
        }
    }

    int Game::DownA()
    {
        for (int a = size; a >=0; a--) //column
        {
            for (int b = size; b >= 0; b--) //row
            {
                if (displayedArray[b][a] == " ")
                {
                    return a;
                }
            }
        }
    }

    int Game::DownB()
    {
        for (int a = size; a >= 0; a--) //column
        {
            for (int b = size; b >= 0; b--) //row
            {
                if (displayedArray[b][a] == " ")
                {
                    return b;
                }
            }
        }
    }

    int Game::UpA()
    {
        for (int a = 0; a <size ; a++) //column
        {
            for (int b = 0; b <size ; b++) //row
            {
                if (displayedArray[b][a] == " ")
                {
                    return a;
                }
            }
        }
    }

    int Game::UpB()
    {
        for (int a = 0; a < size; a++) //column
        {
            for (int b = 0; b < size; b++) //row
            {
                if (displayedArray[b][a] == " ")
                {
                    return b;
                }
            }
        }
    }

    void Game::gameplay()
    {

        cout << endl << "    Let's begin your " << size<< "x" <<size<< " grid!" << string(4, '\n');
        
        gridDisplay();
        int firstIndex = 0;
        int secondIndex = 0;
        int initialLeftA = 0;
        int initialLeftB = 0;

        int lastLeftA = LeftA();
        int lastLeftB = LeftB();
        int lastRightA = RightA();
        int lastRightB = RightB();
        int lastDownA = DownA();
        int lastDownB = DownB();
        int lastUpA = UpA();
        int lastUpB = UpB();

        int check = 0;

        if (check < 1)
        {
            for (int b = 0; b < size && check < 1; b++) //row
            {
                for (int a = 0; a < size && check < 1; a++) //column
                {
                    if (displayedArray[b][a] == " ")
                    {
                        system("CLS");
                        cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                        displayedArray[b][a] = "X";
                        gridDisplay();
                        check++;
                        firstIndex = a;
                        secondIndex = b;
                        initialLeftA = a;
                        initialLeftB = b;
                    }
                }
            }
        }

        check = 0;
        char key = _getch();
        int value = key;

        //while entire grid is not complete, run the switch statement
        while (inputChecker() == false) //fix the issue of changing the slots at the very edges at a = 8
        {
            int checker3 = 0;
            switch (_getch())
            {
            case KEY_UP: //prioritize row
                if (check < 1 && checker3<1)
                {
                    int a = firstIndex;
                    int checker2 = 0;

                    for (int b = secondIndex; b <size && check < 1; b--) //row
                    {

                        if (displayedArray[lastUpB][lastUpA] == "X" || displayedArray[initialLeftB][initialLeftA] == "X")
                        {
                            checker3++;
                            firstIndex = a;
                            secondIndex = b;

                            check++;
                        }

                        if (displayedArray[b][firstIndex] == " ")
                        {
                            displayedArray[secondIndex][firstIndex] = " ";
                            system("CLS");
                            cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                            displayedArray[b][firstIndex] = "X";
                            gridDisplay();
                            check++;
                            secondIndex = b;

                        }

                        //make sure the up button could be pressed
                        while (b == 0 && check < 1 && checker2 < 1)
                        {
                            a--;

                            for (int B = size-1; B >= 0 && check < 1; B--) //row
                            {
                                if (displayedArray[B][a] == " ")
                                {
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    system("CLS");
                                    cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                                    displayedArray[B][a] = "X";
                                    gridDisplay();
                                    secondIndex = B;
                                    firstIndex = a;
                                    checker2++;
                                    check++;
                                }
                            }
                        }
                    }
                }

                check = 0;
                break;

            case KEY_DOWN: ////prioritize row
                if (check < 1  && checker3<1)
                {

                    int a = firstIndex;
                    int checker2 = 0;

                    for (int b = secondIndex; b < size && check < 1; b++) //row
                    {
                        
                        if (displayedArray[lastDownB][lastDownA] == "X")
                        {
                            checker3++;
                            firstIndex = a;
                            secondIndex = b;

                            check++;
                        }
                        

                        if (displayedArray[b][firstIndex] == " ")
                        {
                            displayedArray[secondIndex][firstIndex] = " ";
                            system("CLS");
                            cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                            displayedArray[b][firstIndex] = "X";
                            gridDisplay();
                            check++;
                            secondIndex = b;
                        }


                        //make sure the up button could be pressed
                        while (b == size-1 && check < 1 && checker2 < 1)
                        {
                            a++;

                            for (int B = 0; B < size && check < 1; B++) //row
                            {
                                if (displayedArray[B][a] == " ")
                                {
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    system("CLS");
                                    cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                                    displayedArray[B][a] = "X";
                                    gridDisplay();
                                    secondIndex = B;
                                    firstIndex = a;
                                    checker2++;
                                    check++;
                                }
                            }
                        }

                    }
                }

                check = 0;
                break;

            case KEY_LEFT:
                if (check < 1 && checker3<1)
                {
                    int b = secondIndex;
                    int checker2 = 0;
                    

                    for (int a = firstIndex; a <size && check < 1; a--) //row (a used to be a<size)
                    { 

                        if (displayedArray[lastLeftB][lastLeftA] == "X" || displayedArray[initialLeftA][initialLeftB] == "X")
                        {
                            checker3++;
                            firstIndex = a;
                            secondIndex = b;

                            check++;
                        }

                        if (displayedArray[secondIndex][a] == " ")
                        {
                            displayedArray[secondIndex][firstIndex] = " ";
                            system("CLS");
                            cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                            displayedArray[secondIndex][a] = "X";
                            gridDisplay();
                            check++;
                            firstIndex = a;
                        }

                        while (a == 0 && check < 1 && checker2 < 1)
                        {
                            b--;

                            for (int A = size - 1; A >= 0 && check < 1; A--) //row
                            {
                                if (displayedArray[b][A] == " ")
                                {
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    system("CLS");
                                    cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                                    displayedArray[b][A] = "X";
                                    gridDisplay();
                                    secondIndex = b;
                                    firstIndex = A;
                                    checker2++;
                                    check++;
                                }
                            }
                        }

                        
                    }
                }

                check = 0;
                break;

            case KEY_RIGHT:
                if (check < 1 && checker3 < 1)
                {
                    int b = secondIndex;
                    int checker2 = 0;

                    for (int a = firstIndex; a < size && check < 1; a++) //row
                    {

                        if (displayedArray[lastRightB][lastRightA] == "X")
                        {
                            checker3++;
                            firstIndex = a;
                            secondIndex = b;

                            check++;
                        }

                        if (displayedArray[secondIndex][a] == " ")
                        {
                            displayedArray[secondIndex][firstIndex] = " ";
                            system("CLS");
                            cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                            displayedArray[secondIndex][a] = "X";
                            gridDisplay();
                            check++;
                            firstIndex = a;
                        }

                        while (a == size-1 && check <1 && checker2 < 1)
                        {
                            b++;

                            for (int A = 0; A < size && check < 1; A++) //row
                            {
                                if (displayedArray[b][A] == " ")
                                {
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    system("CLS");
                                    cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                                    displayedArray[b][A] = "X";
                                    gridDisplay();
                                    secondIndex = b;
                                    firstIndex = A;
                                    checker2++;
                                    check++;
                                }
                            }
                        }
                    }
                }
                check = 0;
                break;
            

            case KEY_ESCAPE: //change into a different key

                if (check < 1)
                {
                    int x = 0;
                    int y = 0;

                    cout << "Enter the "<<size <<"x"<<size<< "coordinate you would like to work on : " << endl;

                    cout << "Type your x coordinate (domains [1," << size << "]): ";
                    cin >> x;

                    cout << endl << "Type your y coordinate (ranges [1,9]): ";
                    cin >> y;

                    if (displayedArray[y - 1][x - 1] == arrayNumbers[y - 1][x - 1])
                    {
                        cout << "This coordinate doesn't need to be changed! Pick another one: ";
                        Sleep(2000);
                        system("CLS");
                        cout << endl << "    Let's begin your " << size << "x" << size <<" grid!" << string(4, '\n');
                        gridDisplay();
                    }

                    else if (displayedArray[y - 1][x - 1] != arrayNumbers[y - 1][x - 1])
                    {
                        system("CLS");
                        displayedArray[secondIndex][firstIndex] = " ";
                        cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                        displayedArray[y - 1][x - 1] = "X";
                        gridDisplay();
                    }
                    else;
                }
                check = 0;
                break;

            case KEY_ENTER: //change into a different key
                if (check < 1)
                {
                    string userGuess = "0";
                    cout << "Enter your value for the coordinate marked with an 'X': ";
                    cin >> userGuess;


                    for (int b = 0; b < size; b++) //row
                    {
                        for (int a = 0; a < size; a++) //column
                        {
                            if (displayedArray[b][a] == "X")
                            {
                                if (userGuess == arrayNumbers[b][a])
                                {
                                    displayedArray[b][a] = userGuess;
                                    cout << "Your guess is correct!" << endl;
                                    Sleep(2000);
                                }

                                else if (userGuess != arrayNumbers[b][a])
                                {
                                    cout << "Your guess is not correct! Try again" << endl;
                                    Sleep(2000);
                                    displayedArray[b][a] = " ";

                                }

                                else;
                            }
                        }
                    }

                    system("CLS");
                    cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');

                    if (check < 1)
                    {
                        for (int b = 0; b < size && check < 1; b++) //row
                        {
                            for (int a = 0; a < size && check < 1; a++) //column
                            {
                                if (displayedArray[b][a] == " ")
                                {
                                    system("CLS");
                                    cout << endl << "    Let's begin your " << size << "x" << size << " grid!" << string(4, '\n');
                                    displayedArray[b][a] = "X";
                                    gridDisplay();
                                    check++;
                                    firstIndex = a;
                                    secondIndex = b;
                                    initialLeftA = a;
                                    initialLeftB = b;
                                }
                            }
                        }
                    }
                    check++;
                }
                check = 0;
                break;
            }
        }
        system("CLS");
    } 

    bool Game::inputChecker()
    {
        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                if (displayedArray[b][a] != arrayNumbers[b][a])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void Game::gridDisplay()
    {
        int i = 0; //column (x-axis)
        int j = 0; //row (y-axis)


        while (j < size) //row (y-axis)
        {
            cout << " ";
            while (i < size-1) //column (x-axis)
            {
                if (displayedArray[j][i] == "X")
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << displayedArray[j][i];
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << " | ";
                }

                else if (displayedArray[j][i] != "X")
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << displayedArray[j][i] << " | ";
                }
                i++;
            }

            if (displayedArray[j][i] == "X")
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 14);
                cout << displayedArray[j][i];
                SetConsoleTextAttribute(hConsole, 15);
            }

            else if (displayedArray[j][i] != "X")
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 15);
                cout << displayedArray[j][i];
            }

            cout << endl;

            if (j < size-1)
            {
                cout << spaces;
            }
            cout << endl;
            j++;
            i = 0;
        } 
    }

    void Game::ending(int seconds)
    {
        int minutes = seconds / 60;
        int hours = minutes / 60;

        cout << setw(40) << "( ^o^)/\\(^_^ )" << string(2, '\n');
        cout << setw(45) << "YAYAYA! You finished it in " << hours<<":"<<minutes%60<<":"<<seconds%60<< string(2, '\n'); // set stopwatch to m:s
        cout << setw(60) << "~~~Last 5 highest scores for this difficulty setting~~~" << endl;


        //insert txt.file here. Refer to elimination of older records & insertion of new records

        cout <<endl<< setw(50)<<"[Thanks for playing! Until next time]" << string(2,'\n');  
    }

    
    int main()
    {
        cout << endl << setw(40) << "\\(0_0)/  Hoi! " << endl << endl;

        Game round;
        round.setup();
        auto start = high_resolution_clock::now();
        round.gameplay();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);
        round.ending(duration.count());

        system("pause");
        return 0;
    }
    
    