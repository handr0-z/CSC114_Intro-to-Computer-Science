//--------------------------------------------------------------------------------------------------------------------------------
//  College:                            Delaware Techincal Community College
//  Course:                             CSC 114: Intro to Computer Science
//  Instructor:                         Instructor Mike (Thompson)
//  Author:                             Alejandro Pantoja-Zurita
//  Deliverables:                       Module #3, Assignment #2
//  Date:                               1/29/2025
//  Attributions:                       Program created to calculate required amount of ingredients to make # loaves of bread.
//  CSC114-Module3-Assignment 2.cpp:    This file contains the 'main function. Program executions beings and ends there.
//--------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{   //Introduce the program and the purpose to the end user.
    cout << "(Module #3 Assignment #2: Vars & Data Types)\n\n";
    cout << "          Alejandro Pantoja Zurita          \n";
    cout << "____________________________________________\n\n";
    cout << "      -- PERSONAL BREAD LOAF RECIPE --      \n";
    cout << "____________________________________________\n\n\n";

    // Declare any required variables needed for recipe.
    float flourPerRecipe;
    float saltPerRecipe;
    float yeastPerRecipe;
    float waterPerRecipe;
    int breadLoavesDesired;

    // Confirm ingredient amounts to make (1) loaf of bread.
    cout << "Please enter how much you use per (1) loaf of bread below and press Enter.\n\n";
    cout << "Flour (grams) required: ";
    cin >> flourPerRecipe;
    cout << "Salt (grams) required: ";
    cin >> saltPerRecipe;
    cout << "Yeast (grams) required: ";
    cin >> yeastPerRecipe;
    cout << "Water (grams) required: ";
    cin >> waterPerRecipe;
    cout << endl << endl << endl;
    cout << "How many loaves of bread would you like to make? ";
    cin >> breadLoavesDesired;

    // Calculate required ingredients per user input.
    float flourRequired = flourPerRecipe * breadLoavesDesired;
    float saltRequired = saltPerRecipe * breadLoavesDesired;
    float yeastRequired = yeastPerRecipe * breadLoavesDesired;
    float waterRequired = waterPerRecipe * breadLoavesDesired;

    // Provide end user required quantities to make desired # loaves of bread.
    cout << "\n\n\nIn order to make (" << breadLoavesDesired << ") loaves of bread you will need the following: \n\n";
    cout << "Flour required: " << flourRequired << " grams" << endl;
    cout << "Salt required: " << saltRequired << " grams" << endl;
    cout << "Yeast required: " << yeastRequired << " grams" << endl;
    cout << "Water required: " << waterRequired << " grams" << endl;

    system("pause>0");
}