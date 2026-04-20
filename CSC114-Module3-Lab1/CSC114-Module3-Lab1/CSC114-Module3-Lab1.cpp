//----------------------------------------------------------------------------------------------------------------
//  College:                    Delaware Techincal Community College
//  Course:                     CSC 114: Intro to Computer Science
//  Instructor:                 Instructor Mike (Thompson)
//  Author:                     Alejandro Pantoja-Zurita
//  Deliverables:               Module #3, Lab #1
//  Date:                       1/29/2025
//  Attributions:               Simple cookie recipe program created to calculate required ingredients for cookies.
//  CSC114-Module3-Lab1.cpp:    This file contains the 'main function. Program executions beings and ends there.
//----------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{   //Introduce the program and the purpose to the end user.
    cout << "(Module #3 Lab #1: Vars, Data Types, Input)\n\n";
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

    // Confirm # cookies desired with end user to calculate quantities.
    cout << "How many cookies would you like to make? ";
    cin >> cookiesDesired;
    cout << endl << endl;

    // Calculate required ingredients per user input.
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

    system("pause>0");
}