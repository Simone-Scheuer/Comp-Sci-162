#include "movie_list.h"

int main()
{
    /*
    char matching[31];
    movie scifi;
    cout << "Lets work with scifi: " <<endl;
    scifi.read();
    scifi.display();
    
    cout << "what movie would you like to look for: ";
    cin.get(matching, 31, '\n');
    cin.ignore(100, '\n');
    if (scifi.is_match(matching))
        cout << "Match!" << endl;
    else
        cout << "No Match!" << endl;

    movie drama;
    movie kids;
    return 0;
    */
    list scifi_library;
    scifi_library.read_all();
    scifi_library.display_all();

}
