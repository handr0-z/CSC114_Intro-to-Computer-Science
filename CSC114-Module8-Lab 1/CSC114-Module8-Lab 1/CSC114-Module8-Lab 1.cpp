//----------------------------------------------------------------------------------------------------------------------
//  College:                    Delaware Techincal Community College
//  Course:                     CSC 114: Intro to Computer Science
//  Instructor:                 Instructor Mike (Thompson)
//  Author:                     Alejandro Pantoja-Zurita
//  Deliverables:               Module #8, Lab #1
//  Date:                       03/08/2025
//  Attributions:               Simple program created to practice using arrays.
//  CSC114-Module8-Lab1.cpp:    This file contains the multiple functions to practice setting up functions.
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
float sum2Numbers(float, float);
float multiply2Numbers(float, float);
double circleCircumferenceAndArea(double);
void minNumber(float, float, float);
void maxNumber(float, float, float);
void evenOrOddNumber(int);
void voteAge(int);
bool menuLoop();
void userInput(float&, float&, float&, int&, float&);
float inputTrap(float);


int main()
{
    // Declare any variables needed for program
    bool loopProgram = false;
    float userNumber[3];
    float circleRadius = 1;
    int age;

    float showSum;
    
    // Introduce the program and the purpose to the end user.
    cout << "          (Module #8 Lab #1: Functions)         \n\n";
    cout << "            Alejandro Pantoja Zurita            \n";
    cout << "________________________________________________\n\n";
    cout << "                --  Functions  --               \n";
    cout << "================================================\n\n";
    
    // Loop created to loop the program.
    do
    {
        // Collect user data for program.
        userInput(userNumber[0], userNumber[1], userNumber[2], age, circleRadius);
        cout << "================================================\n\n";

        // Function 1: Sum of 2 Numbers
        cout << "FUNCTION 1: SUM OF (2) NUMBERS (" << userNumber[0] << ", " << userNumber[1] << ", " << userNumber[2] << ")\n\n";
        showSum = sum2Numbers(userNumber[0], userNumber[1]);
        cout << userNumber[0] << " + " << userNumber[1] << " = " << showSum << "\n";

        showSum = sum2Numbers(userNumber[0], userNumber[2]);
        cout << userNumber[0] << " + " << userNumber[2] << " = " << showSum << "\n";

        showSum = sum2Numbers(userNumber[2], userNumber[1]);
        cout << userNumber[2] << " + " << userNumber[1] << " = " << showSum << "\n";
        cout << "________________________________________________\n\n";

        // Function 2: Sum of 2 Numbers
        cout << "FUNCTION 2: MULTIPLY (2) NUMBERS (" << userNumber[0] << ", " << userNumber[1] << ", " << userNumber[2] << ")\n\n";
        showSum = multiply2Numbers(userNumber[0], userNumber[1]);
        cout << userNumber[0] << " x " << userNumber[1] << " = " << showSum << "\n";

        showSum = multiply2Numbers(userNumber[0], userNumber[2]);
        cout << userNumber[0] << " x " << userNumber[2] << " = " << showSum << "\n";

        showSum = multiply2Numbers(userNumber[2], userNumber[1]);
        cout << userNumber[2] << " x " << userNumber[1] << " = " << showSum << "\n";
        cout << "________________________________________________\n\n";

        // Function 3: Circumference & Area
        circleCircumferenceAndArea(circleRadius);
        cout << "________________________________________________\n\n";

        // Function 4: Minimum Number
        minNumber(userNumber[0], userNumber[1], userNumber[2]);
        cout << "________________________________________________\n\n";

        // Function 5: Maximum Number
        maxNumber(userNumber[0], userNumber[1], userNumber[2]);
        cout << "________________________________________________\n\n";

        // Function 6: Even or Odd Number
        cout << "FUNCTION 6: EVEN OR ODD NUMBER\n\n";
        evenOrOddNumber(userNumber[0]);

        evenOrOddNumber(userNumber[1]);

        evenOrOddNumber(userNumber[2]);
        cout << "________________________________________________\n\n";

        // Function 7: Voter Age
        voteAge(age);
        cout << "________________________________________________\n\n";

        // Loop created to run program again
        loopProgram = menuLoop();
        cout << "================================================\n\n";

    } while (loopProgram == true);
}

// Funciton for summing up numbers
float sum2Numbers(float num1, float num2)
{
    float sum;

    // Do the math to return correct variable.
    sum = num1 + num2;
    return sum;
}

// Funciton for multiplying up numbers
float multiply2Numbers(float num1, float num2)
{
    float sum;

    // Do the math to return correct variable.
    sum = num1 * num2;
    return sum;
}

// Fuction for circle circumference & area
double circleCircumferenceAndArea(double num1)
{
    double circumference = 2 * 3.14 * num1;
    double area = 3.14 * num1 * num1;

    cout << "FUNCTION 3: CIRCUMFERENCE & AREA OF CIRCLE\n\n";

    cout << "Radius: " << num1<< "\n";

    // Calculate Circumference
    cout << "Circumference: " << circumference << "\n";

    // Calculate Area
    cout << "Area: " << area << "\n";
    return circumference, area;
}

// Function to orgranize find Minimum Number
void minNumber(float num1, float num2, float num3)
{
    cout << "FUNCTION 4: MINIMUM NUMBER (" << num1 << ", " << num2 << ", " << num3 << ")\n\n";

    if (num1 < num2 && num1 < num3)
        cout << "Minimum Number: " << num1 << "\n";
    else if (num2 < num3)
        cout << "Minimum Number: " << num2 << "\n";
    else
        cout << "Minimum Number: " << num3 << "\n";
}

// Function to orgranize numbers (greatest - least)
void maxNumber(float num1, float num2, float num3)
{
    cout << "FUNCTION 5: MAXIMUM NUMBER (" << num1 << ", " << num2 << ", " << num3 << ")\n\n";

    if (num1 > num2 && num1 > num3)
        cout << "Maximum Number: " << num1 << "\n";
    else if (num2 > num3)
        cout << "Maximum Number: " << num2 << "\n";
    else
        cout << "Maximum Number: " << num3 << "\n";
}

// Function to determine if number is even or odd.
void evenOrOddNumber(int num1)
{
    if (num1 % 2)
        cout << num1 << " is an odd number.\n";
    else
        cout << num1 << " is an even number.\n";
}

// Function to determine if age requirement to vote is met
void voteAge(int num1)
{
    cout << "FUNCTION 7: VOTING AGE\n\n";

    cout << "User Age: " << num1 << "\n\n";

    if (num1 < 18)
        cout << "You are too young to vote.\n";
    else
        cout << "You are eligible to vote.\n";
}

// Function verify if program should loop.
bool menuLoop()
{
    string loopmenu;

    do
    {
        // Prompt user if they would like to run the program again.
        cout << "Would you like to run the program again? (Y/N): ";
        cin >> loopmenu;
        cout << "\n";

        if (loopmenu == "y" || loopmenu == "Y")
            return true;
        else if (loopmenu == "N" || loopmenu == "n")
        {
            return false;
        }
        else
            cout << "Error! Invalid input detected.\n\n";

    } while (loopmenu != "y" && loopmenu != "Y" && loopmenu != "N" && loopmenu != "n");
}

// Function to collect user input.
void userInput(float &num1, float &num2, float &num3, int &age, float &radius)
{
    cout << "INPUT DATA\n\n";

    // Collect values from user
    cout << "Enter (3) numbers below.\n\n";

    cout << "Number 1: ";
    cin >> num1;
    inputTrap(num1);

    cout << "Number 2: ";
    cin >> num2;
    inputTrap(num2);

    cout << "Number 3: ";
    cin >> num3;
    inputTrap(num3);
    cout << "\n";

    cout << "How old are you? ";
    cin >> age;
    inputTrap(age);
    cout << "\n";

    cout << "Enter the radius of a circle: ";
    cin >> radius;
    inputTrap(radius);
    cout << "\n";
}

// Function to trap for invalid input.
float inputTrap(float num1)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "\n";
        cout << "Error! Invalid input detected.\n\n";
        cout << "Try again: ";
        cin >> num1;
        cout << "\n";
    }

    return num1;
}