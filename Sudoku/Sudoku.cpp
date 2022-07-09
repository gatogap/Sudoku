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
    bool checker = false;
    //int a = 0;
    int B = 0;



public:
    void start() //should this be your constructor
    {
        srand(time(NULL));
        cout << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;
        horizontalAssignment(0); //first row should be fine bc if will be the first array we will have to compare

        for (int countRow = 1; countRow < 4; countRow++)
        {
            cout << countRow << endl;
            srand(time(NULL)); //placement of this MATTERS
            horizontalAssignment(countRow); //countRow is the line that will be compared with all the previous ones
            verticalChecker();

            cout << "This was run" << endl;

            while (checker == true)
            {
                verticalChecker();
                countRow = countRow-1;
            }


        }

        
        gridDisplay();

    }

    void horizontalAssignment(int row) //at start, should be equal to zero
    {
        int index1 = 0; //horizontal

        //cout << "~~~~~~~START OF ROUND~~~~~~~~" << endl; DEBUGGER
        
        int b = 0;

        //while (b < 1) //row - y axis. b would give its starting y/row in which repition should be prevented
        //{

            int horizontal[4] = { 1,2,3,4 };

            int a = 0;
            
            /*  INCLUDE THIS IF YOU ARE THINKING TO CHECK ALL PREVIOUS COLUMN SLOTS. not necessary at the moment
            while (a < 4) //column - x axis
            {
                horizontal[a] = 0;
                a++;
            };
            */

            /*------START OF ROW HERE---- - */
            a = 0;
            while (a < 4) //column - x axis
            {
                index1 = rand() % 4;
                bool indicator1 = false;

                while (horizontal[index1] == 0 )
                {
                    index1 = rand() % 4;
                }

                if (horizontal[index1] != 0 )
                {
                    arrayNumbers[row][a] = horizontal[index1];
                 
                   cout << "Current slot value " << horizontal[index1] << endl;
                    horizontal[index1] = 0;
                    
                    a++;
                }
                
            }
            
            //b++;
       // }

        //cout << "~~~~~~~END OF ROUND~~~~~~~~" << endl; DEBUGGER
    }



    void verticalChecker()
    {
        checker = false;
        for (int column = 0; column < 4; column++)
        {
            for (int first = 0; first < 4; first++)
            {
                for (int second = first + 1; second < 4; second++)
                {
                    if (first!= second && arrayNumbers[first][column] == arrayNumbers[second][column])
                    {
                        cout << "column: " << column << endl; //DEBUGGER
                        cout << "first: " << first << endl; //DEBUGGER
                        cout << "second: " << second << endl << endl; //DEBUGGER
                        gridDisplay();
                        horizontalAssignment(second); //start from the x, end at that x on the why y axis.
                        gridDisplay();
                        checker = false;
                       
                       
                    }
                }
            }
        }
        
    }



    void gridDisplay()
    {
        int i = 0; //column
        int j = 0; //row


        while (j < 4) //row
        {
            cout << " ";
            while (i < 3) //column
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
