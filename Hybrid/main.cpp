/*
Shera Adams
*/
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include "Menu.h"
#include "Functions.h"

using namespace std;

int main()
{
    system("Color 09");

    Menu MenuObject;
    MenuObject.aMenu();

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|||                 Now Exiting Program                |||"<< endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    return 0;
}