#include "header.h"
//This file is the formatting file for program four, it holds functions that clear the screen and handle user input for style or error checking.
//Simone Scheuer
//Comp Sci 161

int integer_checker(int min, int max, char message[])
{
    int user_input;
    bool flag = true;
    cout << message;
    while (flag)
    {
        if (cin >> user_input)
        {
            if (user_input >= min && user_input <= max)
            {
                flag = false; // If input is valid and within range, return it
            }
            else
            {
                cout << "Please enter a valid integer between " << min << " and " << max << ": ";
            }
        }
        else
        {
            // If input fails (not an integer), clear the error and ignore the rest of the input
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Please enter a valid integer between " << min << " and " << max << ": ";
        }
    }
    return user_input;
}

void clear_screen()
{
    cout << "\033[2J\033[H"; 
}

void print_message(char message[])
{
    int message_length = strlen(message);
    row_of_tildas(message_length);
    cout << '\n' << message << '\n';
    row_of_tildas(message_length);
    cout << endl;
}

void row_of_tildas(int length)
{
    for (int i{0}; i<length; ++i)
    {
        cout << "~";
    }
}