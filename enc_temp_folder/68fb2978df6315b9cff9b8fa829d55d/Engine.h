#pragma once

class Engine
{
public :
	void run();
private:
	
	void start();
	void update();
	void end();

	int userInput(const char* discrption, const char** options);

private:
	int m_min = 1;
	int m_max = 101;
	int m_guess;

	int  m_user;

	bool m_shouldGameShouldEnd = false;
};

