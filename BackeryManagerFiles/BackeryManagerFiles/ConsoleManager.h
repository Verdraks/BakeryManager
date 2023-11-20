#ifndef ConsoleManager_h
#define ConsoleManager_h

#include "GlobalHeader.h"

class ConsoleManager
{
public:
	void SetGameOver();
	void SwitchState();
	void SelectText();
	void SelectTxtIntro();
	void SelectTxtBuy();
	void SelectTxtPrepare();
	void SelectTxtSell();
	void SelectTxtRecap();
	void SelectTxtGameOver();
	void ShowConsole();
	void WriteText();

	

private:
	vector<string> txts;
	enum StateGame
	{
		Intro,
		Buy,
		Prepare,
		Sell,
		Recap,
		GameOver,
	};
	
	
	StateGame currentState = StateGame::Intro;
	bool isWrittingStep = true;
};

#endif