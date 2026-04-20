//----------------------------------------------------------------------------------------------------------------------------
//  College:                            Delaware Techincal Community College
//  Course:                             CSC 114: Intro to Computer Science
//  Instructor:                         Instructor Mike (Thompson)
//  Author:                             Alejandro Pantoja-Zurita
//  Deliverables:                       Module #4, Assignment 1
//  Date:                               02/05/2025
//  Attributions:                       Program created to calculate account account balance after fees.
//  CSC114-Module4-Assignment1.cpp:     This file contains the 'main function. Program executions beings and ends there.
//----------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Declare any variables needed to calculate final account balance.
    float initialBalance = 0;
    float accountFee = 10;
    float minimumBalanceFee = 15;
    int checksWritten = 0;
    float checkFee = 0;
    float totalCheckFee;
    float totalFees = accountFee;
    float finalBalance=0;

    // Introduce program purpose with banner to user.
    cout << "Module #4 Assignment #1: Branching Code\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Name: Alejandro Pantoja Zurita\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Program: Account Fee Calculator\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "To calculate account fees please enter the following information.\n\n";
    cout << "Account Balance: ";
    cin >> initialBalance;
    cout << endl;

    // Confirm account balance with user to see if minimum balance fee is applied to account.
    if (initialBalance < 400)
    {
        if (initialBalance < 0)
        {
            cout << "Warning!!!\n\n";
            cout << "Insufficient funds detected.\n\n";
            cout << "Contact customer service for assistance.\n\n\n";
            return 0;
        }
        else if (initialBalance < 400)
        {
            totalFees = totalFees+ minimumBalanceFee;
        }
    }

    // Confirm number of checks written to calculate check fee.
    cout << "How many checks have been written this month?\n\n";
    cout << "Checks Written: ";
    cin >> checksWritten;
    cout << "\n";

    // Apply correct checking fee per and per user input
    if (checksWritten < 0)
    {
        cout << "Error! Please enter a postive value for the number of checks written this month.\n\n";
        return 0;
    }
    else if (checksWritten < 20)
        checkFee = 0.10;
    else if (checksWritten <= 39)
        checkFee = 0.08;
    else if (checksWritten <= 59)
        checkFee = 0.06;
    else
        checkFee = 0.04;

    // Calculate account information based on information collected from user.
    totalCheckFee = checksWritten * checkFee;
    totalFees = totalFees + totalCheckFee;
    finalBalance = initialBalance - totalFees;

    cout << "Checking Fee: -$" << totalCheckFee << "\n";
    cout << "(" << checksWritten << " Checks Written x $" << checkFee << " Fee)\n\n\n";

    // Display finalized account information for user.
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Initial Balance:                            $" << initialBalance << endl;
    cout << "Total Fees:                                -$" << totalFees << "\n";
    if (finalBalance < 0)
    {
        cout << "FINAL BALANCE:                             -$" << abs(finalBalance) << "\n";
        cout << endl;
        cout << "Insufficient funds detected.\n";
        cout << "Contact customer service for assistance.\n";
    }
    else
        cout << "FINAL BALANCE:                              $" << finalBalance << "\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Fee Breakdown:\n";
    cout << "Monthly Account Fee:                       -$" << accountFee << endl;
    if (initialBalance < 400)
        cout << "Minimum Balance Fee:                       -$" << minimumBalanceFee << endl;
    cout << "Checking Fee:                              -$" << totalCheckFee << "\n";
    cout << "(" << checksWritten << " Checks Written x $" << checkFee << " Fee)\n";
    cout << "TOTAL:                                     -$" << totalFees << "\n";
    cout << "-----------------------------------------------------------------------------------------\n";

}
