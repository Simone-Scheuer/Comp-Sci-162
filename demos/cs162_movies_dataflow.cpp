#include <fstream>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// Simone Scheuer, practicing reading in structs and displaying and stuff.


const int TITLE = 31;
const int INFO = 131;
const int MOVIES = 10;


//struct
struct movie
{
    char title[TITLE];
    char info[INFO];
    int stars;
};

//prototypes


void read_movies(movie library[], int & num_of_movies);
void display_movies(movie library[], int num_of_movies);
void read_a_movie(movie & a_movie);
void display_a_movie(movie & one_movie);
int load(movie library[]);
void save(movie library[], int number_to_save);

int main()
{
    movie library[MOVIES];
    int num_of_movies = 0;
    num_of_movies = load(library);
    read_movies(library, num_of_movies);
    display_movies(library, num_of_movies);
    save(library, num_of_movies);
    return 0;
}


int load(movie library[])
{
    ifstream file_in;
    int i = 0;
    file_in.open("movie.txt");
    if (file_in)
    {
        file_in.get(library[0].title, TITLE, '~');
        file_in.ignore(100, '~');

        while (!file_in.eof() && i < MOVIES)
        {
            file_in.get(library[i].info, INFO, '~');
            file_in.ignore(100,'~');
            file_in >> library[i].stars;
            file_in.ignore(100, '\n');
            ++i;
            file_in.get(library[i].title, TITLE, '~');
            file_in.ignore(100,  '~');
        }
        file_in.close();
    }
    return i;
}

void save(movie library[], int num_to_save)
{
    ofstream file_out;
    file_out.open("movie.txt", ios::app);
    if (file_out)
    {
        for (int i = 0; i < num_to_save; ++i)
        {
            file_out << library[i].title << '~'
                     << library[i].info << '~'
                     << library[i].stars << endl;
        }
        file_out.close();
    }
}

void read_a_movie(movie & a_movie)
{
    cout << "Please enter the movie title: ";
    cin.get(a_movie.title, TITLE, '\n');
    cin.ignore(100, '\n');
    cout << "Enter info about the movie: ";
    cin.get(a_movie.info, INFO, '\n');
    cin.ignore(100, '\n');

    cout << "Enter number of stars (1-5): ";
    cin >> a_movie.stars;
    cin.ignore(100, '\n');

}


void display_a_movie(movie & one_movie)
{
    cout << one_movie.title <<endl
         << one_movie.info <<endl
         << "The number of stars is " << one_movie.stars << endl;
}


void read_movies(movie library[], int & num_of_movies)
{
    int i = num_of_movies;
    char response = 'n';
    cout << "Do you want to read in a new movie? ";
    cin >> response;
    cin.ignore(100, '\n');

    while ('Y' == toupper(response))
    {
        read_a_movie(library[i]);
        cout << "Another? ";
        cin >> response;
        cin.ignore(100, '\n');
        ++i;
    }
    num_of_movies = i;
}


void display_movies(movie library[], int num_of_movies)
{
    for (int i = 0; i < num_of_movies; ++i)
    {
        display_a_movie(library[i]);
    }
}
