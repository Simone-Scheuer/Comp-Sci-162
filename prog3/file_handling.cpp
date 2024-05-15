#include "header.h"
// File: file_handling.cpp
// Author: Simone Scheuer
// Date: May 4, 2024
// Description: File storing load and save functions for handling external files..


// Loading function that reads into a text file and populates a structure array based on sequences of data members and tildas. 
int load(Item inventory[])
{
    ifstream file_in;
    int index = 0;
    file_in.open("inventory.txt");
    if (file_in)
    {
        file_in.get(inventory[index].name, NAME, '~');
        file_in.ignore(100, '~');

        while(index < 20 && !file_in.eof())
        {
            file_in.get(inventory[index].franchise, FRANCHISE, '~');
            file_in.ignore(100, '~');
            file_in.get(inventory[index].description, DESCRIPTION, '~');
            file_in.ignore(100, '~');
            file_in.get(inventory[index].color, COLOR, '~');
            file_in.ignore(100, '~');
            file_in >> inventory[index].quantity;
            file_in.ignore(100, '~');
            char saleStatus[10];
            file_in.getline(saleStatus, 10);
            inventory[index].sale = (strcmp(saleStatus, "true") == 0);
            file_in >> inventory[index].price;
            file_in.ignore(100, '\n');                  
            ++index;
            file_in.get(inventory[index].name, NAME, '~');
            file_in.ignore(100, '~');
        }
    }
    file_in.close();
    return index;

}


// Saving function that copies the contents of a structure array to a text file, overwriting the text file.
void save(Item inventory[], int num_of_items)
{
    ofstream file_out;
    file_out.open("inventory.txt");
    if (file_out)
    {
        for (int i{0}; i < num_of_items; i++)
        {
            file_out << inventory[i].name << '~'
                << inventory[i].franchise << '~'
                << inventory[i].description << '~'
                << inventory[i].color << '~'
                << inventory[i].quantity << '~'
                << (inventory[i].sale ? "true" : "false") << '~'
                << inventory[i].price << '\n';
        }
    }
    file_out.close();
}

