// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
Game game;
std::string word;

void guess() {

    for (int i = 0; i < game.getSubjectLength(); i++)
    {
        std::cout << "_ ";
    }
    std::cout << std::endl;
    std::cout << "What is your guess?" << std::endl;

    std::cin >> word;

    if (word.length() > 1)
    {
        if (game.guess(word))
        {
            system("cls");
            std::cout << "Congratulations you guessed correctly!" << std::endl;
            new(&game) Game();
            std::cout << "Your next word is " << game.getSubjectLength() << " letters long" << std::endl;

            guess();
        }
        else
        {
            std::cout << "Sadly you guessed incorrect, please try again!" << std::endl;
            std::cout << "You have " << game.getRemainningGuesses() << " remaining" << std::endl;
            guess();
        }
    }
    else if (word.length() == 1) 
    {
        if (game.guessCharacter(word))
        {
            std::cout << "You guessed the character correctly" << std::endl;
        }
        else {
            std::cout << "Sadly you guessed incorrect, you have " << game.getRemainningGuesses() << " guesses left" << std::endl;
        }

        std::string subject = game.getGuessedSubject();

        std::cout << subject << std::endl;
        guess();
    }

    
}

int main()
{

    std::cout << "Welcome to Hangman!" << std::endl;

    std::cout << "Your first word is " << game.getSubjectLength() << " letters long" << std::endl;

    guess();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
