#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

bool Game::guess(std::string word)
{
	if (subject != word)
	{
		remainingGuesses--;
		return false;
	}
	return true;
}

bool Game::guessCharacter(std::string character)
{
	std::string subj;
	char letter = character[0];
	bool found = false;
	for (int i = 0; i < subject.length(); i++)
	{
		if (subject[i] == letter) {
			guessedSubject[i] = subject[i];
			found = true;
		}
	}
	if (!found) remainingGuesses--;

	return found;
}

int Game::getRemainningGuesses()
{
	return remainingGuesses;
}

std::string Game::getGuessedSubject()
{
	return guessedSubject;
}

int Game::getSubjectLength()
{
	return subject.length();
}

Game::Game()
{
	srand((unsigned)time(NULL));
	int index = rand();
	subject = subjects[index % 3];
	for (int i = 0; i < subject.length(); i++)
	{
		guessedSubject += "_";
	}
}
