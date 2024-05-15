// File: Header.h
// Author: Simone Scheuer
// Date: May 4, 2024
// Description: Header file.

#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int welcome{1};
const int goodbye{2};
const int SEARCH{31};
const int NAME{31};
const int FRANCHISE{31};
const int DESCRIPTION{100};
const int COLOR{31};

struct Item
{
    char name[NAME] = "";
    char franchise[FRANCHISE] = "";
    char description[DESCRIPTION] = "";
    char color[COLOR] = "";
    int quantity = 0;
    bool sale = false;
    double price = 0.0;
};

void print_inventory(Item inventory[], int& num_of_items);// See menu_functions.cpp 
void menu(Item inventory[], int& num_of_items);// See main.cpp
void clear_screen(); // See main.cpp
void create_item(Item& an_item); // See menu_functions.cpp                                   
void search_inventory(Item inventory[], int& num_of_items); // See menu_functions.cpp
void print_item(Item inventory[], int& index); // See menu_functions.cpp
void print_message(int message_type); // See main.cpp
void clear_screen(); // See main.cpp
int load(Item inventory[]); // See file_handling.cpp
void save(Item inventory[], int num_of_items); // See file_handling.cpp
