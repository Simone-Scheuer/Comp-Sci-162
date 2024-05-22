#include "movie.h"

//data is titleTITLE infoINFO and stars


movie::movie()
{
    title = nullptr;
    info[0] = '\0';
    stars = 0;
    cout << "We just executed the movie constructor" << endl;
}


movie::~movie()
{
    if (title != nullptr)
        delete [] title;
    title = nullptr;
}


void movie::read()
{
    char temp[TITLE];
    cout << "Please enter a movie title: ";
    cin.get(temp, TITLE, '\n');
    cin.ignore(100, '\n');
    
    title = new char [ strlen(temp) + 1];
    strcpy(title, temp); 

    cout << "Please enter movie information: ";
    cin.get(info, INFO, '\n');
    cin.ignore(100,'\n');
    cout << "Please enter stars (1-5): ";
    cin >> stars;
    cin.ignore (100, '\n');
}


void movie::display()
{
    if (nullptr == title) return;
    cout << title << '\t' << info << endl << "# of stars: " << stars
         << endl;
}


bool movie::is_match(char matching_title[])
{
    if (nullptr == title) return false;
    return (strcmp(matching_title, title) == 0);
}


