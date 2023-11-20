#ifndef ConsoleManager_h
#define ConsoleManager_h

#include "GlobalHeader.h"

class ConsoleManager
{
public:

	static ConsoleManager* GetInstance();

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
	static ConsoleManager* instance;
	ConsoleManager();

	vector<string> txts;
	bool isWrittingStep = true;

};

#endif