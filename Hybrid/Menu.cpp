#include "Menu.h"
#include "Functions.h"
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <cstring>

using namespace std;


void Menu::pMenu()
{
    cout << endl;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|||                 Select an option                   |||"<< endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|||             [1] Print All Sites                    |||" << endl;
    cout << "|||             [2] Lookup Social Media                |||" << endl;
    cout << "|||             [3] Display Hist Chart                 |||" << endl;
    cout << "|||             [4] Exit Application                   |||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    cout << endl;

    return;
}

void Menu::aMenu()
{

/*Menu loops until user enters 4 to exit the application*/
    system("Color 0D");
    bool gettingInput = true;
    //get input from user for menu choice
    int command;

    do {

        // check for valid input or throw bad input and clear the buffer
        try {
            Menu PMenuObject;
            PMenuObject.pMenu();
            std::cin >> command;
            cout << endl;

            while (std::cin.fail()) {

                std::cin.clear();
                std::cin.ignore(256, '\n');
                cout << "Invalid Choice. Please choose a valid menu option." << endl;
                continue;

            }
            if (5 < command <= 0) {

                throw (command); }
        }
        catch (...) {Menu PMenuObject;
            PMenuObject.pMenu();;}
        // call python function to print all social media stats for all outlets as a list
        if (command == 1) {


            cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "|||                DAILY SOCIAL MEDIA USE              |||"<< endl;
            cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << endl;

            Functions CallPObject;
            CallPObject.CallProcedure("SocialMediaList");
        }

        // getStats python function gets social media daily site visits for the desired site
        if (command == 2) {

            string userString;
            cout << "Enter a Social Media Outlet to get statistics: ";
            cout << endl;
            std::cin >> userString;
            cout << endl;

            cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "|||                 SOCIAL MEDIA LOOKUP                |||"<< endl;
            cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            Functions CallStrObject;
            int total = CallStrObject.callStrFunc("getStats", userString);

            if (total == 0)
            {
                cout << "Could not find '" << userString <<"'. Please check the spelling."<< endl;
            }
            else {
                cout << "Daily social media site visits: " << total << endl;
            }
        }

        // Python function call to getHistogram prints asterisks representing the number of visits per site
        if (command == 3) {

            cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "|||                 SOCIAL MEDIA CHART                 |||"<< endl;
            cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            Functions CallPObject;
            CallPObject.CallProcedure("getHistogram");
        }
        if (command == 4)
        {
            gettingInput = false;
        }

    } while (gettingInput == true);
    return;
}