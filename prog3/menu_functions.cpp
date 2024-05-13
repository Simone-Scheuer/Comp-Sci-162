#include "header.h"


//Function to read in a new item from the user, error check, and update the struct members.
void create_item(Item& an_item)
{
    char sale_status_indicator{'z'};
    bool is_valid = false;

    cout << "\n Please enter item name: ";
    cin.get(an_item.name, NAME, '\n');
    cin.ignore(100, '\n');

    cout << "\n Please enter item franchise: ";
    cin.get(an_item.franchise, FRANCHISE, '\n');
    cin.ignore(100, '\n'); 

    cout << "\n Please enter item description: ";
    cin.get(an_item.description, DESCRIPTION, '\n');
    cin.ignore(100, '\n'); 

    cout << "\n Please Enter item color(s): ";
    cin.get(an_item.color, COLOR, '\n');
    cin.ignore(100, '\n');

    cout << "\n Please enter item quantity: ";
    while (!(cin >> an_item.quantity))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cin.ignore(100, '\n');

    cout << "\n Please enter item price: ";
    while (!(cin >> an_item.price))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cin.ignore(100, '\n');

    cout << "\n Please enter item sale status (y/n): ";
    while (!is_valid)
    {
        cin >> sale_status_indicator;
        sale_status_indicator = tolower(sale_status_indicator);
        cin.ignore(100, '\n');
        if (sale_status_indicator == 'y' || sale_status_indicator == 'n')
        {
            is_valid = true; 
        }
        else
        {
            cout << "Invalid input. Please Enter 'y' for yes or 'n' for no: ";
        }
    }

    an_item.sale = (sale_status_indicator == 'y');
}


//Loops and repeatedly calls the print item function to print the whole inventory.
void print_inventory(Item inventory[], int& num_of_items)
{
    if (num_of_items == 0)
    {
        cout << "\n Zero items currently registered. \n";
    }
    cout << "-------------------------------------------------";                           
    for (int i{0}; i < num_of_items; i++)
    {
        print_item(inventory, i);
    }
}


//Preforms a linear search of the item inventory, finds matches for names, and prints their data if theyre found.
void search_inventory(Item inventory[], int& num_of_items)
{
    char search_term[SEARCH];
    cout << "\nEnter the item name to search: ";
    cin.get(search_term, SEARCH, '\n');
    cin.ignore(100, '\n'); 

    bool found = false;
    for (int i{0}; i < num_of_items; i++)
    {
        if (strcmp(search_term, inventory[i].name) == 0)
        {
            print_item(inventory, i);
            found = true;

        }
    }

    if (!found)
    {
        cout << "No items found with the name '" << search_term << "'.\n";
    }
}


//Prints the contents of a particular position in the struct array.
void print_item(Item inventory[], int& index)
{
    cout << "\n Item " << (index + 1) << ":"
        << "\n Name: " << inventory[index].name
        << "\n Franchise: " << inventory[index].franchise
        << "\n Description: " << inventory[index].description
        << "\n Color: " << inventory[index].color
        << "\n Quantity: " << inventory[index].quantity
        << "\n Price: $" << inventory[index].price
        << "\n Sale: " << (inventory[index].sale ? "Yes" : "No") << "\n"
        << "-------------------------------------------------";
}
