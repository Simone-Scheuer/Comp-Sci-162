#include "movie_list.h"

list::list()
{   
    cout << "How many movies would you like to enter: ";
    cin >> size_of_array;
    cin.ignore(100, '\n');
    array = new movie[size_of_array];
    num_of_movies = 0;
}

void list::read_all()
{
    char response = 'y';
    while (tolower(response) == 'y' && num_of_movies < size_of_array)
    {
        array[num_of_movies].read();
        ++num_of_movies;
        cout << "Again? ";
        cin >> response;
        cin.ignore(100, '\n');
    }
}

void list::display_all()
{
    for (int i = 0; i < size_of_array; ++i)
            array[i].display();

}

list::~list()
{
    if (nullptr != array)
        delete [] array; 
    array = 0;
    size_of_array = 0;
    num_of_movies = 0;
}
