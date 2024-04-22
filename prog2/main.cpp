//Simone Scheuer - cs162 - prog2 - simones@pdx.edu - 5/21/24
//This program is a multiplayer game wherein one user enters a sentance, and a second user attempts to type the contents of that sentance after being shown it for a very short amount of time.
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;


void print_welcome();

int main() {
    print_welcome();
}

void print_welcome() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
         << "         Welcome to Simone's spectacular memorization minigame!\n"
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
         << "         The game needs two people, and is placed like this: \n\n"
         << "  1. Player one takes the computer and secrety writes a sentence \n"
         << "     (ex: 'hello i love coding hello world on my new computer') \n\n"
         << "  2. The screen will clear and the computer gets passed to player two \n\n"
         << "  3. Player two will type yes when they are ready to see the sentance \n\n"
         << "  4. The sentance will be shown to player two for a very short time \n\n"
         << "  5. Player two will enter their best approximation of the sentance \n"
         << "     (ex: 'howdy i love combing baby birds on my new calculator') \n\n"
         << "  6. The computer will compare the two sentances if any words match \n\n"
         << "  7. If more than half match you win, otherwise youll try again \n"
         << "     (ex: 'You got 5 matches out of 10 words, nice job!' \n\n"
         << "  8. After player two wins, or fails two more times, swap players \n\n"
         << "  9. The game can be played back and forth forever! have 'fun'! \n\n"
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
