//---------------------------------------------------------------------------------------------------------------------------------------------
//  College:                            Delaware Techincal Community College
//  Course:                             CSC 114: Intro to Computer Science
//  Instructor:                         Instructor Mike (Thompson)
//  Author:                             Alejandro Pantoja-Zurita
//  Deliverables:                       Module #9, Assignment
//  Date:                               03/22/2025
//  Attributions:                       Program used to provide estimate for paint and jobs
//  CSC114-Module5-Assignment.cpp:      This file contains multiple functions. Program executions beings and ends within the main function.
//---------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Declare function prototypes.
string programBanner(string, string&, string&, int);
int inputTxtFile(int&, float&, int);
int fileOpen(int&, float&, int);
float roomSquareFootage(float, int);
float invalidInputTrap(float);
void roomCalculations(float&, float&, float&, float&, float&, float&, float&);
void displayEstimate(int, float, float, float, float, float, float);
float roomSquareFootage(float, int);
int tableWidth(float);

int main()
{
    // Decalre any variables required for program
    int totalRooms = 0;
    int roomMax = 10;
    float paintPrice = 0;
    int i;

    // need to change array size to match roomMax value
    float roomSF[10];
    float laborTime[10];
    float laborCost[10];
    float paintNeeded[10];
    float paintCost[10];
    float roomCost[10];

    float totalSF = 0;
    float totalLaborTime = 0;
    float totalLaborCost = 0;
    float totalPaint = 0;
    float totalPaintCost = 0;
    float estimateTotal = 0;

    fstream userFile;
    string firstName = "[First Name]";
    string lastName = "[Last Name]";
    string fullName = "user";
    string fileName;
    string confirmation;

    // Program banner and functino to request user's name.
    fullName = programBanner(fullName, firstName, lastName, roomMax);

    // Variable to contain name of finalized estimate file for job.
    fileName = fullName + " Estimate.txt";

    // Generate input.txt file for # of rooms
    inputTxtFile(totalRooms, paintPrice, roomMax);

    // Obtain Room SF for each room from user.
    for (i = 0; i < totalRooms; i++)
    {
        roomSF[i] = roomSquareFootage(roomSF[i], i);
    }
    cout << "------------------------------------------------------------------------------------------------------\n\n";

    // Calculate line items for each room & for the total
    for (i = 0; i < totalRooms; i++)
    {
        roomCalculations(paintPrice, roomSF[i], laborTime[i], laborCost[i], paintNeeded[i], paintCost[i], roomCost[i]);

        totalSF = totalSF + roomSF[i];
        totalLaborTime = totalLaborTime + laborTime[i];
        totalLaborCost = totalLaborCost + laborCost[i];
        totalPaint = totalPaint + paintNeeded[i];
        totalPaintCost = totalPaintCost + paintCost[i];
        estimateTotal = estimateTotal + roomCost[i];
    }

    // Display information for user.
    cout << "Customer Name: " << fullName << "\n\n";
    cout << "------------------------------------------------------------------------------------------------------\n";
    cout << "# OF ROOMS TO BE PAINTED: " << totalRooms << "\n";
    cout << "JOB SQUARE FOOTAGE: " << fixed << setprecision(2) << totalSF << " SF\n\n";
    cout << "LABOR TIME: " << fixed << setprecision(0) << totalLaborTime << " Hours\n";
    cout << "COST: $" << fixed << setprecision(2) << totalLaborCost << "\n\n";
    cout << "PAINT REQUIRED: " << fixed << setprecision(0) << totalPaint << " Gallons\n";
    cout << "COST: $" << fixed << setprecision(2) << totalPaintCost << "\n\n";
    cout << "TOTAL COST: $" << fixed << setprecision(2) << estimateTotal << "\n\n";
    cout << "Note: See below for material/ labor breakdown per room.\n\n";
    cout << "------------------------------------------------------------------------------------------------------\n";
    cout << "Room #       Room SF       Paint Qty        Paint Cost      Labor Hrs       Labor Cost        Total\n";
    cout << "------------------------------------------------------------------------------------------------------\n\n";

    for (i = 0; i < totalRooms; i++)
    {
        displayEstimate(i, roomSF[i], laborTime[i], laborCost[i], paintNeeded[i], paintCost[i], roomCost[i]);
    }
    cout << "------------------------------------------------------------------------------------------------------\n\n";

    do
    {
        // Verify if user would like to save estimate.
        cout << "Would you like to save a copy of the estimate? (Yes/ No): ";
        cin >> confirmation;
        cout << "\n";

        if (confirmation == "Yes" || confirmation == "YES" || confirmation == "yes")
        {
            // Export estimate to file.
            ofstream programFile(fileName);

            if (programFile.is_open())
            {
                programFile << "Customer Name: " << fullName << "\n\n";
                programFile << "------------------------------------------------------------------------------------------------------\n";
                programFile << "# OF ROOMS TO BE PAINTED: " << totalRooms << "\n";
                programFile << "JOB SQUARE FOOTAGE: " << fixed << setprecision(2) << totalSF << " SF\n\n";
                programFile << "LABOR TIME: " << fixed << setprecision(0) << totalLaborTime << " Hours\n";
                programFile << "COST: $" << fixed << setprecision(2) << totalLaborCost << "\n\n";
                programFile << "PAINT REQUIRED: " << fixed << setprecision(0) << totalPaint << " Gallons\n";
                programFile << "COST: $" << fixed << setprecision(2) << totalPaintCost << "\n\n";
                programFile << "TOTAL COST: $" << fixed << setprecision(2) << estimateTotal << "\n\n";
                programFile << "Note: See below for material/ labor breakdown per room.\n\n";
                programFile << "------------------------------------------------------------------------------------------------------\n";
                programFile << "Room #       Room SF       Paint Qty        Paint Cost      Labor Hrs       Labor Cost        Total\n";
                programFile << "------------------------------------------------------------------------------------------------------\n\n";

                for (i = 0; i < totalRooms; i++)
                {
                    int j;

                    programFile << setw(3) << i + 1;

                    j = tableWidth(roomSF[i]);
                    programFile << setw(j + 11) << fixed << setprecision(2) << roomSF[i] << " SF";

                    j = tableWidth(paintNeeded[i]);
                    programFile << setw(j + 3) << fixed << setprecision(0) << paintNeeded[i] << " gallons";

                    j = tableWidth(paintCost[i]);
                    programFile << setw(j + 7) << "$" << fixed << setprecision(2) << paintCost[i];

                    j = tableWidth(laborTime[i]);
                    programFile << setw(j + 7) << fixed << setprecision(0) << laborTime[i] << " hrs";

                    j = tableWidth(laborCost[i]);
                    programFile << setw(j + 8) << "$" << fixed << setprecision(2) << laborCost[i];

                    j = tableWidth(roomCost[i]);
                    programFile << setw(j + 8) << "$" << fixed << setprecision(2) << roomCost[i] << "\n\n";
                }
                cout << "------------------------------------------------------------------------------------------------------\n\n";

                // Close saved estimate file.
                programFile.close();

                cout << "DONE!\n\n";
                cout << "See (" << fileName << ") file for created estimate.\n\n";
                cout << "------------------------------------------------------------------------------------------------------\n\n";
            }
            else
            {
                cout << "Error! unable to create " << fullName << " Estimate.txt file\n\n";
                cout << "------------------------------------------------------------------------------------------------------\n\n";
                return 0;
            }
        }
        else if (confirmation == "No" || confirmation == "NO" || confirmation == "no")
        {
            return 0;
        }
        else
        {
            cout << "Error! invalid input detected.\n";
            cout << "------------------------------------------------------------------------------------------------------\n\n";
        }
    } while (confirmation != "Yes" && confirmation != "YES" && confirmation != "yes");
}

// Function for program banner.
string programBanner(string fullName, string& first, string& last, int max)
{
    // initialize any variables

    cout << "Module #9 Assignment: File Input and Output\n\n";
    cout << "Name: Alejandro Pantoja Zurita\n";
    cout << "------------------------------------------------------------------------------------------------------\n\n";
    cout << "                                        -- Picasso Painters --                                        \n";
    cout << "------------------------------------------------------------------------------------------------------\n";
    cout << "Please confirm the number of rooms (" << max << " Max) to be painted and the price of paint (per gallon) using\n";
    cout << "input.txt file to provide accurate information for estimate of job to be completed accurately.\n";
    cout << "------------------------------------------------------------------------------------------------------\n\n";

    // Prompt user to provide first and last name;
    cout << "Customer First Name: ";
    cin >> first;
    cout << "\n";
    cout << "Customer Last Name: ";
    cin >> last;
    cout << "\n";
    cout << "------------------------------------------------------------------------------------------------------\n\n";

    fullName = first + " " + last;

    return fullName;
}

// Function to generate a input file for user to provide information or verify user numbers;
int inputTxtFile(int& room, float& paint, int max)
{
    string confirmation;
    string confirmation2;

    // Verify with user if input.txt file exists with correct numbers.
    do
    {
        // Confirm with user if input file has been created to check values.
        cout << "input.txt file avaialble with total room number & cost of paint? (Yes/ No): ";
        cin >> confirmation;
        cout << "------------------------------------------------------------------------------------------------------\n\n";

        if (confirmation == "Yes")
        {
            fileOpen(room, paint, max);
        }
        else if (confirmation == "No")
        {
            // Generate input.txt file for user to confirm # of rooms & price of paint.
            ofstream programFile("input.txt");

            if (programFile.is_open())
            {
                programFile << "*** Number of rooms to be painted here ***\n\n";
                programFile << "*** Cost of paint (per gallon) here ***";
                programFile.close();

                cout << "                    --- input.txt file created ---                    \n\n";
                cout << "WARNING!!! DO NOT PROCEED BEFORE ADDING CORRECT VALUES TO input.txt FILE\n\n";
                cout << "Please add the following information below into the input.txt file\n\n";
                cout << "*** Number of rooms to be painted (whole numbers only) ***\n";
                cout << "*** Cost of paint per gallon ***\n";
                cout << "------------------------------------------------------------------------------------------------------\n\n";
                system("pause");
                cout << "------------------------------------------------------------------------------------------------------\n\n";
            }
            else
            {
                cout << "Error! unable to create input.txt file\n\n";
                cout << "------------------------------------------------------------------------------------------------------\n\n";
                return 0;
            }
        }
        else
        {
            cout << "Error! invalid input detected.\n";
            cout << "------------------------------------------------------------------------------------------------------\n\n";
        }
    } while (room <= 0 || room > max || paint < 0);

    // Display values to user for final confirmation.
    do
    {
        cout << "Number of rooms to be painted: " << room << "\n\n";
        cout << "Cost of paint (per gallon): $" << fixed << setprecision(2) << paint << "\n\n";
        cout << "------------------------------------------------------------------------------------------------------\n\n";

        // Confirm with user if input.txt file has been has been adjusted.
        cout << "Did you provide accurate numbers to input.txt file ? (Yes / No) : ";
        cin >> confirmation2;
        cout << "------------------------------------------------------------------------------------------------------\n\n";

        if (confirmation2 == "Yes")
            return 1;
        else if (confirmation2 == "No")
        {
            cout << "Please enter correct values inside input.txt file before continuing.\n\n";
            cout << "------------------------------------------------------------------------------------------------------\n\n";
            system("pause");
            cout << "------------------------------------------------------------------------------------------------------\n\n";
            fileOpen(room, paint, max);
        }
        else
        {
            cout << "Error! invalid input detected.\n";
            cout << "------------------------------------------------------------------------------------------------------\n\n";
        }
    } while (confirmation2 != "Yes");
}

// Function to open input.txt file to obtain values.
int fileOpen(int& room, float& paint, int max)
{
    fstream programFile("input.txt");

    // Display # inside input.txt file to confirm with user correct numbers.
    if (programFile.is_open())
    {
        programFile >> room;
        programFile >> paint;
        programFile.close();
    }
    else
    {
        cout << "Error! unable to open input.txt file\n\n";
        cout << "------------------------------------------------------------------------------------------------------\n\n";
        return 0;
    }

    // Check for valid numbers from input.txt
    if (room <= 0 || room > max)
    {
        invalidInputTrap(room);
        cout << "Total rooms cannot be a negative number or above " << max << ".\n\n";
        cout << "File must contain WHOLE NUMBERS ONLY, NO LETTERS!\n\n";
        cout << "------------------------------------------------------------------------------------------------------\n\n";
    }

    if (paint < 0)
    {
        invalidInputTrap(room);
        cout << "Paint cost (per gallon) cannot be a negative number.\n\n";
        cout << "File must contain numbers only, NO LETTERS!\n\n";
        cout << "------------------------------------------------------------------------------------------------------\n\n";
    }
}

// Funciton trap created to account for invalid input.
float invalidInputTrap(float invalid)
{
    if (cin.fail() || invalid <= 0)
    {
        cin.clear();
        cin.ignore();
        cout << "\n";
        cout << "Error! Invalid input detected.\n\n";
    }

    return invalid;
}

// Function to retrieve SF of rooms for estimate.
float roomSquareFootage(float room, int num1)
{
    do
    {
        cout << "Square Footage for Room #" << num1 + 1 << ": ";
        cin >> room;
        cout << "\n";
        invalidInputTrap(room);

    } while (room <= 0);

    return room;
}

// Calcualte quantities as required for job.
void roomCalculations(float& paintPrice, float& roomSF, float& laborTime, float& laborCost, float& paintNeeded, float& paintCost, float& roomCost)
{
    // Decalre any variables required for function
    float baseSF = 110;
    int baseHours = 8;
    float basePay = 25.00;
    float workRateSF = baseSF / baseHours;

    laborTime = roomSF / workRateSF;
    laborCost = laborTime * basePay;
    paintNeeded = roomSF / baseSF;
    paintCost = paintNeeded * paintPrice;
    roomCost = paintCost + laborCost;
}

// Function created to display estimate of job
void displayEstimate(int i, float roomSF, float laborTime, float laborCost, float paintNeeded, float paintCost, float roomCost)
{
    int j;

    cout << setw(3) << i + 1;

    j = tableWidth(roomSF);
    cout << setw(j + 11) << fixed << setprecision(2) << roomSF << " SF";

    j = tableWidth(paintNeeded);
    cout << setw(j + 3) << fixed << setprecision(0) << paintNeeded << " gallons";

    j = tableWidth(paintCost);
    cout << setw(j + 7) << "$" << fixed << setprecision(2) << paintCost;

    j = tableWidth(laborTime);
    cout << setw(j + 7) << fixed << setprecision(0) << laborTime << " hrs";

    j = tableWidth(laborCost);
    cout << setw(j + 8) << "$" << fixed << setprecision(2) << laborCost;

    j = tableWidth(laborCost);
    cout << setw(j + 8) << "$" << fixed << setprecision(2) << roomCost << "\n\n";
}

int tableWidth(float value)
{
    if (value < 10)
        return 5;
    else if (value < 100)
        return 4;
    else if (value < 1000)
        return  3;
    else
        return 2;
}
