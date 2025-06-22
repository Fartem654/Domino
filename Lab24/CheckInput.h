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

    bool isIntRange(int Val, int Min, int Max);

    bool StrIsNumb(string Str);

    bool StrIsBin(string Str);

    bool isDomino(string Str);

};

