/* This is the console executable, that makes use of the BullCow class
This acts as a view in a MVC pattern, and is responsible for 
all user interaction. For game logic see the FBullCowGame class.

*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void printInfo();
void playGame();
FText  getValidGuess();
void returnGuess(FText  guess);
bool askToPlay();
void callGameSummary();
FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
	do
	{
		printInfo();
		playGame();
	} 
	while (askToPlay());
	system("pause");
	return 0;
}

// loop for number of turns
void playGame()
{
	// TODO implement the method generating an isogram while also making sure max # of tries gets updated
	int32 maxTries = BCGame.getMaxTries();
	std::cout << "Maximum number of tries: " << maxTries << std::endl;
	int32 currentTry = BCGame.getCurrentTry();
	// loop asking for guesses until the game is NOT won
	// and there are still tries remaining
	FBullCowCount BullCowCount;
	while (!BCGame.isGameWon() && currentTry <= maxTries)
	{
		std::cout << "Try " << currentTry++ << " out of " << maxTries << " .";
		FText  guess = getValidGuess(); 

		BullCowCount = BCGame.submitValidGuess(guess);
		std::cout << "Bulls =" << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	callGameSummary();
	return;
}

// introduce the game
void printInfo()
{ 
	// TODO update the max # of tries depending on the length of the isogram
	std::cout << "Welcome to Bulls and Cows Game, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength() << " letter isogram I am thinking of?\n";
	std::cout << std::endl;
	
	return;
}


FText  getValidGuess()
{
	FText  guess = "";
	EGuessStatus Status = EGuessStatus::Invalid;
	do
	{
		std::cout << "Enter your guess: ";
		getline(std::cin, guess);

		Status = BCGame.checkGuessValidity(guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter only lowercase chars.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	return guess;
}

// return guess
void returnGuess(FText  guess)
{
	std::cout << "Your last guess was: " << guess << std::endl << std::endl;
	return;
}

bool askToPlay()
{ 
	BCGame.reset();
	std::cout << "Do you want to play again with the same hidden word?" << " yes/no\n";
	FText  response = "";
	getline(std::cin, response);
	std::cout << std::endl;
	if (putchar(tolower(response[0]) == 'y')) return true;
	else return false;
}
void callGameSummary()
{
	if (BCGame.isGameWon())
	{
		std::cout << "\nCongratulations, you WIN!!!\n\n";
	}
	else std::cout << "\nSorry, better luck next time.\n\n";
	return;
}


