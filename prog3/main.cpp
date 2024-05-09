#include "header.h"

int main() {
    Item inventory[20];  // Creating an instance of Item
    int num_of_items{0};
    print_welcome();
    menu(inventory, num_of_items);

    return 0;
}


void print_welcome()
{
    clear_screen();
    cout << "\n Welcome to Mona's Inventory Management Program \n";
    cout << "---------------------------------------------------\n";
}


void menu (Item inventory[], int& num_of_items)
{
    int choice{0};
    do
    {
        cout << "\n 1. Register a new item. \n 2. Print current inventory."
            << "\n 3. Search current inventory. \n 4. Save and quit. \n\n";  

        cout << " Enter your choice: ";
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


void clear_screen()
{
    cout << "\033[2J\033[H"; 
}


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
