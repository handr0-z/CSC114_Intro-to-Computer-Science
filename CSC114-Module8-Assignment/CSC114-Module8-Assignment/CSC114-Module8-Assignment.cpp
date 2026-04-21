//---------------------------------------------------------------------------------------------------------------------------------------------
//  College:                            Delaware Techincal Community College
//  Course:                             CSC 114: Intro to Computer Science
//  Instructor:                         Instructor Mike (Thompson)
//  Author:                             Alejandro Pantoja-Zurita
//  Deliverables:                       Module #8, Assignment #1
//  Date:                               02/11/2025
//  Attributions:                       Simple cookie recipe program created to calculate required ingredients for cookies.
//  CSC114-Module8-Assignment.cpp:      This file contains multiple functions. Program executions beings and ends within the main function.
//---------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// Notes: I created functions for the parts of the program that could be compartmentalized to reduce the size of the main function.
// Function Prototypes
bool programLoop();
void resultDisplay(float, float, float, float);
float mainMenu(float);
void calculations(float, int, float, float, float);
void programBanner(float, float, float, int);

int main()
{
    // Declare any required variables for recipe.
    float sugarPerRecipe = 1.5;
    float butterPerRecipe = 1.0;
    float flourPerRecipe = 2.75;
    int cookiesPerRecipe = 48;

    bool menuLoop = false;

    int cookieMultiplier;
    float cookiesDesired = 1;

    // Program banner.
    programBanner(sugarPerRecipe, butterPerRecipe, flourPerRecipe, cookiesPerRecipe);

    // Loop created in case user would like to run program again.
    do
    {
        // Ask user to Confirm # cookies desired to calculate quantities from list provided below.
        cookiesDesired = mainMenu(cookiesDesired);

        cout << "______________________________________________________________\n\n";

        // Provide end user required quantities to make desired # cookies as requested.
        if (cookiesDesired == 0)
        {
            // Loop created to display ingredients required for "All the above" option.
            for (cookieMultiplier = 1; cookieMultiplier <= 4; cookieMultiplier++)
            {
                // Calculate & display required ingredients for cookies desired by user.
                cookiesDesired = 5 * cookieMultiplier;
                calculations(cookiesDesired, cookiesPerRecipe, sugarPerRecipe, butterPerRecipe, flourPerRecipe);
            }
        }
        else
        {
            // Calculate & display required ingredients for cookies desired by user.
            calculations(cookiesDesired, cookiesPerRecipe, sugarPerRecipe, butterPerRecipe, flourPerRecipe);
        }

        // Ask user if they would like to run the program again
        menuLoop = programLoop();

        cout << "______________________________________________________________\n\n";

    } while (menuLoop == true);
}

// Program Banner
void programBanner(float num1, float num2, float num3, int wholeNum1)
{
    cout << "              (Module #8 Assignment: Functions)               \n\n";
    cout << "                   Alejandro Pantoja Zurita                   \n";
    cout << "______________________________________________________________\n\n";
    cout << "                  -- SIMPLE COOKIE RECIPE --                  \n";
    cout << "______________________________________________________________\n\n";

    // Provide default recipe to user for reference.
    cout << "Default Recipe makes (" << wholeNum1 << ") cookies.\n";
    cout << "Sugar: " << num1 << " Cups required.\n";
    cout << "Butter: " << num2 << " Cups required.\n";
    cout << "Flour: " << num3 << " Cups required.\n";
    cout << "______________________________________________________________\n\n";
}

// Main menu function was created to return a requried value to main function. Aside from that a string was used in place of char, and I trapped for invalid inputs.
float mainMenu(float cookiesDesired)
{
    string optionMenu;

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

        if (optionMenu == "A" || optionMenu == "a")
            cookiesDesired = 5;
        else if (optionMenu == "B" || optionMenu == "b")
            cookiesDesired = 10;
        else if (optionMenu == "C" || optionMenu == "c")
            cookiesDesired = 15;
        else if (optionMenu == "D" || optionMenu == "d")
            cookiesDesired = 20;
        else if (optionMenu == "E" || optionMenu == "e")
            cookiesDesired = 0;
        else if (optionMenu == "F" || optionMenu == "f")
        {
            cout << "______________________________________________________________\n";
            cout << "\nDesired number of cookies: ";
            cin >> cookiesDesired;

            // Loop created in case user enters a negative number.
            while (cin.fail() || cookiesDesired <= 0)
            {
                cin.clear();
                cin.ignore();
                cout << "\nError! invalid input detected.\n\n";
                cout << "Desired number of cookies: ";
                cin >> cookiesDesired;
            }
        }
        else
            cout << "\nError! invalid input detected.\n\n";
    } while (optionMenu != "A" && optionMenu != "a" && optionMenu != "B" && optionMenu != "b" && optionMenu != "C" && optionMenu != "c" && optionMenu != "D" && optionMenu != "d" && optionMenu != "E" && optionMenu != "e" && optionMenu != "F" && optionMenu != "f");

    return cookiesDesired;
}

// Calculations function was created to reduce the amount of items lines that were duplicated within the main function depending on main menu choice. 
void calculations(float cookiesDesired, int cookiesPerRecipe, float sugarPerRecipe, float butterPerRecipe, float flourPerRecipe)
{
    float recipeRatio;
    float sugarRequired;
    float butterRequired;
    float flourRequired;

    recipeRatio = cookiesDesired / cookiesPerRecipe;
    sugarRequired = sugarPerRecipe * recipeRatio;
    butterRequired = butterPerRecipe * recipeRatio;
    flourRequired = flourPerRecipe * recipeRatio;

    // Provide end user required quantities to make desired # cookies.
    resultDisplay(cookiesDesired, sugarRequired, butterRequired, flourRequired);
}

// Result Display function was created to reduce the amount of items lines that were duplicated within the main function depending on main menu choice. 
void resultDisplay(float cookie, float sugar, float butter, float flour)
{
    cout << "In order to make (" << cookie << ") cookies you will need: \n\n";
    cout << "Sugar: " << sugar << " Cups required. \n";
    cout << "Butter: " << butter<< " Cups required. \n";
    cout << "Flour: " << flour << " Cups required. \n";
    cout << "______________________________________________________________\n\n";

    // Notify user ingredients may need to be ordered if the requried amount exceeds 5 Cups.
    if ((sugar > 5) || (butter > 5) || (flour > 5))
    {
        cout << "Please confirm enough ingredients below are available for recipe:\n\n";
        if (sugar > 5)
            cout << "5+ Cups of sugar required.\n";
        if (butter > 5)
            cout << "5+ Cups of butter required.\n";
        if (flour > 5)
            cout << "5+ Cups of flour required.\n";
        cout << "______________________________________________________________\n\n";
    }

}

// Program loop function was created to compartmentalize a specific funtion within the main program. Aside from that a string was used in place of char, and I trapped for invalid inputs.
bool programLoop()
{
    string loopConfirmation;

    do
    {
        cout << "Would you like to run the program again? (Yes/No): ";
        cin >> loopConfirmation;
        cout << "\n";

        if (loopConfirmation == "yes" || loopConfirmation == "Yes" || loopConfirmation == "y" || loopConfirmation == "Y" || loopConfirmation == "YES")
            return true;
        else if (loopConfirmation == "no" || loopConfirmation == "No" || loopConfirmation == "n" || loopConfirmation == "N" || loopConfirmation == "NO")
            return false;
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Error! Invalid answer provided.\n\n";
        }
    }
    while (loopConfirmation != "yes" && loopConfirmation != "Yes" && loopConfirmation != "y" && loopConfirmation != "Y" && loopConfirmation != "no" && loopConfirmation != "No" && loopConfirmation != "n" && loopConfirmation != "N");
}