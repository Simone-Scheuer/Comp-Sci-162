//Simone Scheuer - cs162 - prog2 - simones@pdx.edu - 5/21/24
//This program is a multiplayer game wherein one user enters a sentance, and a second user attempts to type the contents of that
//sentance after being shown it for a very short amount of time it then compares the phrases and determines the amount of matches.
//The program uses a single function to compare two phrases collected as arrays and a variety of other functions for input/ouput, screen clearing, continuing, etc.

#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

const int SIZE = 256;

void print_welcome();
void collect_input(char sentence[] );
void clear_screen();
void ready_to_go();
void timed_display(char sentence[], int time);
void compare_phrases(char phrase1[], char phrase2[], int& matches, int& words);
char collect_continue();

int main()
    // This is the main function that controls the game loop. It uses a loop to repeat the game, and has internal statements to control the dialogue.
{
    print_welcome();

    int attempts{1};// The amount of guess attempts the user has done.
    int match_count{0};// The amount of matches, established here, modified by compare_phrases.
    int word_count{0};// The amount of words, established here, modified by compare_phrases.
    char player1_phrase[SIZE] = {0};// Player ones phrase, the 'held' phrase that player2s is compared against.
    char player2_phrase[SIZE] = {0};// Player twos phrase, the 'compared' phrase that is entered second.
    int time{1}; // The time in seconds that the sentence is displayed for, modified as attempts increase.
    bool repeat_play = false; // A boolean tracking whether the game will repeat, modified upon failure.
    bool switch_player = true; // A boolean tracking the players, allowing them to be switched upon failure.
    char player1_name[SIZE]; // A char array containing player1s name, stored here to avoid having to loop through and 'swap'.
    char player2_name[SIZE]; //  A char array containing player1s name, stored here to avoid having to loop through and 'swap'.  
    char should_loop{'y'}; // A char storing the users choice to exit, allowing quitting functionality.
    float half_matches{0.0}; // A float to store the divided half of matches, as a float to handle edge cases.
    float half_words{0.0}; // A float to store the divided half of words, as a float to handle edge cases.

    // Collect player names and clear buffers and screen.
    cout << "Player 1 enter your name: ";
    cin.get(player1_name,SIZE,'\n');
    cin.ignore(256, '\n');  
    cout << "Player 2 enter your name: ";
    cin.get(player2_name,SIZE,'\n');
    cin.ignore(256, '\n');  
    clear_screen();

    // Initiate a loop to contain the core gameplay.
    while (should_loop == 'y')
    {
        // Reset time and repeating values for subsequent loops.
        time = 1;
        repeat_play = false;

        // Check which player is asking and print the correct name based on that.
        if (switch_player)
        {
            cout << "It's " << player1_name << "'s turn to write the starter sentence!\n";
        }
        else
        {
            cout << "It's " << player2_name << "'s turn to write the starter sentence!\n";
        }

        // Collect player1 phrase, clear the screen, get approval to continue. 
        collect_input(player1_phrase);
        clear_screen();
        ready_to_go();
        clear_screen();

        // Loop that controls counting attempts and giving messages based on number of tries.
        while(repeat_play == false)
        {
            if (attempts == 4)
            {
                cout << "SIKE! No more attempts! You stink at this! Switch players! \n \n";
                switch_player = !switch_player;
                repeat_play = true;
            }
            else
            {
                timed_display(player1_phrase, time);
                clear_screen();

                if (switch_player)
                {
                    cout << "It's " << player2_name << "'s turn to write their best approximation of the sentence!\n";        
                }
                else
                {
                    cout << "It's " << player1_name << "'s turn to write their best approximation of the sentence!\n";
                }

                collect_input(player2_phrase);
                compare_phrases(player1_phrase, player2_phrase, match_count, word_count);
                cout << "You matched " << match_count << " out of " << word_count << " words! \n\n";
                half_words = static_cast<float>(word_count) / 2;

                if (half_words <= match_count)
                {
                    cout << "Great job! Half or more right! Switch players! \n";
                    switch_player = !switch_player;
                    repeat_play = true;
                    time = 1;
                    attempts = 1;
                    half_words = 0;

                }

                else if (half_words > match_count)
                {
                    cout << "Not quite half right, " << attempts << "/3 attempts made, try again with a little more time!\n";
                    ready_to_go();
                    time ++;
                    attempts ++;
                    clear_screen();
                }

            }
        }
        should_loop = collect_continue();
        clear_screen();
    }
    cout << "\nBye! Bye! Thanks for playing!\n";
}


void print_welcome()
    // This function prints the formatted welcome message.
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
        << "         Welcome to Simone's spectacular memorization minigame!\n"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
        << "         The game needs two people, and is placed like this: \n\n"
        << "  1. Player one takes the computer and secrety writes a sentence. \n"
        << "     (ex: 'hello i love coding hello world on my new computer') \n\n"
        << "  2. The screen will clear and the computer gets passed to player two. \n\n"
        << "  3. Player two will type yes when they are ready to see the sentence. \n\n"
        << "  4. The sentance will be shown to player two for a very short time. \n\n"
        << "  5. Player two will enter their best approximation of the sentence. \n"
        << "     (ex: 'howdy i love combing baby birds on my new calculator') \n\n"
        << "  6. The computer will compare the two sentences, checking matches. \n\n"
        << "  7. If more than half match you win, otherwise you'll try again. \n"
        << "     (ex: 'You got 5 matches out of 10 words, nice job!' \n\n"
        << "  8. After player two wins, or fails two more times, swap players. \n\n"
        << "  9. You'll get the chance to quit after each game! have 'fun'! \n\n"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}


void collect_input(char sentence[])
    // This function intakes a char array and modifies it.
{
    cout << "\n >>> ";
    cin.get(sentence, SIZE, '\n');
    cin.ignore(256, '\n');
}


void clear_screen()
    // This function loops to output 100 newlines and fully clear the screen.
{
    for (int i = 0; i < 100; i++)
    {
        cout << '\n';
    }
}


void ready_to_go()
    // This function uses a while loop to error check if the user wants to continue.
{
    char yes = 'x';
    cout << "Enter 'y' when you are ready to see the sentence, once it dissapears you'll type your approximation: ";
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
    // This is the function that intakes time and a phrase and displays the phrase for the time given.
{
    cout << "3...\n";
    sleep(1);
    cout << "2...\n";
    sleep(1);
    cout << "1...\n";
    sleep(1);
    cout << "\n\n" <<  sentence << "\n\n";  
    sleep(time);
}


void compare_phrases(char phrase1[SIZE], char phrase2[SIZE], int& matches, int& words)
    // This is the titular comparing function that iterates through two char arrays simultaneously and compares them.
{
    char held_word[SIZE];
    char compared_word[SIZE];
    int held_index{0};
    int compared_index{0};
    int match_count{0};
    int phrase1_length = strlen(phrase1);
    int phrase2_length = strlen(phrase2);
    bool word_matched = false;
    int word_count = 0;

    // This is the begining of the nested loops that collect the first word in a sentance, and compares it to another array.
    for (int i = 0; i <= phrase1_length; i ++)
    {
        // Check if the current character is an alphabetic or an apostrophe.
        if (isalpha(phrase1[i]) || phrase1[i] == '\'')
        {
            // If it is, add it to the held word array and increase the held index, also lower it to handle case errors.
            phrase1[i] = tolower(phrase1[i]);
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
                word_count ++;

                // Start iterating over characters in phrase2.
                for (int j = 0; j <= phrase2_length && !word_matched; j++)
                {   
                    // Similar to above, if its valid...
                    if (isalpha(phrase2[j]) || phrase2[j] == '\'')
                    {
                        // Add it to the array, similarly lower each letter to handle case errors.
                        phrase2[j] = tolower(phrase2[j]);
                        compared_word[compared_index++] = phrase2[j];
                    }
                    // Otherwise, if its not valid, its time to end the word.
                    else if (phrase2[j] == ' ' || phrase2[j] == '\0' || !isalpha(phrase2[j]))
                    {
                        // Cut off the word and output debugging message.
                        compared_word[compared_index] = '\0';
                        // cout << "Comparing held word: [" << held_word << "] with compared word: [" << compared_word << "]\n";

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
    // Update the arguments with their relevant data pieces.
    matches = match_count;
    words = word_count;
}


char collect_continue()
    // A simple continue collection function.
{
    char y_or_n{};
    do 
    {
        cout << "\nEnter 'y' to play again or 'n' to exit: ";
        cin >> y_or_n;
        cin.ignore(100, '\n');
        y_or_n = tolower(y_or_n);
    }
    while (y_or_n != 'y' && y_or_n != 'n');
    return y_or_n;
}
