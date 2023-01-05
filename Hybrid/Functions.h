#ifndef HYBRID_FUNCTIONS_H
#define HYBRID_FUNCTIONS_H

#include "Menu.h"
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <cstring>

using namespace std;
class Functions {
public:
    int callIntFunc(string proc, int param);
    int callStrFunc(string proc, string param);
    void CallProcedure(string pName);
};

#endif HYBRID_FUNCTIONS_H
