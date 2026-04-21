//----------------------------------------------------------------------------------------------------------------------
//  College:                    Delaware Techincal Community College
//  Course:                     CSC 114: Intro to Computer Science
//  Instructor:                 Instructor Mike (Thompson)
//  Author:                     Alejandro Pantoja-Zurita
//  Deliverables:               Module #5, Lab #2
//  Date:                       02/11/2025
//  Attributions:               Simple cookie recipe program created to calculate required ingredients for cookies.
//  CSC114-Module5-Lab2.cpp:    This file contains the 'main function. Program executions beings and ends there.
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{   // Introduce the program and the purpose to the end user.
    cout << "                 (Module #5 Lab #2: For Loop)                 \n\n";
    cout << "                   Alejandro Pantoja Zurita                   \n";
    cout << "______________________________________________________________\n\n";
    cout << "                  -- SIMPLE COOKIE RECIPE --                  \n";
    cout << "______________________________________________________________\n\n";

    // Declare any required variables for recipe.
    float sugarPerRecipe = 1.5;
    float butterPerRecipe = 1.0;
    float flourPerRecipe = 2.75;
    int cookiesPerRecipe = 48;
    float cookiesDesired = 0;
    char optionMenu;
    char loopConfirmation;
    bool menuLoop = false;
    float recipeRatio;
    int cookieMultiplier = 0;
    float sugarRequired;
    float butterRequired;
    float flourRequired;

    // Provide default recipe to user for reference.
    cout << "Default Recipe makes (" << cookiesPerRecipe << ") cookies.\n";
    cout << "Sugar: " << sugarPerRecipe << " Cups required.\n";
    cout << "Butter: " << butterPerRecipe << " Cups required.\n";
    cout << "Flour: " << flourPerRecipe << " Cups required.\n\n";
    cout << "______________________________________________________________\n\n";

    // Loop created in case user would like to run program again.
    do
    {
        // Ask user to Confirm # cookies desired to calculate quantities from list provided below.
        cout << "How many cookies would you like to make?\n";
        cout << "A) 5 Cookies\n";
        cout << "B) 10 Cookies\n";
        cout << "C) 15 Cookies\n";
        cout << "D) 20 Cookies\n";
        cout << "E) All the above\n";
        cout << "F) Other\n\n";

        // Loop created to ensure user enters a valid option.
        do
        {
            cout << "Enter letter to confirm option: ";
            cin >> optionMenu;

            if (optionMenu == int('A') || optionMenu == int('a'))
                cookiesDesired = 5;
            else if (optionMenu == int('B') || optionMenu == int('b'))
                cookiesDesired = 10;
            else if (optionMenu == int('C') || optionMenu == int('c'))
                cookiesDesired = 15;
            else if (optionMenu == int('D') || optionMenu == int('d'))
                cookiesDesired = 20;
            else if (optionMenu == int('E') || optionMenu == int('e'))
            {
                cookiesDesired = 1;
                cookieMultiplier = 1;
            }
            else if (optionMenu == int('F') || optionMenu == int('f'))
            {
                cout << "\nDesired number of cookies: ";
                cin >> cookiesDesired;

                // Loop created in case user enters a negative number.
                while (cookiesDesired <= 0)
                {
                    cout << "\n\nPlease note - program requires a positive number for cookies desired.\n\n";
                    cout << "(you entered: " << cookiesDesired << ")\n\n\n";
                    cout << "Desired number of cookies: ";
                    cin >> cookiesDesired;
                }
            }
            else
            {
                cout << "\nError! Please select a letter from the options listed above.\n\n";
                cout << "Invalid answer provided.\n\n";
            }
        }
        while (optionMenu != int('A') && optionMenu != int('a') && optionMenu != int('B') && optionMenu != int('b') && optionMenu != int('C') && optionMenu != int('c') && optionMenu != int('D') && optionMenu != int('d') && optionMenu != int('E') && optionMenu != int('e') && optionMenu != int('F') && optionMenu != int('f'));
        cout << "______________________________________________________________";

        // Provide end user required quantities to make desired # cookies as requested.
        if (cookieMultiplier == 1)
        {
            // Loop created to display ingredients required for "All the above" option.
            for (cookieMultiplier = 1; cookieMultiplier <= 4; cookieMultiplier++)
            {
                // Calculate required ingredients for cookies desired by user.
                cout << endl << endl;
                cookiesDesired = 5;
                cookiesDesired *= cookieMultiplier;
                recipeRatio = cookiesDesired / cookiesPerRecipe;
                sugarRequired = sugarPerRecipe * recipeRatio;
                butterRequired = butterPerRecipe * recipeRatio;
                flourRequired = flourPerRecipe * recipeRatio;

                // Provide end user required quantities to make desired # cookies.
                cout << "In order to make (" << cookiesDesired << ") cookies you will need: \n";
                cout << "Sugar: " << sugarRequired << " Cups required. \n";
                cout << "Butter: " << butterRequired << " Cups required. \n";
                cout << "Flour: " << flourRequired << " Cups required.\n";
                cout << "______________________________________________________________";

            }
            cout << endl << endl;
        }
        else
        {
            // Calculate required ingredients for cookies desired by user.
            recipeRatio = cookiesDesired / cookiesPerRecipe;
            sugarRequired = sugarPerRecipe * recipeRatio;
            butterRequired = butterPerRecipe * recipeRatio;
            flourRequired = flourPerRecipe * recipeRatio;

            // Provide end user required quantities to make desired # cookies.
            cout << endl << endl;
            cout << "In order to make (" << cookiesDesired << ") cookies you will need: \n";
            cout << "Sugar: " << sugarRequired << " Cups required. \n";
            cout << "Butter: " << butterRequired << " Cups required. \n";
            cout << "Flour: " << flourRequired << " Cups required. \n\n";
            cout << "______________________________________________________________\n\n";
        }

        // Notify user ingredients may need to be ordered if the requried amount exceeds 5 Cups.
        if ((sugarRequired > 5) || (butterRequired > 5) || (flourRequired > 5))
        {
            cout << "!!!Warning: You may need to order more ingredients.!!!\n\n";
            cout << "Please confirm enough ingredients below are avialble:\n";
            if (sugarRequired > 5)
                cout << "Sugar: More than 5 Cups of sugar required.\n";
            if (butterRequired > 5)
                cout << "Butter: More than 5 Cups of butter required.\n";
            if (flourRequired > 5)
                cout << "Flour: More than 5 Cups of flour required.\n\n\n";
        }

        // Ask user if they would like to run the program again
        do
        {
            cout << "Would you like to run the program again? (Yes/No): ";
            cin >> loopConfirmation;
            cout << "\n";

            if (loopConfirmation == int('yes') || loopConfirmation == int('Yes') || loopConfirmation == int('y') || loopConfirmation == int('Y'))
                menuLoop = true;
            else if (loopConfirmation == int('no') || loopConfirmation == int('No') || loopConfirmation == int('n') || loopConfirmation == int('N'))
                menuLoop = false;
            else
                cout << "\n\nError! Invalid answer provided.\n\n";
        }
        while (loopConfirmation != int('yes') && loopConfirmation != int('Yes') && loopConfirmation != int('y') && loopConfirmation != int('Y') && loopConfirmation != int('no') && loopConfirmation != int('No') && loopConfirmation != int('n') && loopConfirmation != int('N'));
        
        cout << "______________________________________________________________\n\n";
    } 
    while (menuLoop == true);
}