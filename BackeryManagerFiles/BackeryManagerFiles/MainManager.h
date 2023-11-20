#ifndef MainManager_h
#define MainManager_h

#include "GlobalHeader.h"
#include "Player.h"
#include "ConsoleManager.h"

class MainManager
{
public:
	map<string, float> currentPriceIngredient;

	void RefreshPrice();
	void ManageGame();
	
	MainManager();

	static float CalculRandomPrice();

private:
	Player player;
	ConsoleManager consoleManager;
	int day;
	bool exitGame = false;

	void IncrementDay();
	bool CheckEndGame();
	

};
#endif MainProgram_h

