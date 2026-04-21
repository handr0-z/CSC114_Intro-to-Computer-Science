//----------------------------------------------------------------------------------------------------------------------------
//  College:                            Delaware Techincal Community College
//  Course:                             CSC 114: Intro to Computer Science
//  Instructor:                         Instructor Mike (Thompson)
//  Author:                             Alejandro Pantoja-Zurita
//  Deliverables:                       Module #5, Assignment 1
//  Date:                               02/12/2025
//  Attributions:                       Program created to convert US, Canadian, & Japanese Currency
//  CSC114-Module5-Assignment1.cpp:     This file contains the 'main function. Program executions beings and ends there.
//----------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Declare any variables requried to execute program.
	float minValue = -1;
	float maxValue = -2;
	float incrementValue = 0;
    short int optionMenu = 0;
    double exchangeRate = 0;
    string currencySelected;
    float startCurrency = 0;
    float endCurrency =0 ;

    // Introduce program purpose with banner to user.
    cout << "Module #5 Assignment #1: While Loop\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Name: Alejandro Pantoja Zurita\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Program: Currency Converter\n";
    cout << "-----------------------------------------------------------------------------------------\n\n";

    // Confirm with user the desired currency.
    cout << "CURRENCY CONVERTER\n\n";
    cout << "Convert U.S. (Dollar) to: \n";
    cout << "1) Japan (Yen)\n";
    cout << "2) Canada (Dollar)\n\n";

    // Set exchange rate based on option chosen above.
    while (optionMenu < 1 || optionMenu > 2)
    {
        cout << "Select (1) or (2): ";
        cin >> optionMenu;
        cout << "\n";

        if (optionMenu == 1) 
        {
            exchangeRate = 151.3000;
            currencySelected = "JAPAN";
        }
        else if (optionMenu == 2) 
        {
            exchangeRate = 1.4311;
            currencySelected = "CANADA";
        }
        else
            cout << "Error! Please select option (1) or option (2).\n\n";
    }

    cout << "-----------------------------------------------------------------------------------------\n\n";

    // Confirm values user would like to see on chart.
    cout << "Creating exchange rate chart...\n\n";

    // Loops created to ensure appropriate values are entered by user.
    while (minValue < 0) 
    {
        cout << "Enter a Minimum Value (US dollar): $";
        cin >> minValue;
        cout << "\n";
        if (minValue < 0)
            cout << "Error! Minimum Value cannot be lower than 0.\n\n";
        maxValue = minValue - 2;
    }
    while (maxValue < minValue)
    {
        cout << "Enter a Maximum Value (US dollar): $";
        cin >> maxValue;
        cout << "\n";
        if (maxValue < minValue)
            cout << "Error! Maximum value cannot be lower than Maximum Value.\n\n";
    }
    while (incrementValue <= 0 || incrementValue >= maxValue)
    {
        cout << "Enter Increment Value (US dollar): $";
        cin >> incrementValue;
        cout << "\n";
        if (incrementValue <= 0)
            cout << "Error! Increment Value must be more than 0.\n\n";
        else if (incrementValue >= maxValue)
            cout << "Error! Increment Value must be less than Max Value.\n\n";
    }

    cout << "-----------------------------------------------------------------------------------------\n\n";

    // Display requested chart per user input.
    cout << "U.S. TO " << currencySelected << " CURRENCY CONVERTER\n\n";
    cout << "CURRENT EXCHANGE RATE: " << exchangeRate << "\n\n";

    // Loop created to generate a chart to show minimum to maximum values as requested by user.
    // Referenced https://cplusplus.com/forum/beginner/233106/ to set appropriate precision based on currency.
    while (minValue <= maxValue) 
    {
        startCurrency = minValue;
        endCurrency = startCurrency * exchangeRate;
        if (exchangeRate == 151.3000)
        {
            if (startCurrency < 10)
                cout << fixed << setprecision(2) << "US Dollar: $" << startCurrency << "               " << " Japanese Yen: " << setprecision(0) << endCurrency << "\n";
            else if (startCurrency < 100)
                cout << fixed << setprecision(2) << "US Dollar: $" << startCurrency << "              " << " Japanese Yen: " << setprecision(0) << endCurrency << "\n";
            else
                cout << fixed << setprecision(2) << "US Dollar: $" << startCurrency << "             " << " Japanese Yen: " << setprecision(0) << endCurrency << "\n";
            minValue += incrementValue;
        }
        else 
        {
            if (startCurrency < 10)
                cout << fixed << setprecision(2) << "US Dollar: $" << startCurrency << "               " << " Canadian Dollar: $" << endCurrency << "\n";
            else if (startCurrency < 100)
                cout << fixed << setprecision(2) << "US Dollar: $" << startCurrency << "              " << " Canadian Dollar: $" << endCurrency << "\n";
            else
                cout << fixed << setprecision(2) << "US Dollar: $" << startCurrency << "             " << " Canadian Dollar: $" << endCurrency << "\n";
            minValue += incrementValue;
        }
    }
    cout << "\n-----------------------------------------------------------------------------------------\n\n";
}