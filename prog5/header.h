//Header File For Program 5
//Simone Scheuer - CS162

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 256;

struct Clue
{
    char * question;
    char * hint;
    char * answer;
    int difficulty; 
};

struct Node
{
    Clue clue;
    Node * next;
};

Node* create_node(const char* question, const char* hint, const char* answer, int difficulty);
void delete_node(Node* node);
Node* populate_node();
void append_node(Node** head);
void display_list(Node * head);

//Formatting Functions
int check_integer(int min, int max, char message[]);
void clear_screen();
void print_message(char message[]);
void row_of_tildas(int length);

void question_answering(Node** head);
void make_clues(Node** head, int& clue_number);  
void menu(int & user_choice);
