//Sudoku grid comes with a few spaces already filled in; the more spaces filled in, the easier the game � the more difficult Sudoku puzzles have very few spaces that are already filled in.
//include keyboard
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> //randomizing library

using namespace std;

class gamePreparation
{
private:
    int arrayNumbers[9][9];
    int arrayBlanks[9][9];
    int rowChecker = 0;

public:
    void start() //should this be your constructor
    {
        //initializer();
        srand(time(NULL));
        cout << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
        horizontalAssignment(0); 
        
        for (int countRow = 1; countRow < 9; countRow++)
        {  
            horizontalAssignment(countRow); //countRow is the line that will be compared with all the previous lines
            rowChecker = countRow+1; 
            verticalChecker();         
        }    
        gridDisplay(); 
    }


    void initializer() //very helpful for debugging. Maybe necessary to help initialize though. 
    {
        for (int b = 0; b < 9; b++) //row
        {
            for (int a = 0; a < 9; a++) //column
            {
                arrayNumbers[b][a]= 0;
            }
        }
    }

    void horizontalAssignment(int row) //at start, row is zero
    {
        int index1 = 0; //horizontal index
        int a = 0; //column (x-axis)
        int horizontal[9] = { 1,2,3,4,5,6,7,8,9 };
        
            /*------START OF ROW HERE-----*/

            while (a < 9) //column - x axis
            {
                index1 = rand() % 9;
                

                while (horizontal[index1] == 0 )
                {
                    index1 = rand() % 9;
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
                cout << arrayNumbers[j][i] << " | ";
                i++;
            }
            cout << arrayNumbers[j][i];
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
};



int main() {
    cout << setw(23) << ":) Herro! <3" << endl;

    gamePreparation round;
    round.start();

    system("pause");
    //include timer

    return 0;
}
