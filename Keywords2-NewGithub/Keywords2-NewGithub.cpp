// Keywords2.cpp : Defines the entry point for the console application.
//Test commit

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
//srand(static_cast<unsigned int>(time(0)));//<cstdlib> function for random <ctime> for seeding time
#include <string>
#include <vector>
#include <algorithm>
//random_shuffle(words.begin(), words.end());//<algorithm> library function
#include <cctype>



using namespace std;
void Hangman(string userName, int difficulty);

int main()
{
	//program init values
	//int MAX_WRONG = 8; //Maximum Number of incorrect Guesses

	// Display Title of program to user
	cout << "Welcom to Keywords CIA Training program" << endl;

	// Ask the recruit to login using thier name
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cout << "Please enter your last name: " << endl;
	string user_name;
	cin >> user_name;

	int difficulty;
	cout << "\n\nPlease select your difficulty setting!" << endl;
	cout << "1.) Easy      12" << endl;
	cout << "2.) Medium     8" << endl;
	cout << "3.) Medium     4" << endl;
	cin >> difficulty;

	// Create an int var to count the number of simulations being run starting at 1
	int simulations = 1;
	// Display the simulation # is staring to the recruit. 
	bool playagain = false;
	do
	{
		while (simulations < 4)
		{
			cout << "Simulation " << simulations << " starts Now!  Good luck recruit " << user_name << "!";
			Hangman(user_name, difficulty);
			simulations++;
		}
		cout << "Would you like to play another round." << endl;
		string play_again = "";
		cin >> play_again;
		if (play_again=="Y" || play_again=="y")
		{
			Hangman(user_name, difficulty);
			playagain = true;
		}
		else
		{
			playagain = false;
		}
	} while (playagain);

	cout << "Keyword CIA Training simulation complete." << endl;
	// Ask the recruit if they would like to run the simulation again

	// If the recruit wants to run the simulation again

	//     Increment the number of simiulations ran counter

	//     Move program execution back up to // Display the simulation # is staring to the recruit. 

	// Otherwise 

	//     Display End of Simulations to the recruit

	//     Pause the Simulation with press any key to continue
	system("pause");
	return 0;
}
void Hangman(string userName, int difficulty)
{

	int MAX_WRONG = difficulty;

	switch (difficulty)
	{
	case 1: MAX_WRONG = 12;
		break;
	case 2: MAX_WRONG = 8;
		break;
	case 3: MAX_WRONG = 4;
		break;
	default: cout << "\nYou have entered an invalid selection, try again." << endl;
		break;
	}
	// Create a collection of 10 words you had wrote down manually
	vector<string> words; //collection of possible words to guess
	words.push_back("ALPHA");
	words.push_back("BRAVO");
	words.push_back("CHARLIE");
	words.push_back("DELTA");
	words.push_back("ECHO");
	words.push_back("WHISKEY");
	words.push_back("TANGO");
	words.push_back("FOXTROT");
	words.push_back("ZULU");
	words.push_back("XRAY");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";

	cout << "Welcome to Keyword CIA Assessment training. Good Luck\n";
	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		// Display an overview of what Keywords II is to the recruit 

		// Display an directions to the recruit on how to use Keywords
		cout << "\n\nRecruit " << userName << " You Have " << (MAX_WRONG - wrong);
		//     Tell recruit how many incorrect guesses he or she has left
		cout << " incorrect guesses left.\n\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		//     Show recruit the letters he or she has guessed
		cout << "\nSo far, the word is :\n" << soFar << endl;
		//     Show player how much of the secret word he or she has guessed

		char guess;
		cout << "\n\nEnter your guess recruit " << userName << ": ";
		cin >> guess;
		//     Get recruit's next gues

		guess = toupper(guess); //Make Uppercase since secret word is uppercase
		



//     While recruit has entered a letter that he or she has already guessed

//          Get recruit ’s guess

		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "\n\nEnter your guess recruit " << userName << ": ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "\nCongratulations Recruit " << userName << "!\n" << guess << " is in the word.\n";
			//update soFar to include newly guess letter
			//     Add the new guess to the group of used letters
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				//     If the guess is in the secret word

				//          Tell the recruit the guess is correct

				//          Update the word guessed so far with the new letter
				if (THE_WORD[i] == guess)
				{

					soFar[i] = guess;
				}
			}
		}

		//     Otherwise

		//          Tell the recruit the guess is incorrect

		//          Increment the number of incorrect guesses the recruit has made
		else
		{
			cout << "\nIncorrect, " << guess << " isn't in the word.\n You're failure is being analyzed Recruit " << userName << ".";
			++wrong;
		}
	}
	//shut down
	// If the recruit has made too many incorrect guesses

	//     Tell the recruit that he or she has failed the Keywords II course.
	if (wrong == MAX_WRONG)
	{
		cout << "\nYou have failed you're assessment Recruit " << userName << "!";
	}
	else
	{
		cout << "\nCongratulations Recruit " << userName << "!";
	}
	cout << "\n\nThe word was " << THE_WORD << "\n\nYou may continue to the next phase of training." << endl;
	// Otherwise

	//     Congratulate the recruit on guessing the secret words

}

































