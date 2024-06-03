#include "header.h"
//Event List class function for program 4
//Simone Scheuer
//20/5/24
//This file contains the functions for the event_list class, that make use of the entire array of
//events, such as reading or displaying all of them and constructing and deconstructing the
//dynamic array.


event_list::event_list() // Constructor: initializes the dynamic memory class object array, while error checking it for size.
{
    char dynamic_memory_message[] =  "How many events would you like to store? ";
    int min_event{0};
    int max_event{99999};
    size_of_array = integer_checker(min_event,max_event,dynamic_memory_message);
    cin.ignore(100, '\n');
    array = new event[size_of_array];
    num_of_events = 0;
}


event_list::~event_list() // Deconstructor: Deallocates the dynamic class object array and nulls the data members.
{
    if (nullptr != array)
        delete [] array;
    array = 0;
    size_of_array = 0;
    num_of_events = 0;
}


void event_list::read_all() // Read In Repeatedly Function: Checks the fullness of the event array, and then repeatedly calls the read in function until the user exits or the array is filled.
{
    char response = 'y';
    if (num_of_events >= size_of_array)
    {
        cout << "\nEvent array is full, you should have allocated more dynamic memory you fool!\n";
    }
    while (tolower(response) == 'y' && num_of_events < size_of_array)
    {
        array[num_of_events].read_event();
        ++num_of_events;
        if (num_of_events < size_of_array)
        {
            cout << "Again? ";
            cin >> response;
            cin.ignore(100, '\n');
        }
    }
}


void event_list::display_all() // Display All Function: Repeatedly calls the display function for each index of the num of events.
{
    if (num_of_events  == 0)
    {
        cout << "\nNo events to display currently.\n";
    }
    else
    {
    for (int i{0}; i < num_of_events; ++i)
       array[i].display_event();
    }
}


void event_list::search_event_list() // Search Function: Intakes a char array to compare to names of events and calls the compare name function at each one.
{
    if (num_of_events == 0)
    {
        cout << "\nNo events to search for currently.\n";
    }
    else
    {
    char check_name[SIZE];
    cout << "\nEnter an event name to search for: ";
    cin.get(check_name, 100, '\n');
    cin.ignore(100, '\n');
    for (int i{0}; i < num_of_events; i++)
        array[i].compare_name(check_name);
    }
}
