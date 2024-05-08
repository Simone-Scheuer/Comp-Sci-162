// File: Header.h
// Author: Simone Scheuer
// Date: May 4, 2024
// Description: Header file.
#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SEARCH{31};
const int NAME{31};
const int FRANCHISE{31};
const int DESCRIPTION{100};
const int COLOR{31};

struct Item
{
    char name[NAME];
    char franchise[FRANCHISE];
    char description[DESCRIPTION];
    char color[COLOR];
    int quantity;
    bool sale;
    double price;
};

void print_inventory(Item inventory[], int& num_of_items);
void menu(Item inventory[], int& num_of_items);
void clear_screen();
void create_item(Item& an_item);                                                         
void search_inventory(Item inventory[], int& num_of_items);
