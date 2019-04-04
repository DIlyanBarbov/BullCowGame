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
	
	
	void reset();		  
	FBullCowCount submitValidGuess(FString guess);
	FString generateIsogram(int);
	// ^^ please try ignore this and focus on the interface ^^
private:
	int32 myCurrentTry;
	FString myHiddenWord;
	bool bGameIsWon;

	bool isIsogram(FString guess) const;
	bool isLowercase(FString guess) const;
};