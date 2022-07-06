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
        cout << "    Let's begin your 9x9 grid!" << endl << endl << endl << endl;

        horizontalAssignment(B); //we use parameters so that the program could be rerun at a certain verical point the numbers repreat.
        verticalChecker();
        gridDisplay();




    }

    void horizontalAssignment(int b)
    {
        int index1 = 0; //horizontal

        //cout << "~~~~~~~START OF ROUND~~~~~~~~" << endl; DEBUGGER
        srand(time(NULL));



        while (b < 4) //row - y axis
        {

            int a = 0;
            while (a < 4) //column - x axis
            {
                arrayNumbers[b][a] = 0;
                a++;
            };

            int horizontal[4] = { 1,2,3,4 };

            a = 0;
            while (a < 4) //column - x axis
            {

                index1 = rand() % 4;
                bool indicator1 = false;

                while (horizontal[index1] == 0 && indicator1 == false)
                {
                    index1 = rand() % 4;
                }

                if (horizontal[index1] != 0 && indicator1 == false)
                {
                    arrayNumbers[b][a] = horizontal[index1];
                    indicator1 = true;
                    horizontal[index1] = 0;
                    a++;
                }
            }
            b++;
        }

        //cout << "~~~~~~~END OF ROUND~~~~~~~~" << endl; DEBUGGER
    }



    void verticalChecker()
    {

        for (int column = 0; column < 4; column++)
        {
            for (int first = 0; first < 4; first++)
            {
                for (int second = first + 1; second < 4; second++)
                {
                    while (arrayNumbers[first][column] == arrayNumbers[second][column])
                    {
                        cout << "column: " << column << endl; //DEBUGGER
                        cout << "first: " << first << endl; //DEBUGGER
                        cout << "second: " << second << endl << endl; //DEBUGGER

                        B = second;
                        horizontalAssignment(second); //row is returned
                        verticalChecker2();
                    }
                }
            }
        }
    }

    void verticalChecker2()
    {

        for (int column = 0; column < 4; column++)
        {
            for (int first = 0; first < 4; first++)
            {
                for (int second = first + 1; second < 4; second++)
                {
                    while (arrayNumbers[first][column] == arrayNumbers[second][column])
                    {
                        B = second;
                        horizontalAssignment(second); //row is returned

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


//Changes have been done


int main() {
    cout << "           :) Herro! <3" << endl;

    gamePreparation round;
    round.start();



    //include timer

    return 0;
}
