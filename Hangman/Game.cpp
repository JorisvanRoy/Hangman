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

std::string Game::guessCharacter(std::string character)
{
	std::string subj;
	char letter = character[0];
	for (int i = 0; i < subject.length(); i++)
	{
		if (subject[i] == letter) {
			guessedSubject[i] = subject[i];
		}
	}
	return guessedSubject;
}

int Game::getRemainningGuesses()
{
	return remainingGuesses;
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
