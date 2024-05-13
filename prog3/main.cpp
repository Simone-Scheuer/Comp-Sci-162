#include "header.h"

//Main function to intialize struct array and the counter variable and call the menu.
int main() {
    Item inventory[20];  // Creating an instance of Item
    int num_of_items{0};
    print_welcome();
    menu(inventory, num_of_items);

    return 0;
}

//Uber simple function to clear the screen and print the title.
void print_welcome()
{
    clear_screen();
    cout << "\n Welcome to Mona's Inventory Management Program \n";
    cout << "---------------------------------------------------\n";
}

//Menu function to act as an looping choice tree and call the other functions.
void menu (Item inventory[], int& num_of_items)
{
    int choice{0};
    do
    {
        cout << "\n 1. Register a new item. \n 2. Print current inventory."
             << "\n 3. Search current inventory. \n 4. Save and quit. \n\n"
             << " Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << " Invalid choice. Please enter 1-4. \n";
            continue;
        }
        cin.ignore(100, '\n');
        if (choice < 1 || choice > 4)
        {
            clear_screen();
            cout << " Invalid choice. Please enter 1-4. \n";
        }

        else if (choice == 1)
        {
            clear_screen();
            create_item(inventory[num_of_items]);
            clear_screen();
            num_of_items++;
        }
        else if (choice == 2)
        {
            clear_screen();
            print_inventory(inventory, num_of_items);
        }
        else if (choice == 3)
        {
            clear_screen();
            search_inventory(inventory, num_of_items);
        }
    } while (choice != 4); 
}


//Cosmetic function to clear the screen, called after every function in menu.
void clear_screen()
{
    cout << "\033[2J\033[H"; 
}



