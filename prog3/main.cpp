#include "header.h"

int main() {
    Item myItem;  // Creating an instance of Item

    // Assigning values to the struct members
    strcpy(myItem.name, "Superhero Figurine");
    strcpy(myItem.franchise, "Marvel");
    strcpy(myItem.description, "A detailed figurine of Spider-Man.");
    strcpy(myItem.color, "Red and Blue");
    myItem.quantity = 50;
    myItem.sale = false;
    myItem.price = 29.99;

    // Output some information about the item
    cout << "Item: " << myItem.name << endl;
    cout << "Franchise: " << myItem.franchise << endl;
    cout << "Description: " << myItem.description << endl;
    cout << "Color: " << myItem.color << endl;
    cout << "Quantity: " << myItem.quantity << endl;
    cout << "On Sale: " << (myItem.sale ? "Yes" : "No") << endl;
    cout << "Price: $" << myItem.price << endl;

    return 0;
}

