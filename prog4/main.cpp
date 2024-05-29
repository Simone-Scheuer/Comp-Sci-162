#include "header.h"
//Program 4 Main file
//Simone Scheuer
//20/5/24
//This file contains the main function for this program, calling to the other classes and files.


int main() // Main: Intitializes the dynamic object array, and default variables, and then uses a switch case to control the main functionalities.
{
    clear_screen();
    char welcome[] = "Welcome to Mona's Event Planning Program!";
    print_message(welcome);
    event_list my_events;  
    clear_screen();
    int user_choice{0};

    do{
        menu(user_choice);
        clear_screen();
        switch(user_choice)
        {
            case 1:
                clear_screen();
                my_events.read_all();
                break;
            case 2:
                clear_screen();
                my_events.display_all();
                break;
            case 3:
                clear_screen();
                my_events.search_event_list();
                break;
            case 4:
                clear_screen();
                char goodbye[] = "Thanks for using Mona's Event Planning Program!";
                print_message(goodbye);
                break;
        }

    } while (user_choice != 4);
}


void menu(int & user_choice) // Menu Function: Displays the menu and handles the user input.
{
   cout << "\nMENU" << endl
        << "~~~~~~~~~~~~~~~~~" <<endl
        << "1. Enter Events" << endl
        << "2. Display Events" << endl
        << "3. Search Events" << endl
        << "4. Quit Program" << endl
        << "~~~~~~~~~~~~~~~~~" <<endl;

    char menu_message[] = "Enter Choice: ";
    int min = 1;
    int max = 4;
    user_choice = integer_checker(min,max,menu_message);
    cin.ignore(100, '\n');
}
