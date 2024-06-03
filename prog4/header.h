//Header File for Program 4 
//Simone Scheuer
//5/20/24
//Header for Dynamic Memory Based Event Management System.

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE = 200;

class event //Single instance event class, holding all data parameters and single event handling methods.
{
    public:
        event();
        ~event();
        void read_event();
        void display_event();
        void compare_name(char check_name[SIZE]);

    private:
        char * name;
        char * description;
        char * start_date;
        char * end_date;
        double price;
        int stars;
        int attendence;
        bool twentyoneplus;
};


class event_list //Multi instance class object array handling class, holding meta data parameters and multi event handling methods.
{
    public:
        event_list();
        ~event_list();
        void read_all();
        void display_all();
        void search_event_list();

    private:
        event * array;
        int size_of_array;
        int num_of_events;
};


//Main.cpp functions
void menu(int & user_choice);

//Formatting.cpp functions
void clear_screen();
int integer_checker(int min, int max, char message[]);
void print_message(char message[]);
void row_of_tildas(int length);
