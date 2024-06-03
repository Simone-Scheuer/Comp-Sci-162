#include "header.h"
//This file contains the linear linked list components of program 5.
//Simone Scheuer - CS162

Node * create_node(const char* question, const char* hint, const char* answer, int difficulty)
{
    Node * new_node = new Node;

    new_node -> clue.question = new char[strlen(question) + 1];
    strcpy(new_node->clue.question, question);

    new_node -> clue.hint = new char[strlen(hint) + 1];
    strcpy(new_node->clue.hint, hint);

    new_node -> clue.answer = new char[strlen(answer) + 1];
    strcpy(new_node->clue.answer, answer);

    new_node -> clue.difficulty = difficulty;

    new_node -> next = nullptr;
    return new_node;
}

Node * populate_node()
{
    char question[SIZE];
    char hint[SIZE];
    char answer[SIZE];
    int difficulty;

    cout << "\nEnter a question for the clue: ";
    cin.get(question, SIZE, '\n');
    cin.ignore(100, '\n');
    cout << "\nEnter a hint for the clue: ";
    cin.get(hint, SIZE, '\n');
    cin.ignore(100, '\n');
    cout << "\nEnter an answer for the clue: ";
    cin.get(answer, SIZE, '\n');
    cin.ignore(100, '\n');
    char difficulty_message[] =  "\nEnter a difficulty for the clue (1-100): ";
    difficulty = check_integer(1,100,difficulty_message);
    cin.ignore(100, '\n');
    
    return create_node(question, hint, answer, difficulty); 
}


void append_node(Node ** head)
{
    Node * new_node = populate_node();
    if (*head == nullptr)
    {
        *head = new_node;
    } 
    else
    {
        Node * last_node = *head;
        while (last_node -> next != nullptr)
        {
            last_node = last_node -> next;
        }

        last_node -> next = new_node;

    }
}

void display_list(Node* head)
{
    Node * current = head;
    while (current != nullptr)
    {
        cout << "Question: " << current->clue.question << endl;
        cout << "Hint: " << current->clue.hint << endl;
        cout << "Answer: " << current->clue.answer << endl;
        cout << "Difficulty: " << current->clue.difficulty << endl;
        current = current->next;
    }
}

void delete_node(Node* node) 
{
    delete[] node->clue.question;
    delete[] node->clue.hint;
    delete[] node->clue.answer;
    delete node;
}

