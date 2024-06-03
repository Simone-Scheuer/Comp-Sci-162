#include "header.h"
//Event.cpp File for program 4
//Simone Scheuer
//20/5/24
//This file contains the implementation for the Event class, the first half of the event list
//Class pair who work together to create a dynamically sized array of events.


event::event() // Constructor: initializes the event class object private members to zero or null values.
{
    name = nullptr;
    description = nullptr;
    start_date = nullptr;
    end_date = nullptr;
    price = 0.0;
    stars = 0;
    attendence = 0;
    twentyoneplus = false;
}


event::~event() // Deconstructor: deallocates dynamically allocated data, and deletes it.
{
    if (name != nullptr)
        delete [] name;
    name = nullptr;
    if (description != nullptr)
        delete [] description;
    description = nullptr;
    if (start_date != nullptr)
        delete [] start_date;
    start_date = nullptr;
    if (end_date != nullptr)
        delete [] end_date;
    end_date = nullptr;
}

void event::read_event() // Event Reading Function: Reads in and populates a class object, uses dynamic memory allocation and temp vars to populate char arrays dynamically.
{
    char temp_name[SIZE];
    char temp_desc[SIZE];
    char temp_start[SIZE];
    char temp_end[SIZE];
    char temp_char = 'z';
    int min_price{0}, max_price{99999};
    int min_stars{0}, max_stars{5};
    int min_attend{0}, max_attend{9999999};

    cout << "Please enter the event name: ";
    cin.get(temp_name, SIZE, '\n');
    cin.ignore(100, '\n');
    name = new char [strlen(temp_name) + 1];
    strcpy(name, temp_name);

    cout << "Please enter a brief description: ";
    cin.get(temp_desc, SIZE, '\n');
    cin.ignore(100, '\n');
    description = new char [strlen(temp_desc) + 1];
    strcpy(description, temp_desc);
        
    cout << "Please enter the start date (DD/MM/YY): ";
    cin.get(temp_start, SIZE, '\n');
    cin.ignore(100, '\n');
    start_date = new char [strlen(temp_start) + 1];
    strcpy(start_date, temp_start);

    cout << "Please enter the end date (DD/MM/YY):  ";
    cin.get(temp_end, SIZE, '\n');
    cin.ignore(100, '\n');
    end_date = new char [strlen(temp_end) + 1];
    strcpy(end_date, temp_end);
    
    char price_message[] = "Please enter the price of admission: $";
    price = integer_checker(min_price, max_price, price_message); 

    char star_message[] = "Please enter the star rating (1-5): ";
    stars = integer_checker(min_stars, max_stars, star_message);
    
    char attend_message[] = "Please enter the expected attendence: ";
    attendence = integer_checker(min_attend, max_attend, attend_message);

    cout << "Is the event 21+ (y/n): ";
    cin >> temp_char;
    twentyoneplus = (temp_char == 'y');
    cin.ignore(100, '\n');
}


void event::display_event() // Display Object Function: Displays a particular event object and all its members.
{
    if (nullptr == name) return;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << "Event Name: " << name << endl
         << "Description: " << description  << endl
         << "Dates: " <<start_date << " to " << end_date << endl
         << "Price of Admission: $ " << price << endl
         << "User Star Rating: " << stars << "/5" << endl
         << "Expected Attendence: " << attendence << endl;
         if (twentyoneplus)
             cout << "The event is 21+" << endl;
         else
             cout << "The event is not 21+" << endl;
}


void event::compare_name(char check_name[]) // Compare Name Function: Compares a name to its argument and displays it if a match is found.
{
   if (strcmp(check_name, name) == 0)
   {
       display_event();
   }
   else
   {
       cout <<"\bNo matches found for " << check_name << ".\n";
   }
}

