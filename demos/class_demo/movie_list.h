#include "movie.h"

const int MOVIES = 10;

class list
{
    public:
        list();
        ~list();
        void read_all();
        void display_all();

    private:
        movie * array;

        int size_of_array;
        int num_of_movies;
};
