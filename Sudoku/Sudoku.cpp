//Sudoku grid comes with a few spaces already filled in; the more spaces filled in, the easier the game – the more difficult Sudoku puzzles have very few spaces that are already filled in.
//include keyboard
#include <iostream>
#include <string>
#include <cstdlib> //randomizing library

using namespace std;

class gamePreparation
{
private:
    int index = 0;
    int arrayNumbers[4][4];
    int arrayBlanks[30][30];

public:
    void start() //should this be your constructor
    {
        srand(time(NULL));
        cout << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
        horizontalAssignment(0,0); //first row should be fine bc if will be the first array we will have to compare
        
        for (int countRow = 1; countRow < 4; countRow++)
        {
            cout << countRow << endl;
            
            horizontalAssignment(countRow,0); //countRow is the line that will be compared with all the previous ones
            verticalChecker();
            cout << "This was run" << endl;
        }    
        gridDisplay();
    }

    void horizontalAssignment(int row, int column) //at start, should be equal to zero
    {
        int index1 = 0; //horizontal
        int horizontal[4] = { 1,2,3,4 };
        int a = 0;
      
            /*------START OF ROW HERE-----*/

            while (a < 4) //column - x axis
            {
                index1 = rand() % 4;
                bool indicator = false;

                while (horizontal[index1] == 0 )
                {
                    index1 = rand() % 4;
                }

                if (horizontal[index1] != 0 )
                {
                    arrayNumbers[row][a] = horizontal[index1];
                    horizontal[index1] = 0;
                   
                    a++;
                }           
            }
    }

    void verticalChecker()
    {
     
        for (int column = 0; column < 4; column++)
        {
            for (int firstRow = 0; firstRow < 3; firstRow++)
            {
                for (int secondRow = firstRow + 1; secondRow < 4; secondRow++)
                {
                    if (arrayNumbers[firstRow][column] == arrayNumbers[secondRow][column])
                    {
                        horizontalAssignment(secondRow,column);
                        
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


        while (j < 4) //row (x-axis)
        {
            cout << " ";
            while (i < 3) //column (y-axis)
            {
                cout << arrayNumbers[j][i] << " | ";
                i++;
            }
            cout << arrayNumbers[j][i];
            cout << endl;


            if (j < 3)
            {
                cout << "-----------------------------------";
            }
            cout << endl;
            j++;
            i = 0;
        }
    }
};



int main() {
    cout << "           :) Herro! <3" << endl;

    gamePreparation round;
    round.start();


    system("pause");
    //include timer

    return 0;
}
