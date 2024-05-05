// File: Header.h
// Author: Simone Scheuer
// Date: May 4, 2024
// Description: Header file.

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE{100};

struct Item
{
    char name[SIZE];
    char franchise[SIZE];
    char description[SIZE];
    char color[SIZE];
    int quantity;
    bool sale;
    double price;
};
