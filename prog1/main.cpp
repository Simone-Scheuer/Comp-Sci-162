//Simone Scheuer - CS162 - Program1
//This program is designed to preform a mathematics quiz game, players will answer multipication addition and subtraction problems using numbers one through twenty.
//The program randomly generates questions and allows two inputs before a 'life' is subtracted, the program intentionally excludes questions with negative answers.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	//seed random generation, and preset all variables to avoid bugs.	
	srand(time(0));
	int question_number = 0, number_range = 0;
	int player_answer = 0;
	int player_life = 5, num1 = 0, num2 = 0;
	int operator_choice = 0, correct_answer = 0;
	int game_score = 0, num_questions = 0;
	int start_command = 0, temp_var = 0, attempts = 0;
	bool answered_correctly = false;
	char operator_symbol;

	//print formatted welcome messsage.
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< "		Welcome to my math quiz!		\n"
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< "  You will be asked to solve simple arithmetic problems!\n"
		<< "	You'll have two chances for each problem,\n"
		<< "      But if you fail twice, you'll lose a life!\n"
		<< "  You begin with 5 lives and if you run out- Game Over!\n"
		<< "                Example: 5 + 7 = ?\n"
		<< "                  Your Answer: 12\n"
		<< "No answers will be negative, so enter -1 to exit anytime!\n" 
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< "Enter a positive number to be your max!\n"
		<< "Ex: Enter 20 for equations with numbers 0-20!\n"
		<< "Enter range: ";
	cin  >> number_range; 	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<<"Enter 1 to begin! \n";

	//create a loop to handle start command, error check, and allow for exit. 
	cout << "Enter here:  ";
	cin >> start_command;

	while (start_command != 1 && start_command != -1) {
		cout << "Please enter 1 to begin or -1 to quit!\n";
		cout << "Enter: ";
		cin >> start_command;
	}

	if (start_command == -1) {
		cout << "Why'd you even try and play in the first place bozo?\n";
		return 0;
	}

	//initialize question generation loop when player is living, generate random values, select operator, calculate correct answer.
	while (player_life > 0) {

		question_number += 1;
		//reset special variables each loop.
		attempts = 0;
		player_answer = 0;

		num1 = rand() % number_range;
		num2 = rand() % number_range;
		operator_choice = rand() % 3;

		if (operator_choice == 0) {
			correct_answer = num1 + num2;
			operator_symbol = '+';

		} else if (operator_choice == 1) {
			correct_answer = num1 - num2;
			operator_symbol = '-';
			//if the result is negative swap num1 and num2 to avoid negatives.
			if (correct_answer < 0) {
				temp_var = num1;
				num1 = num2;
				num2 = temp_var;
				correct_answer = num1 - num2;
				operator_symbol = '-';
			}

		} else if (operator_choice == 2) {
			correct_answer = num1 * num2;
			operator_symbol = '*';
		}

		answered_correctly = false;

		//initialize question answering loop while player has lives, the answer is not correct, and the player is not exiting.
		while (attempts < 2 && !answered_correctly && player_answer != -1) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
				<< "What is " << num1 << " " << operator_symbol << " " << num2 << "?\n"
				<< "Your Answer: ";
			cin >> player_answer;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";


			if (player_answer == -1)
			{
				cout << "Exiting the game! Thanks for playing!\n"
					<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				return 0;
			}

			if ( player_answer == correct_answer) {
				cout << "Correct! Good Job!\n"
					<< "Current lives: " << player_life << "/5\n";

				if (attempts == 0) {
					game_score += 2;
				} else {
					game_score +=1;
				}

				answered_correctly = true;

			} else {
				attempts ++;
				if (attempts == 2)  { 
					cout << "Wrong again! lose a life! The correct answer was: " << correct_answer << ".\n";
					player_life --;
					cout << "Current lives: " << player_life << "/5\n";

				} else { 
					cout << "Wrong answer, try again!:\n"
						<< "Attempts remaining: 1\n";

				}	
			}
		}
	}

	//verify valid game-over and print score	
	if (player_life == 0)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Game Over! Your score was: "  << game_score  << ".  You answered " << question_number << " Questions! \n\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
	return 0;

}
