#include <iostream>
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
using namespace std;
using namespace std::chrono;

class gamePreparation
{
private:
    //making the arrays strings will display blank spaces on the 9x9 grid
    string arrayNumbers[8][8];
    string arrayBlanks[8][8]; //MAKE THIS DYNAMIC
    string displayedArray[8][8]; //MAKE THIS DYNAMIC
    

    int spaceArraysOptions[3];
    int rowChecker = 0;
    int size = 0;
    

public:

    void setup()
    {
        numberInitializer();
        blankInitializer();
        srand(time(NULL));
        horizontalAssignment(0);

        for (int countRow = 1; countRow < 9; countRow++)
        {
            horizontalAssignment(countRow); //countRow is the line that will be compared with all the previous lines
            rowChecker = countRow + 1;
            verticalChecker();
        }
        displayAssignment();
        sizeDifficulty();
        spaceDifficulty();
        system("CLS");
    }

    void sizeDifficulty()
    {
        cout << "[Choose the size of your grid]" << endl << endl;
        cout << " 1) 4x4" << endl;
        cout << " 2) 6x6" << endl;
        cout << " 3) 8x8" << string(2, '\n');
        cout << " Enter your decision here: ";
        cin >> size;
        cout << endl;

        switch (size)
        {
        case 1:
            spaceArraysOptions[0]= 4;
            spaceArraysOptions[1] = 8;
            spaceArraysOptions[2] = 12;
            break;

        case 2:
            spaceArraysOptions[0] = 6;
            spaceArraysOptions[1] = 18;
            spaceArraysOptions[2] = 30;
            break;

        case 3:
            spaceArraysOptions[0] = 8;
            spaceArraysOptions[1] = 36;
            spaceArraysOptions[2] = 49;
            break;

        default:
            cout << "~[TRY AGAIN: Choose options 1-3]~" << string(2, '\n');
            Sleep(2050);
            system("CLS");
            sizeDifficulty();
        }  
    }

    void spaceDifficulty()
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
            cout << "~[TRY AGAIN: Choose options 1-5]~" << string(2, '\n');
            Sleep(2050);
            system("CLS");
            spaceDifficulty();
        }
    }

    void displayAssignment()
    {

        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                displayedArray[b][a] = arrayNumbers[b][a];
            }
        }
    }

    void blankAssignment(int difficulty)
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

    void numberInitializer() //very helpful for debugging. Maybe necessary to help initialize though. 
    {
        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                arrayNumbers[b][a] = "0";
            }
        }
    }

    void blankInitializer() //very helpful for debugging. Maybe necessary to help initialize though. 
    {
        for (int b = 0; b < size; b++) //row
        {
            for (int a = 0; a < size; a++) //column
            {
                arrayBlanks[b][a] = " ";
            }
        }
    }

    void horizontalAssignment(int row) //at start, row is zero MAKE HORIZONTAL ARRAY DYNAMIC
    {
        int index = 0; //horizontal index
        int a = 0; //column (x-axis)
        string horizontal[8] = { "1","2","3","4","5","6","7","8" };

        /*------START OF ROW HERE-----*/

        while (a < 8) //column - x axis
        {
            index = rand() % size;

            while (horizontal[index] == "0")
            {
                index = rand() % 9;
            }

            if (horizontal[index] != "0")
            {
                arrayNumbers[row][a] = horizontal[index];
                horizontal[index] = "0";

                a++;
            }
        }
    }

    void verticalChecker()
    {
        for (int column = 0; column < 9; column++)
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


    void gameplay()
    {

        cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
        
        gridDisplay();
        int firstIndex = 0;
        int secondIndex = 0;
        int check = 0;

        if (check < 1)
        {
            for (int b = 0; b < 9 && check < 1; b++) //row
            {
                for (int a = 0; a < 9 && check < 1; a++) //column
                {
                    if (displayedArray[b][a] == " ")
                    {
                        system("CLS");
                        cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');

                        displayedArray[b][a] = "X";
                        gridDisplay();
                        check++;
                        firstIndex = a;
                        secondIndex = b;
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
            switch (_getch())
            {
            case KEY_UP: //prioritize row
                if (check < 1)
                {
                    int a = firstIndex;
                    int checker2 = 0;

                    for (int b = secondIndex; b >= 0 && check < 1; b--) //row
                    {
                        if (displayedArray[b][firstIndex] == " ")
                        {
                            displayedArray[secondIndex][firstIndex] = " ";
                            system("CLS");
                            cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
                            displayedArray[b][firstIndex] = "X";
                            gridDisplay();
                            check++;
                            secondIndex = b;

                        }

                        //make sure the up button could be pressed
                        while (b == 0 && check < 1 && checker2 < 1)
                        {
                            a--;

                            for (int B = 8; B >= 0 && check < 1; B--) //row
                            {
                                if (displayedArray[B][a] == " ")
                                {
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    system("CLS");
                                    cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
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
                if (check < 1)
                {

                    int a = firstIndex;
                    int checker2 = 0;

                    for (int b = secondIndex; b < 9 && check < 1; b++) //row
                    {
                        if (displayedArray[b][firstIndex] == " ")
                        {
                            displayedArray[secondIndex][firstIndex] = " ";
                            system("CLS");
                            cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
                            displayedArray[b][firstIndex] = "X";
                            gridDisplay();
                            check++;
                            secondIndex = b;
                        }


                        //make sure the up button could be pressed
                        while (b == 8 && check < 1 && checker2 < 1)
                        {
                            a++;

                            for (int B = 0; B < 9 && check < 1; B++) //row
                            {
                                if (displayedArray[B][a] == " ")
                                {
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    system("CLS");
                                    cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
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
                if (check < 1)
                {
                    int b = secondIndex;
                    int checker2 = 0;

                    for (int a = firstIndex; a < 9 && check < 1; a--) //row
                    {
                        if (displayedArray[secondIndex][a] == " ")
                        {
                            displayedArray[secondIndex][firstIndex] = " ";
                            system("CLS");
                            cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
                            displayedArray[secondIndex][a] = "X";
                            gridDisplay();
                            check++;
                            firstIndex = a;
                        }

                        while (a == 0 && check < 1 && checker2 < 1)
                        {
                            b--;

                            for (int A = 8; A >= 0 && check < 1; A--) //row
                            {
                                if (displayedArray[b][A] == " ")
                                {
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    system("CLS");
                                    cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
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
                if (check < 1)
                {
                    int b = secondIndex;
                    int checker2 = 0;

                    for (int a = firstIndex; a < 9 && check < 1; a++) //row
                    {
                        if (displayedArray[secondIndex][a] == " ")
                        {
                            displayedArray[secondIndex][firstIndex] = " ";
                            system("CLS");
                            cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
                            displayedArray[secondIndex][a] = "X";
                            gridDisplay();
                            check++;
                            firstIndex = a;
                        }

                        while (a == 8 && check <1 && checker2 < 1)
                        {
                            b++;

                            for (int A = 0; A < 9 && check < 1; A++) //row
                            {
                                if (displayedArray[b][A] == " ")
                                {
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    system("CLS");
                                    cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
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

                    cout << "Enter the 9x9 coordinate you would like to work on:" << endl;

                    cout << "Type your x coordinate (domains [1,9]): ";
                    cin >> x;

                    cout << endl << "Type your y coordinate (ranges [1,9]): ";
                    cin >> y;

                    if (displayedArray[y - 1][x - 1] == arrayNumbers[y - 1][x - 1])
                    {
                        cout << "This coordinate doesn't need to be changed! Pick another one: ";
                        Sleep(2000);
                        system("CLS");
                        cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
                        gridDisplay();
                    }

                    else if (displayedArray[y - 1][x - 1] != arrayNumbers[y - 1][x - 1])
                    {
                        system("CLS");
                        displayedArray[secondIndex][firstIndex] = " ";
                        cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
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


                    for (int b = 0; b < 9; b++) //row
                    {
                        for (int a = 0; a < 9; a++) //column
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
                    cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');

                    if (check < 1)
                    {
                        for (int b = 0; b < 9 && check < 1; b++) //row
                        {
                            for (int a = 0; a < 9 && check < 1; a++) //column
                            {
                                if (displayedArray[b][a] == " ")
                                {
                                    system("CLS");
                                    cout << endl << "    Let's begin your 9x9 grid!" << string(4, '\n');
                                    displayedArray[b][a] = "X";
                                    gridDisplay();
                                    check++;
                                    firstIndex = a;
                                    secondIndex = b;
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

    bool inputChecker()
    {
        for (int b = 0; b < 9; b++) //row
        {
            for (int a = 0; a < 9; a++) //column
            {
                if (displayedArray[b][a] != arrayNumbers[b][a])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void gridDisplay()
    {
        int i = 0; //column (x-axis)
        int j = 0; //row (y-axis)


        while (j < 9) //row (y-axis)
        {
            cout << " ";
            while (i < 8) //column (x-axis)
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

            if (j < 8)
            {
                cout << "-----------------------------------";
            }
            cout << endl;
            j++;
            i = 0;
        } 
    }

    void ending(int seconds)
    {
        int minutes = seconds / 60;
        int hours = minutes / 60;


        cout << setw(40) << "( ^o^)/\\(^_^ )" << string(2, '\n');
        cout << setw(45) << "YAYAYA! You finished it in " << hours<<":"<<minutes%60<<":"<<seconds%60<< string(2, '\n'); // set stopwatch to m:s
        cout << setw(60) << "~~~Last 5 highest scores for this difficulty setting~~~" << endl;


        //insert txt.file here. Refer to elimination of older records & insertion of new records

        cout <<endl<< setw(50)<<"[Thanks for playing! Until next time]" << string(2,'\n');  
    }
};

int main() {
    cout <<endl<< setw(40) << "\\(0_0)/  Hoi! " << endl;

    gamePreparation round;
    round.setup();
    auto start = high_resolution_clock::now();
    round.gameplay();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    round.ending(duration.count());
   
    system("pause");
    return 0;
}
