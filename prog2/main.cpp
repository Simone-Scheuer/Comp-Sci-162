//Simone Scheuer - cs162 - prog2 - simones@pdx.edu - 5/21/24
//This program is a multiplayer game wherein one user enters a sentance, and a second user attempts to type the contents of that sentance after being shown it for a very short amount of time.
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

const int SIZE = 256;

void print_welcome();

void collect_input(char sentence[SIZE] );

void clear_screen();

void ready_to_go();

void timed_display(char sentence[SIZE], int time);

int main()
{
    print_welcome();

    char player1_phrase[SIZE];
    int time{1};

    collect_input(player1_phrase);
    clear_screen();
    ready_to_go();
    timed_display(player1_phrase, time);
    clear_screen();
}


void print_welcome()
{
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


void collect_input(char sentence[])
{
     cout << "please enter a phrase\n";
     cin.get(sentence, SIZE, '\n');
     cin.ignore(100, '\n');
}


void clear_screen()
{
     for (int i = 0; i < 100; i++)
     {
         cout << '\n';
     }
}

void ready_to_go()
{
    char yes = 'x';
    cout << "Enter 'y' when you are ready to continue: ";
    cin >> yes;
    yes = tolower(yes);
    while (yes != 'y')
    {
        cout << "Please enter 'y' when you are ready to continue: ";
        cin >> yes;
        yes = tolower(yes);
    }
}

void timed_display(char sentence[SIZE], int time)
{
    cout << "\n\n" <<  sentence << "\n\n";  
    sleep(time);
}
