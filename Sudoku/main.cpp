#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
#include "Sudoku.h"

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