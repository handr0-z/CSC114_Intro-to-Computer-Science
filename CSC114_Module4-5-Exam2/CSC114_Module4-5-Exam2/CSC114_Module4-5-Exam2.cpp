// CSC114_Module4-5-Exam2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool programLoop = true;
    int deviceMenu;
    int repairMenu;
    string deviceName;
    string repairType;
    int cost;

    do
    {
        cout << "TECH REPAIR\n";
        cout << "________________________________\n\n";

        cout << "Select a Device:\n";
        cout << "1) Computer\n";
        cout << "2) Smartphone\n\n";
        cout << "Option: ";
        cin >> deviceMenu;

        while (deviceMenu < 1 || deviceMenu > 2)
        {
            cout << "Error! Invalid Input Detected.\n";
            cout << "Option: ";
            cin >> deviceMenu;
        }

        cout << "________________________________\n\n";
        if (deviceMenu == 1)
        {
            deviceName = "Computer";
            cout << "Select a Repair Type:\n";
            cout << "1) Software Install\n";
            cout << "2) Battery Replacement\n";
            cout << "3) Screen Repair\n\n";
            cout << "Option: ";
            cin >> repairMenu;

            while (repairMenu < 1 || repairMenu > 3)
            {
                cout << "Error! Invalid Input Detected.\n";
                cout << "Option: ";
                cin >> repairMenu;
            }

            if (repairMenu == 1)
            {
                repairType = "Software Install";
                cost = 20;
            }
            else if (repairMenu == 2)
            {
                repairType = "Battery Replacement";
                cost = 25;
            }
            else
            {
                repairType = "Screen Repair";
                cost = 100;
            }
        }
        else
        {
            deviceName = "Smartphone";
            cout << "Select a Repair Type:\n";
            cout << "1) Battery Replacement\n";
            cout << "2) Screen Repair\n";
            cout << "3) Data Recovery\n\n";
            cout << "Option: ";
            cin >> repairMenu;

            while (repairMenu < 1 || repairMenu > 3)
            {
                cout << "Error! Invalid Input Detected.\n";
                cout << "Option: ";
                cin >> repairMenu;
            }

            if (repairMenu == 1)
            {
                repairType = "Battery Replacement";
                cost = 50;
            }
            else if (repairMenu == 2)
            {
                repairType = "Screen Repair";
                cost = 200;
            }
            else
            {
                repairType = "Data Recovery";
                cost = 110;
            }
        }

        cout << "________________________________\n\n";
        cout << "Device Type: " << deviceName << endl;
        cout << "Repair Type: " << repairType << endl;
        cout << "Cost: $" << cost << endl;
        cout << "________________________________\n\n\n\n\n\n\n\n";

    } while (programLoop == true);

}
