#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	reset();
}

void FBullCowGame::reset()
{
	const FString hiddenWord = "ants";
	myHiddenWord = hiddenWord;
	myCurrentTry = 1;
	constexpr int32 maxTries = 8;
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

bool FBullCowGame::isGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString guess) const
{
	if (false) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; // TODO write function
	}
	else if (false) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase; //TODO write function 
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
