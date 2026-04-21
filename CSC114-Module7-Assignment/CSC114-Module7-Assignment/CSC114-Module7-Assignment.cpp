//----------------------------------------------------------------------------------------------------------------------
//  College:                            Delaware Techincal Community College
//  Course:                             CSC 114: Intro to Computer Science
//  Instructor:                         Instructor Mike (Thompson)
//  Author:                             Alejandro Pantoja-Zurita
//  Deliverables:                       Module #7, Assignment #1
//  Date:                               02/28/2025
//  Attributions:                       Simple program created to practice using arrays.
//  CSC114-Module7-Assignment1.cpp:     This file contains the 'main function. Program executions beings and ends there.
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;


int main()
{
    // Declare any variables needed for program
    int winningNumbers[5];
    int userNumbers[5];
    float optionMenu;
    int counterValue;
    bool loopProgram = false;
    char loopmenu;
    int i=0;
    int matchingNumbers =0;

    // Code to generate random number was obtained from https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    //used to generate random numbers each time program is run (once - if need new numbers run program again) https://stackoverflow.com/questions/7748071/same-random-numbers-every-time-i-run-the-program
    int range = 9 - 1 + 1;
    srand(time(NULL));

    // Loop created to generate random lottery winning numbers.
    for (i = 0; i < 5; i++)
        winningNumbers[i] = rand() % range + 1;

    // Loop created to loop the program.
    do
    {
        // Introduce the program and the purpose to the end user.
        cout << "        (Module #7 Assignment #1: Arrays)       \n\n";
        cout << "            Alejandro Pantoja Zurita            \n";
        cout << "________________________________________________\n\n";
        cout << "                  --  Lottery  --                  \n";
        cout << "________________________________________________\n";

        // Inform user what they need to do.
        cout << "Enter ticket number (5 digits) to verify prize.\n";
        cout << "Enter numbers from left to right on ticket.\n";
        cout << "Number must be between 0-9.\n";
        cout << "________________________________________________\n\n";

        // Loop created to for user to input ticket numbers.
        for (i = 0; i < 5; i++) 
        {
            cout << "Number " << i + 1 << ": ";
            cin >> userNumbers[i];
            //cout << "\n";

            // Loop created to trap for invalid input. Trap for incorrect variable type obtaained from https://stackoverflow.com/questions/64181665/unsigned-integer-variable-displays-as-0-when-some-alphabets-are-given-as-input
            while (cin.fail() || userNumbers[i] < 0 || userNumbers[i] > 9)
            {
                cin.clear();
                cin.ignore();
                cout << "\n";
                cout << "Error! Invalid input detected.\n";
                cout << "Number " << i + 1 << ": ";
                cin >> userNumbers[i];
            }

            // check for matching numbers.
            if (winningNumbers[i] == userNumbers[i])
                matchingNumbers += 1;

            cout << "________________________________________________\n\n";
        }

        // Display info to user.
        cout << "User Lottery Numbers:             " << userNumbers[0] << " " << userNumbers[1] << " " << userNumbers[2] << " " << userNumbers[3] << " " << userNumbers[4] << "\n\n";
        cout << "Winning Lottery Numbers:          " << winningNumbers[0] << " " << winningNumbers[1] << " " << winningNumbers[2] << " " << winningNumbers[3] << " " << winningNumbers[4] << "\n\n";
        cout << "Matching Lottery Numbers (" << matchingNumbers << "):     ";

        // Loop to inform user of matching numbers.
        for (i = 0; i < 5; i++) 
        {
            if (winningNumbers[i] == userNumbers[i])
                cout << userNumbers[i] << " ";
            else
                cout << "  ";
        }

        cout << "\n\n";

        // Message created to notify user of winning ticket.
        if (userNumbers[0] == winningNumbers[0] && userNumbers[1] == winningNumbers[1] && userNumbers[2] == winningNumbers[2] && userNumbers[3] == winningNumbers[3] && userNumbers[4] == winningNumbers[4])
            cout << "GRAND PRIZE WINNER!!!\n";

        // Loop created to run program again
        do
        {
            // Prompt user if they would like to run the program again.
            cout << "________________________________________________\n\n";
            cout << "Would you like to run the program again? (Y/N): ";
            cin >> loopmenu;
            cout << "\n\n";

            if (loopmenu == 'y' || loopmenu == 'Y')
                loopProgram = true;
            else if (loopmenu == 'N' || loopmenu == 'n')
                loopProgram = false;
            else
                cout << "Error! Invalid input detected.\n";
        } while (loopmenu != 'y' && loopmenu != 'Y' && loopmenu != 'N' && loopmenu != 'n');
        cout << "________________________________________________\n\n\n\n\n";

        matchingNumbers = 0;

    } while (loopProgram == true);
}