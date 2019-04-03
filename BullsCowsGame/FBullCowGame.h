#pragma once
#include <string>

using FString = std::string;
using int32 = int;
// all values initialised to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
public:
	FBullCowGame();

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	bool isGameWon() const;
	EGuessStatus checkGuessValidity(FString guess) const;

	void reset(); // TODO make a more rich return value			  
	FBullCowCount submitValidGuess(FString guess);
	// TODO provide a method generating an isogram with inputed number of characters
	//std::string generateIsogram(int32);
	// ^^ please try ignore this and focus on the interface ^^
private:
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
	bool bGameIsWon;
};