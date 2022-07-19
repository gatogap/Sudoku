//include keyboard
#include <iostream>
#include <string>

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

class gamePreparation
{
    private:
        //making the arrays strings will display blank spaces on the 9x9 grid
        string arrayNumbers[9][9]; 
        string arrayBlanks[9][9];
        string displayedArray[9][9];
        int rowChecker = 0;

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
                rowChecker = countRow+1; 
                verticalChecker();         
            }    
            displayAssignment();
            levelOfDifficulty();
            system("CLS");
        }

        void levelOfDifficulty()
        {
            cout<<"[Choose the number of blank spots you would like to solve on your grid]"<<endl<<endl;
            int decision = 0; //user input
            int difficulty = 0; //pass by reference

            cout << " 1) 10 Blank Slots" << endl;
            cout << " 2) 20 Blank Slots" << endl;
            cout << " 3) 30 Blank Slots" << endl;
            cout << " 4) 40 Blank Slots" << endl;
            cout << " 5) 50 Blank Slots" << endl<<endl;
            cout << " Enter your decision here: ";
            cin >> decision;
            cout << endl;

            switch (decision)
            {
            case 1:
                blankAssignment(10);
                break;

            case 2:
                blankAssignment(20);
                break;

            case 3:
                blankAssignment(30);
                break;

            case 4:
                blankAssignment(40);
                break;

            case 5:
                blankAssignment(50);
                break;

            default: 
                cout << "~[TRY AGAIN: Choose options 1-5]~" << endl << endl;
                Sleep(2050);
                system("CLS");
                levelOfDifficulty();
            }
        }

        void displayAssignment()
        {

            for (int b = 0; b < 9; b++) //row
            {
                for (int a = 0; a < 9; a++) //column
                {
                    displayedArray[b][a] = arrayNumbers[b][a];
                }
            }
        }

        void blankAssignment(int difficulty)
        {
            int index1 = 0;
            int index2 = 0;
            index1 = rand() % 9;
            index2 = rand() % 9;
            int count = 0;

            while (count < difficulty)
            {
                index1 = rand() % 9;
                index2 = rand() % 9;

                while (displayedArray[index1][index2] == " ")
                {
                    index1 = rand() % 9;
                    index2 = rand() % 9;
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
            for (int b = 0; b < 9; b++) //row
            {
                for (int a = 0; a < 9; a++) //column
                {
                    arrayNumbers[b][a]= "0";
                }
            }
        }

        void blankInitializer() //very helpful for debugging. Maybe necessary to help initialize though. 
        {
            for (int b = 0; b < 9; b++) //row
            {
                for (int a = 0; a < 9; a++) //column
                {
                    arrayBlanks[b][a] = " ";
                }
            }
        }

        void horizontalAssignment(int row) //at start, row is zero
        {
            int index = 0; //horizontal index
            int a = 0; //column (x-axis)
            string horizontal[9] = { "1","2","3","4","5","6","7","8","9" };
        
                /*------START OF ROW HERE-----*/

                while (a < 9) //column - x axis
                {
                    index = rand() % 9;
                

                    while (horizontal[index] == "0" )
                    {
                        index = rand() % 9;
                    }

                    if (horizontal[index] != "0" )
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
            
            cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
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
                            cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
                            
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
            while (inputChecker() == false)
            {

                switch (_getch())
                {
                    case KEY_UP: //prioritize row
                        if (check < 1)
                        {  
                                for (int b = secondIndex; b >= 0 && check < 1; b--) //row
                                {
                               

                                        if (displayedArray[b][firstIndex] == " ")
                                        {
                                            displayedArray[secondIndex][firstIndex] = " ";
                                            system("CLS");
                                            cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
                                            displayedArray[b][firstIndex] = "X";
                                            gridDisplay();
                                            check++;
                                            secondIndex = b;
                                       
                                        }
                                
                                }
                        }

                        check = 0;
                        break;

                    case KEY_DOWN: ////prioritize row
                            if (check < 1)
                            {
                            
                                    for (int b = secondIndex; b < 9 && check < 1; b++) //row
                                    {
                                        if (displayedArray[b][firstIndex] == " ")
                                        {
                                            displayedArray[secondIndex][firstIndex] = " ";
                                            system("CLS");
                                            cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
                                            displayedArray[b][firstIndex] = "X";
                                            gridDisplay();
                                            check++;
                                            secondIndex = b;
                                        }
                                    }
                            
                            }
 
                            check = 0;
                            break;

                        case KEY_LEFT:
                            if (check < 1)
                            {
                            
                                    for (int a = firstIndex; a >= 0 && check < 1; a--) //row
                                    {
                                        if (displayedArray[secondIndex][a] == " ")
                                        {
                                            displayedArray[secondIndex][firstIndex] = " ";
                                                system("CLS");
                                                cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;   
                                                displayedArray[secondIndex][a] = "X";
                                                gridDisplay();
                                                check++;
                                            firstIndex = a;
                                        }
                                    }
                            
                            }

                            check = 0;
                            break;

                        case KEY_RIGHT:
                            if (check < 1)
                            {
                            
                                    for (int a = firstIndex; a < 9 && check < 1; a++) //row
                                    {
                                        if (displayedArray[secondIndex][a] == " ")
                                        {
                                            displayedArray[secondIndex][firstIndex] = " ";
                                            system("CLS");
                                            cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
                                            displayedArray[secondIndex][a] = "X";
                                            gridDisplay();
                                            check++;
                                            firstIndex = a;
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
                                    cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
                                    gridDisplay();
                                }

                                else if (displayedArray[y - 1][x - 1] != arrayNumbers[y - 1][x - 1])
                                {
                                    system("CLS");
                                    displayedArray[secondIndex][firstIndex] = " ";
                                    cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
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
                                            }


                                            else if (userGuess != arrayNumbers[b][a])
                                            {
                                                cout << "Your guess is not correct! Try again" << endl;
                                                Sleep(2000);
                                            }  
                                        }     
                                    }
                                }

                                system("CLS");
                                cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
                                gridDisplay();
                                check++;
                            }
                            check = 0;
                            break;
                    }
            }
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

            
            cout << "This was run" << endl;
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

        void ending()
        {
            cout << setw(20) << "( ^o^)/\\(^_^ )" << endl;
            cout << setw(20) << "You finished it in " << endl; // include stopwatch value here;
            cout << setw(10) << "~~~Last 10 highest scores for this difficulty setting~~~" << endl;
            cout << setw(15) << "[Would you like to play again?]" << endl;
        }
};



int main() {
  
    cout <<endl<< setw(40) << "\\(0_0)/  Hoi! " << endl;


    gamePreparation round;
    round.setup();
    round.gameplay();
    

    system("pause");
    //include timer

    return 0;
}
