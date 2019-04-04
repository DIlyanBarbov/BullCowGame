#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	reset();
}



void FBullCowGame::reset()
{
	const FString hiddenWord = "tiger";
	myHiddenWord = hiddenWord;
	myCurrentTry = 1;
	constexpr int32 maxTries = 5;
	myMaxTries = maxTries;
	return;
}

int FBullCowGame::getMaxTries() const
{
	return myMaxTries;
}

int FBullCowGame::getCurrentTry() const
{
	return myCurrentTry;
}

int32 FBullCowGame::getHiddenWordLength() const
{
	int32 hiddenWordLength = myHiddenWord.length();
	return hiddenWordLength;
}

bool FBullCowGame::isIsogram(FString guess) const
{
	// treat 0 and 1 letter words as isograms
	if (guess.length() <= 1) { return true; }
	TMap<char, bool> letterSeen; // setup our map
	
	for (auto letter : guess)// for all letters in the word
	{
		if (letterSeen[letter])// if the letter is in the map
		{
			return false;// we do NOT have an isogram
		} // otherwise
		else letterSeen[letter] = true; // add the letter to the map as seen	
	}
}

bool FBullCowGame::isLowercase(FString guess) const
{
	if (guess.length() <= 1) { return true; }
	for (auto letter : guess) // for every letter in the guess
	{
		
		if (islower(letter)) return true;
		else return false;
	}
}

bool FBullCowGame::isGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString guess) const
{
	if (!isIsogram(guess)) // if the guess isn't an isogram 
	{
		return EGuessStatus::Not_Isogram; 
	}
	else if (!isLowercase(guess)) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length()!= getHiddenWordLength())  // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}
// receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::submitValidGuess(FString guess)
{
	// increment a turn number
	myCurrentTry++;
	// setup a return structure
	FBullCowCount bullCowCount;
	// loop through all letters in a guess
	int32 hiddenWordLength = myHiddenWord.length();
	// compare letters against the hidden word
	for (int32 mhwChar = 0; mhwChar < hiddenWordLength; mhwChar++)
	{
		for (int32 gChar = 0; gChar < hiddenWordLength; gChar++)
		{
			if ((guess[gChar] == myHiddenWord[mhwChar])) // if they match
			{
				if (mhwChar == gChar) bullCowCount.Bulls++; // in the same place, increment bulls
				else bullCowCount.Cows++; // if not then cows
			}
		}
	}
	if (bullCowCount.Bulls == hiddenWordLength) bGameIsWon = true;
	else bGameIsWon = false;
	return bullCowCount;
}


/*std::string FBullCowGame::generateIsogram(int)
{
	return std::string();
}
*/
