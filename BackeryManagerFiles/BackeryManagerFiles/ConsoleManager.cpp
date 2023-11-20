#include "ConsoleManager.h"
#include "MainManager.h"


ConsoleManager* ConsoleManager::GetInstance()
{
	if (ConsoleManager::instance == NULL) {
		ConsoleManager::instance = new ConsoleManager();
	}
	return ConsoleManager::instance;
}


void ConsoleManager::SelectText() {
	
	switch (MainManager::GetInstance()->GetState())
	{
	case MainManager::StateGame::Intro:
		this->SelectTxtIntro();
		break;
	case MainManager::StateGame::Buy:
		this->SelectTxtBuy();
		break;
	case MainManager::StateGame::Prepare:
		this->SelectTxtPrepare();
		break;
	case MainManager::StateGame::Sell:
		this->SelectTxtSell();
		break;
	case MainManager::StateGame::Recap:
		this->SelectTxtRecap();
		break;
	case MainManager::StateGame::GameOver:
		this->SelectTxtGameOver();
		break;
	}
}

void ConsoleManager::SelectTxtIntro() {
	this->txts = { "Hi guy and welcome to your new job ... BACKERY !","You have 3 things to do each days to run this buisness:","1) Buy ingredient to the market for create your recipes","2) Make meal of your card","3) Make people happy ! ", "That's all, good luck"};
	this->WriteText();
}

void ConsoleManager::SelectTxtBuy() {
	this->txts = { "vdsgdsg","fesfse" };
	this->WriteText();
}

void ConsoleManager::SelectTxtPrepare() {
	this->txts = { "vdsgdsg","fesfse" };
	this->WriteText();
}

void ConsoleManager::SelectTxtSell() {
	this->txts = { "vdsgdsg","fesfse" };
	this->WriteText();
}

void ConsoleManager::SelectTxtRecap() {
	this->txts = { "vdsgdsg","fesfse" };
	this->WriteText();
}
void ConsoleManager::SelectTxtGameOver() {
	this->txts = { "Oups, you have'nt enought money to run it, so i have to kill you to sell your organ..", ("Hey your finally dead, it's cool you survive " + to_string(MainManager::GetInstance()->GetDays()) + " days !"),"Be better next time !"};
	this->WriteText();
}


void ConsoleManager::ShowConsole()
{
	system("cls");
	//this->SelectText();
}

void ConsoleManager::WriteText()
{
	for (int i = 0; i < this->txts.size(); i++)
	{
		if (isWrittingStep) {
			for (int j = 0; j < this->txts[i].size(); j++) {
				cout << txts[i][j];
				this_thread::sleep_for(50ms);
			}
		}
		else {
			cout << txts[i];
		}
		cout << endl;
	}
	isWrittingStep = false;
}
