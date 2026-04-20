//----------------------------------------------------------------------------------------------------------------------
//  College:                    Delaware Techincal Community College
//  Course:                     CSC 114: Intro to Computer Science
//  Instructor:                 Instructor Mike (Thompson)
//  Author:                     Alejandro Pantoja-Zurita
//  Deliverables:               Module #4, Lab #1
//  Date:                       2/03/2025
//  Attributions:               Simple cookie recipe program created to calculate required ingredients for cookies.
//  CSC114-Module4-Lab1.cpp:    This file contains the 'main function. Program executions beings and ends there.
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{   // Introduce the program and the purpose to the end user.
    cout << "     (Module #4 Lab #1: if statements)     \n\n";
    cout << "        Alejandro Pantoja Zurita           \n";
    cout << "___________________________________________\n\n";
    cout << "        -- SIMPLE COOKIE RECIPE --         \n";
    cout << "___________________________________________\n\n\n";

    // Declare any required variables needed for recipe.
    float sugarPerRecipe = 1.5;
    float butterPerRecipe = 1.0;
    float flourPerRecipe = 2.75;
    int cookiesPerRecipe = 48;
    float cookiesDesired = 0;

    // [EXTRA] Variables below can be implemented if user would like to input qty available for ingredients.
    /*float sugarAvailable;
    float butterAvailable;
    float flourAvailable;*/

    // Confirm # cookies desired with end user to calculate quantities.
    cout << "How many cookies would you like to make? ";
    cin >> cookiesDesired;
    if (cookiesDesired <= 0)
    {
        cout << "\n\Please note - program requres a positive number for cookies desired.\n\n";
        cout << "(you entered: " << cookiesDesired << ")" << endl << endl;
        return 0;
    }
    cout << endl;

    // [EXTRA] Confirm available ingredient qty with user with code below. [Not turned on]
    /*{
        cout << "Available sugar (cups): ";
        cin >> sugarAvailable;
        cout << endl;
        if (sugarAvailable <= 0)
        {
            cout << "Please note - program requres a positive number for sugar available.\n\n";
            cout << "(you entered: " << sugarAvailable << ")" << endl << endl;
            return 0;
        }
            cout << "Available butter (cups): ";
        cin >> butterAvailable;
        if (butterAvailable <= 0)
        {
            cout << "\n\Please note - program requres a positive number for butter available.\n\n";
            cout << "(you entered: " << butterAvailable << ")" << endl << endl;
            return 0;
        }
        cout << "Available flour (cups): ";
        cin >> flourAvailable;
        if (flourAvailable <= 0)
        {
            cout << "\n\Please note - program requres a positive number for flour available.\n\n";
            cout << "(you entered: " << flourAvailable << ")" << endl << endl;
            return 0;
        }
    }
    cout << endl << endl;*/

    // Calculate required ingredients for cookies desired by user.
    float recipeRatio = cookiesDesired / cookiesPerRecipe;
    float sugarRequired = sugarPerRecipe * recipeRatio;
    float butterRequired = butterPerRecipe * recipeRatio;
    float flourRequired = flourPerRecipe * recipeRatio;

    // Provide end user required quantities to make desire # cookies.
    cout << "In order to make (" << cookiesDesired << ") cookies you will need: \n";
    cout << "Sugar: " << sugarRequired << " Cups required. \n";
    cout << "Butter: " << butterRequired << " Cups required. \n";
    cout << "Flour: " << flourRequired << " Cups required. \n\n\n";

    // Provide default recipe to user for reference.
    cout << "Default Recipe makes (" << cookiesPerRecipe << ") cookies.\n";
    cout << "Sugar: " << sugarPerRecipe << " Cups required.\n";
    cout << "Butter: " << butterPerRecipe << " Cups required.\n";
    cout << "Flour: " << flourPerRecipe << " Cups required.\n\n\n";

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

    // [EXTRA] Expanded notification to user about missing ingredients if they input ingredients avaiable.
    /*float sugarNeeded = sugarRequired - sugarAvailable;
    float butterNeeded = butterRequired - sugarAvailable;
    float flourNeeded = flourRequired - flourAvailable;

    if ((sugarNeeded > 0) || (butterNeeded > 0) || (flourNeeded > 0))
    {
        cout << " ! ! ! Warning: Please order more ingredients to complete recipe. ! ! !\n\n";

        if (sugarNeeded > 0)
            cout << "Missing: " << sugarNeeded << " Cups of sugar.";
        if (butterNeeded > 5)
            cout << "Missing: " << butterNeeded << " Cups of butter.";
        if (flourNeeded > 0)
            cout << "Missing: " << flourNeeded << " Cups of flour";
    }*/

    system("pause>0");
}