#include "Engine.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Engine::run()
{

	start();

	while (!m_shouldGameShouldEnd) 
	{
		update();
	}

	end();
}

void Engine::start()
{
	srand(time(NULL));

	//Tell user to think of number within range
	std::cout << "Think of a number between 1 and 100" << std::endl;
	system("pause");
	system("cls");
}

void Engine::update()
{
	//Checks to see if the 
	if (m_min == m_max)
	{
		m_shouldGameShouldEnd = true;
		return;
	}

	//Random number within range 
	m_guess = rand() % (m_max - m_min)  + m_min;

	//Displays the guessed number to user
	std::cout << "Is it " << m_guess << " ?\n";

	//Displays users options 
	//If guess was closer to higher 
	std::cout << "1. Higher\n"

	//If guess was closer to Lower
	"2. Lower\n"

	//If the guess  was correct 
	"3. Correct" << std::endl;
	system("pause");

	//Takes user input
	std::cin >> m_user;


	//Checks if the users guess was close to 100
	if (m_user == 1)
		m_min = m_guess + 1;
	

	//Check if the users guess was closer to 1
	else if (m_user == 2)
		m_max = m_guess;
	
	//If the user agress the guess is correct
	else if (m_user == 3)
		m_shouldGameShouldEnd = true;

}

void Engine::end()
{
	system("cls");
	if (m_min == m_max)
		std::cout << "You Cheated!?" << std::endl;
	
	else 
		std::cout << "The Guessed Number is: "  << m_guess << std::endl;
	system("pause");
}

int Engine::userInput(const char* discrption, const char** options)
{

		std::cout << discrption << std::endl;

		for (int i = 0; i < sizeof(options); i++)
			std::cout << options[i] << std::endl;
		std::cin >> m_user;
	return m_user;
}
