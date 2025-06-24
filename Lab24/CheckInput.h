#pragma once
#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

class CheckInput
{
public:
    bool isInt();

    bool isIntMin(int Val, int Min);

    bool isIntMax(int Val, int Max);

    bool isIntRange(int Val, int Min, int Max);

    bool StrIsNumb(string Str);

    bool StrIsBin(string Str);

    bool isDomino(string Str);

    bool isDominoFile(string Str);
};

