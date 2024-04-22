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

int compare_phrases(char phrase1[SIZE], char phrase2[SIZE]);

int main()
{
    print_welcome();

    char player1_phrase[SIZE] = {0};
    char player2_phrase[SIZE] = {0};
    int time{1};

    collect_input(player1_phrase);
    clear_screen();
    ready_to_go();
    timed_display(player1_phrase, time);
    clear_screen();
    collect_input(player2_phrase);
    int match_count = compare_phrases(player1_phrase, player2_phrase);
    cout << "you matched " << match_count << " words \n";
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
    cin.ignore(256, '\n');
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
    cin.ignore(256, '\n');
}


void timed_display(char sentence[SIZE], int time)
{
    cout << "\n\n" <<  sentence << "\n\n";  
    sleep(time);
}


int compare_phrases(char phrase1[SIZE], char phrase2[SIZE])
    // This is the titular comparing function that iterates through a char array, stops at whitespace, holds that found word, and then repeats the process for every word in the other array.
{
    char held_word[SIZE];
    char compared_word[SIZE];
    int held_index{0};
    int compared_index{0};
    int match_count{0};
    int phrase1_length = strlen(phrase1);
    int phrase2_length = strlen(phrase2);
    bool word_matched = false;

    // This is the begining of the nested loops that collect the first word in a sentance, compare it to every word in another sentence, and then move on to the next word and similarly compare it.
    for (int i = 0; i < phrase1_length; i ++)
    {
        // Check if the current character is an alphabetic or an apostrophe.
        if (isalpha(phrase1[i]) || phrase1[i] == '\'')
        {
            // If it is, add it to the held word array and increase the held index.
            held_word[held_index++] = phrase1[i];
        } 
        // If the character is a space, null, or not alphabetic, it indicates a word end.
        else if (phrase1[i] == ' ' || phrase1[i] == '\0' || !isalpha(phrase1[i])) 
        {
            // Cut off the held word.
            held_word[held_index] = '\0';

            // If a word is held...
            if (held_index > 0)
            {
                compared_word[0] = '\0';  
                compared_index = 0;       

                // Start iterating over characters in phrase2.
                for (int j = 0; j <= phrase2_length && !word_matched; j++)
                {   
                    // Similar to above, if its valid...
                    if (isalpha(phrase2[j]) || phrase2[j] == '\'')
                    {
                        // Add it to the array.
                        compared_word[compared_index++] = phrase2[j];
                    }
                    // Otherwise, if its not valid, its time to end the word.
                    else if (phrase2[j] == ' ' || phrase2[j] == '\0' || !isalpha(phrase2[j]))
                    {
                        // Cut off the word.
                        compared_word[compared_index] = '\0';
                        cout << "Comparing held word: [" << held_word << "] with compared word: [" << compared_word << "]\n";

                        // If a word was collected...
                        if (compared_index > 0)
                        {

                            // Compare the words to see if they match...
                            if (strcmp(held_word, compared_word) == 0)
                            {
                                // And iterate the match count.
                                match_count++;
                                word_matched = true;
                            }
                            // Reset the compared index to do another phrase2 word.
                            compared_word[0] = '\0';
                            compared_index = 0;
                        }
                    }
                }
                // Reset the held index to do another of the phrase1 word.
                held_word[0] = '\0';
                held_index = 0;
                word_matched = false;
            }
        }
    }

    return match_count;

}



