#ifndef MainManager_h
#define MainManager_h

#include "GlobalHeader.h"
#include "Player.h"

class MainManager
{
public:

	map<string, float> currentPriceIngredient;

	enum StateGame
	{
		Intro,
		Buy,
		Prepare,
		Sell,
		Recap,
		GameOver,
	};

	
	void RefreshPrice();
	void ManageGame();
	void InteractionGame();
	void SwitchState();
	int GetDays();

	MainManager::StateGame GetState();

	static MainManager* GetInstance();
	static float CalculRandomPrice();

private:

	static MainManager* instance;
	MainManager();

	StateGame currentState = StateGame::Intro;

	Player player;
	int day;
	bool exitGame = false;

	bool CheckEndGame();
	void IncrementDay();
	void SetGameOver();

};
#endif MainProgram_h

