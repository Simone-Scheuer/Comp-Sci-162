#include "header.h"
//Main file for linear linked list clue hunt program.
//Simone Scheuer - CS162

int main()
{
    char welcome[] = "Welcome to Mona's Linear Linked List Puzzle Treasure Hunt!";
    print_message(welcome);    
    Node* head = nullptr;
    int user_choice{0};
    int clue_number{1};

    do{
        menu(user_choice);
        clear_screen();
        switch(user_choice)
        {
            case 1:
                clear_screen();
                make_clues(&head, clue_number);
                break;
            case 2:
                clear_screen();
                if (head == nullptr)
                {
                    cout << "You havent entered any clues yet silly!\n";
                    break;
                }
                question_answering(&head);
                break;
            case 3:
                clear_screen();
                char goodbye[] = "Thanks for using Mona's Clue Hunt Program!";
                print_message(goodbye);
                break;
        }
    } while (user_choice != 3);
}


void menu(int & user_choice) // Menu Function: Displays the menu and handles the user input.
{
    cout << "\nMENU" << endl
        << "~~~~~~~~~~~~~~~~~" <<endl
        << "1. Enter Clues" << endl
        << "2. Begin Hunt" << endl
        << "3. Quit Program" << endl
        << "~~~~~~~~~~~~~~~~~" <<endl;

    char menu_message[] = "Enter Choice: ";
    int min = 1;
    int max = 3;
    user_choice = check_integer(min,max,menu_message);
    cin.ignore(100, '\n');
}


void question_answering(Node** head)
{
    Node * current = *head;
    char user_input[SIZE];
    int riddle_number{1};
    while (current != nullptr)
    {
        do
        {
            cout << "Riddle #" << riddle_number << ": " << current->clue.question;
            cout << "\n\nEnter your guess or type 'clue' for a clue: ";
            cin.get(user_input, SIZE, '\n');
            cin.ignore(100, '\n');

            if (strcmp(user_input, "clue") == 0)
            {
                cout << '\n' << current->clue.hint;
            }

            else if (strcmp(user_input, current->clue.answer) == 0 )
            {
                clear_screen();
                cout << "Great Job! You Got It!\n\n";
                current = current->next;
                ++riddle_number;
            }
            else 
            {
                clear_screen();
                cout << "\nNot Quite! Try Again!";
            }
        } while (current != nullptr && strcmp(user_input, current->clue.answer) != 0);
    }
}


void make_clues(Node** head,int& clue_number)
{
    char user_input = 'y';
    do
    {
        cout << "Clue #" << clue_number << '\n';
        append_node(head);
        cout << "\nAnother? (y/n): ";
        cin >> user_input;
        cin.ignore(100, '\n');
        ++clue_number;
        clear_screen();
    } 
    while(user_input == 'y');
}


