// #includes
// #constants
// #structures
// #class interfaces
// #prototypes

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int TITLE = 31;
const int INFO = 131;

class movie
{
    public:
        movie();
        ~movie();
        void read();
        void display();
        bool is_match(char matching_title[]);
    private:
        char * title;
        char info[INFO];
        int stars;
};


