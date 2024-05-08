#include "header.h"
void print_item(Item inventory[], int& i);
void print_welcome();
void search_list();
void clear_screen();


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
    cin >> an_item.quantity;
    cin.ignore(100, '\n');

    cout << "\n Please enter item price: ";
    cin >> an_item.price;
    cin.ignore(100, '\n');

    cout << "\n Please enter item sale status (y/n): ";
    cin >> sale_status_indicator;
    cin.ignore(100, '\n');
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

void print_item(Item inventory[], int& i)
{
    cout << "\n Item " << (i + 1) << ":"
        << "\n Name: " << inventory[i].name
        << "\n Franchise: " << inventory[i].franchise
        << "\n Description: " << inventory[i].description
        << "\n Color: " << inventory[i].color
        << "\n Quantity: " << inventory[i].quantity
        << "\n Price: $" << inventory[i].price
        << "\n Sale: " << (inventory[i].sale ? "Yes" : "No") << "\n"
        << "-------------------------------------------------\n";
}
