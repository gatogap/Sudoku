//Sudoku grid comes with a few spaces already filled in; the more spaces filled in, the easier the game – the more difficult Sudoku puzzles have very few spaces that are already filled in.
//include keyboard
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> //randomizing
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

        void start() //should this be your constructor
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

            cout << endl << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
            gridDisplay(); 
        }

        void levelOfDifficulty()
        {
            cout<<"[Choose the number of blank spots you would like to solve on your grid]"<<endl<<endl;
            int decision = 0; //user input
            int difficulty = 0; //pass by value

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
                cout << "[TRY AGAIN: Choose options 1-5]" << endl << endl;
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
                for (int firstRow = 0; firstRow < rowChecker-1; firstRow++)
                {
                    for (int secondRow = firstRow + 1; secondRow < rowChecker; secondRow++)
                    {
                        if ( arrayNumbers[firstRow][column] == arrayNumbers[secondRow][column])
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

        void gridDisplay()
        {
            int i = 0; //column (x-axis)
            int j = 0; //row (y-axis)


            while (j < 9) //row (y-axis)
            {
                cout << " ";
                while (i < 8) //column (x-axis)
                {
                    cout << displayedArray[j][i] << " | ";
                    i++;
                }
                cout << displayedArray[j][i];
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
    round.start();

    system("pause");
    //include timer

    return 0;
}
