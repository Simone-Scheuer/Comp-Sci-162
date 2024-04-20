//This is a demo from april 18th, cs162, Simone Scheuer, its meant to count characters in someones input.
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE = 121; //Max Phrase Size

//Prototypes
void welcome(); 
char input(char sentance[]); // Returns Character to search for
int count_match(char sentance[], char match);

int main()
{
    char phrase[SIZE]; //the sentance
    char match {'\0'}; //the character they want to match
    int count {0}; //number of matches
    welcome();
    match = input(phrase);
    count = count_match(phrase, match);
    cout << "the resulting number of matches is: "
        << count << endl;
    return 0;
}

//WELCOME THE USER AND DESCRIBE WHAT WILL HAPPEN
void welcome() //FUNCTION HEADER
{
    cout << "Welcome to our Matching Program" << endl;
    cout << "\nYou will enter a phrase and a character!"
         << "\nAnd we will count how often it appears!";
}
char input(char array[])
{
    char to_match {};

    cout << "please enter a phrase";
    cin.get(array, SIZE, '\n');
    cin.ignore(100, '\n');
    cout << "please enter a character to check for";
    cin >> to_match;
    cin.ignore(100, '\n');
    return to_match;
}

int count_match (char array[], char compare)
{
    int counter {0};
    size_t length = {strlen(array)};
    for (int i {0}; 1 < length; i++)
        if (array[i] == compare)
            ++ counter;
    return counter;
}
