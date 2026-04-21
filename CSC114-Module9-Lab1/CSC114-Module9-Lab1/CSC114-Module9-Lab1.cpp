//---------------------------------------------------------------------------------------------------------------------------------------------
//  College:                            Delaware Techincal Community College
//  Course:                             CSC 114: Intro to Computer Science
//  Instructor:                         Instructor Mike (Thompson)
//  Author:                             Alejandro Pantoja-Zurita
//  Deliverables:                       Module #9, Lab
//  Date:                               03/31/2025
//  Attributions:                       Simple cookie recipe program created to calculate required ingredients for cookies from menu options.
//  CSC114-Module9-Lab.cpp:             This file contains multiple functions. Program executions beings and ends within the main function.
//---------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Notes: I created functions for the parts of the program that could be compartmentalized to reduce the size of the main function.

// Function Prototypes
void programBanner(float&, float&, float&, float&);
int mainMenu(int&);
bool programLoop(bool);
void resultDisplay(int, float, float, float);
void calculations(int&, float&, float&, float&, float&);
int inputTxtFile(float&, float&, float&, float&);
bool fileOpen(float&, float&, float&, float&);

int main()
{
    // Declare any required variables for recipe.
    float sugarPerRecipe = -1; // Base is 1.5 cups
    float butterPerRecipe = -1; // Base is 1.0 cups
    float flourPerRecipe = -1; // Base is 2.75 cups
    float cookiesPerRecipe = -1; // base is 48 cookies

    bool menuLoop = false;

    int cookieMultiplier;
    int cookiesDesired = -1;

    // Program banner.
    programBanner(cookiesPerRecipe, sugarPerRecipe, butterPerRecipe, flourPerRecipe);

    // Loop created in case user would like to run program again.
    do
    {

        // Ask user to Confirm # cookies desired to calculate quantities from list provided below.
        cookiesDesired = mainMenu(cookiesDesired);

        cout << "------------------------------------------------------------------------------------------------------\n\n";

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
        menuLoop = programLoop(menuLoop);

        cout << "------------------------------------------------------------------------------------------------------\n\n";

    } while (menuLoop == true);
}

// Function to display program banner to user.
void programBanner(float& cookies, float& sugar, float& butter, float& flour)
{
    // Program banner.
    cout << "                                      (Module #9 Lab: File Input)                                     \n\n";
    cout << "                                       Alejandro Pantoja Zurita                                       \n";
    cout << "------------------------------------------------------------------------------------------------------\n\n";
    cout << "                                      -- SIMPLE COOKIE RECIPE --                                      \n";
    cout << "------------------------------------------------------------------------------------------------------\n\n";

    inputTxtFile(cookies, sugar, butter, flour);

    // Provide default recipe to user for reference.
    /*cout << "Default Recipe makes (" << cookies << ") cookies.\n";
    cout << "Sugar: " << sugar << " Cups required.\n";
    cout << "Butter: " << butter << " Cups required.\n";
    cout << "Flour: " << flour << " Cups required.\n";
    cout << "------------------------------------------------------------------------------------------------------\n\n";*/
}

// Main menu function was created to return a requried value to main function. Aside from that a string was used in place of char, and I trapped for invalid inputs.
int mainMenu(int& cookiesDesired)
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
            cout << "------------------------------------------------------------------------------------------------------\n";
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
void calculations(int& cookiesDesired, float& cookiesPerRecipe, float& sugarPerRecipe, float& butterPerRecipe, float& flourPerRecipe)
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
void resultDisplay(int cookie, float sugar, float butter, float flour)
{
    cout << "In order to make (" << cookie << ") cookies you will need: \n\n";
    cout << "Sugar: " << setprecision(2) << sugar << " Cups required. \n";
    cout << "Butter: " << setprecision(2) << butter << " Cups required. \n";
    cout << "Flour: " << setprecision(2) << flour << " Cups required. \n";
    cout << "------------------------------------------------------------------------------------------------------\n\n";

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
        cout << "------------------------------------------------------------------------------------------------------\n\n";
    }

}

// Program loop function was created to compartmentalize a specific funtion within the main program. Aside from that a string was used in place of char, and I trapped for invalid inputs.
bool programLoop(bool menuLoop)
{
    string loopConfirmation;

    do
    {
        cout << "Would you like to run the program again? (Yes/No): ";
        cin >> loopConfirmation;
        cout << "\n";

        if (loopConfirmation == "yes" || loopConfirmation == "Yes" || loopConfirmation == "y" || loopConfirmation == "Y" || loopConfirmation == "YES")
            menuLoop = true;
        else if (loopConfirmation == "no" || loopConfirmation == "No" || loopConfirmation == "n" || loopConfirmation == "N" || loopConfirmation == "NO")
            menuLoop = false;
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Error! Invalid answer provided.\n\n";
        }
    } while (loopConfirmation != "yes" && loopConfirmation != "Yes" && loopConfirmation != "y" && loopConfirmation != "Y" && loopConfirmation != "no" && loopConfirmation != "No" && loopConfirmation != "n" && loopConfirmation != "N");

    return menuLoop;
}

// Function to generate a input file for user to provide information or verify user numbers;
int inputTxtFile(float& cookies, float& sugar, float& butter, float& flour)
{
    string confirmation;
    string confirmation2;
    bool loop = false;

    cout << "------------------------------------------------------------------------------------------------------\n\n";

    // Verify with user if input.txt file exists with correct numbers.
    do
    {
        // Confirm with user if input file has been created to check values.
        cout << "input.txt file available with ingredient amounts for cookie recipe? (Yes/ No): ";
        cin >> confirmation;
        cout << "------------------------------------------------------------------------------------------------------\n\n";

        if (confirmation == "Yes")
        {
            loop = fileOpen(cookies, sugar, butter, flour);
        }
        else if (confirmation == "No")
        {
            // Generate input.txt file for user to confirm # of rooms & price of paint.
            ofstream programFile("input.txt");

            if (programFile.is_open())
            {
                programFile << "*** Number of cookies per recipe ***\n\n";
                programFile << "*** Sugar Required for recipe ***\n\n";
                programFile << "*** Butter Required for recipe ***\n\n";
                programFile << "*** Flour Required for recipe ***\n\n";
                programFile.close();

                cout << "                    --- input.txt file created ---                    \n\n";
                cout << "WARNING!!! DO NOT PROCEED BEFORE ADDING CORRECT VALUES TO input.txt FILE\n\n";
                cout << "Please add the following information below into the input.txt file\n\n";
                cout << "*** Number of cookies per recipe (whole numbers only) ***\n";
                cout << "*** Sugar Required per recipe ***\n";
                cout << "*** Butter Required per recipe ***\n";
                cout << "*** Flour Required per recipe ***\n";
                cout << "------------------------------------------------------------------------------------------------------\n\n";
                system("pause");
                cout << "------------------------------------------------------------------------------------------------------\n\n";
            }
            else
            {
                cout << "Error! unable to create input.txt file\n";
                cout << "------------------------------------------------------------------------------------------------------\n\n";
                return 0;
            }
        }
        else
        {
            cout << "Error! invalid input detected.\n";
            cout << "------------------------------------------------------------------------------------------------------\n\n";
        }
    } while (confirmation != "Yes" && confirmation != "No" || loop == true);

    do
    {
        loop = false;
        // Display values to user for final confirmation.
        cout << "Cookies per recipe: " << cookies << "\n";
        cout << "Sugar Required: " << sugar << "\n";
        cout << "Butter Required: " << butter << "\n";
        cout << "Flour Required: " << flour << "\n";
        cout << "------------------------------------------------------------------------------------------------------\n\n";

        // Confirm with user if input.txt file has been has been adjusted.
        cout << "Did you provide accurate numbers to input.txt file for cookie recipe? (Yes/ No): ";
        cin >> confirmation2;
        cout << "------------------------------------------------------------------------------------------------------\n\n";

        if (confirmation2 == "Yes")
        {
            if (cookies <= 0 || sugar <= 0 || butter <= 0 || flour <= 0)
            {
                cout << "Error! invalid values detected inside input.txt file.\n\n";
                cout << "Please enter positive values only inside input.txt file.\n\n";
                cout << "------------------------------------------------------------------------------------------------------\n\n";
            }
        }
        else if (confirmation2 == "No")
        {
            cout << "Please enter correct values inside input.txt file before continuing.\n\n";
            cout << "------------------------------------------------------------------------------------------------------\n\n";
            system("pause");
            cout << "------------------------------------------------------------------------------------------------------\n\n";
            fileOpen(cookies, sugar, butter, flour);
        }
        else
        {
            cout << "Error! invalid input detected.\n";
            cout << "------------------------------------------------------------------------------------------------------\n\n";
        }
    } while (cookies <= 0 || sugar <= 0 || butter <= 0 || flour <= 0 || confirmation2 != "Yes");
}

// Function to open input.txt file to obtain values.
bool fileOpen(float& cookies, float& sugar, float& butter, float& flour)
{
    ifstream programFile("input.txt");

    // Display # inside input.txt file to confirm with user correct numbers.
    if (programFile.is_open())
    {
        programFile >> cookies;
        programFile >> sugar;
        programFile >> butter;
        programFile >> flour;
        programFile.close();
    }
    else
    {
        cout << "Error! input.txt file not found.\n\n";
        cout << "------------------------------------------------------------------------------------------------------\n\n";
        return true;
    }
}
