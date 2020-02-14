#pragma once
#include <string>
class Game
{
public:
	Game();
	bool guess(std::string word);
	std::string guessCharacter(std::string character);
	int getRemainningGuesses();
	int getSubjectLength();
private:
	std::string subjects[3] = { "Apple", "Pear", "Banana" };
	std::string subject;
	std::string guessedSubject;
	int remainingGuesses = 8;
};

