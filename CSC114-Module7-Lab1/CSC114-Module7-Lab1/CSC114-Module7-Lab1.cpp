//----------------------------------------------------------------------------------------------------------------------
//  College:                    Delaware Techincal Community College
//  Course:                     CSC 114: Intro to Computer Science
//  Instructor:                 Instructor Mike (Thompson)
//  Author:                     Alejandro Pantoja-Zurita
//  Deliverables:               Module #7, Lab #1
//  Date:                       02/26/2025
//  Attributions:               Simple program created to practice using arrays.
//  CSC114-Module7-Lab1.cpp:    This file contains the 'main function. Program executions beings and ends there.
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
    // code to trap for incorrect input type obtained from https://cplusplus.com/forum/general/207458/, (LINES 69-70)

    // Declare arrays of different data types
    // Index #         1    2    3    4    5    6    7    8    9     10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26
    char letter[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',  'J',  'K',  'L',  'M',  'N',  'O',  'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z' };

    // Index #                 1    2    3    4    5    6    7    8    9    10
    float decimalNumber[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.1, 8.1, 9.1, 10.0 };

    // Index #            1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26
    int wholeNumber[] = { 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1 };

    // Index #              1        2       3        4      5         6         7         8       9         10       11      12
    string color[] = { "White", "Black", "Blue", "Green", "Red", "Purple", "Yellow", "Purple", "Pink", "Magenta", "Brown", "Cyan" };

    // Declare any variables needed for program
    float optionMenu;
    int counterValue;
    bool loopProgram = false;
    char loopmenu;
    int i;


    // Introduce the program and the purpose to the end user.
    cout << "           (Module #7 Lab #1: Arrays)           \n\n";
    cout << "            Alejandro Pantoja Zurita            \n";
    cout << "________________________________________________\n\n";
    cout << "                  -- ARRAYS --                  \n";
    cout << "________________________________________________\n\n";

    // Loop created to loop the program.
    do
    {
        // Prompt User to select prompt to display
        cout << "This program displays the index values of multiple arrays.\n";
        cout << "Begin by entering a number as a counter.\n";
        cout << "____________________________________________________________\n\n";

        // Loop created to ensure user enter valid option.
        do
        {
            // Prompt user to enter an integer.
            cout << "Enter a number to use as a counter (1-9)\n";
            cout << "Counter #: ";
            cin >> counterValue;

            // Error message displayed to inform user of invalid input.
            if (counterValue < 1 || counterValue > 9)
            {
                cout << "\n";
                cout << "Error! Invalid input detected.\n";
                cout << "____________________________________________________________\n\n";
                cin.clear();
                cin.ignore();
            }
        } while (counterValue < 1 || counterValue > 9);

        cout << "____________________________________________________________\n\n";


        // Loop created to display values for characters array.
        cout << "Character Array (26 Values):\n";
        for (i = 0; i < 26; i=i+counterValue)
        {
            cout << "Index Value " << i << ": " << letter[i] << endl;
        }
        cout << "____________________________________________________________\n\n";

        // Loop created to display values for decimals array.
        cout << "Decimal Array (10 Values):\n";
        for (i = 0; i < 10; i = i + counterValue)
        {
            cout << "Index Value " << i << ": " << decimalNumber[i] << endl;
        }
        cout << "____________________________________________________________\n\n";

        // Loop created to display values for integers array.
        cout << "Integer Array (26 Values):\n";
        for (i = 0; i < 26; i = i + counterValue)
        {
            cout << "Index Value " << i << ": " << wholeNumber[i] << endl;
        }
        cout << "____________________________________________________________\n\n";

        // Loop created to display values for colors array.
        cout << "Color Array (12 Values):\n";
        for (i = 0; i < 12; i = i + counterValue)
        {
            cout << "Index Value " << i << ": " << color[i] << endl;
        }

        // Reset values used in calculations in case program runs again.
        counterValue = 0;

        do
        {
            // Prompt user if they would like to run the program again.
            cout << "____________________________________________________________\n\n";
            cout << "Would you like to run the program again? (Y/N): ";
            cin >> loopmenu;
            cout << "\n\n";

            if (loopmenu == 'y' || loopmenu == 'Y')
                loopProgram = true;
            else if (loopmenu == 'N' || loopmenu == 'n')
                loopProgram = false;
            else
                cout << "Error! Invalid input detected.";
        } while (loopmenu != 'y' && loopmenu != 'Y' && loopmenu != 'N' && loopmenu != 'n');
        cout << "____________________________________________________________\n\n";

    } while (loopProgram == true);
}