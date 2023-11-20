#include "ConsoleManager.h"

void ConsoleManager::SetGameOver()
{
	this->currentState = StateGame::GameOver;
}

void ConsoleManager::SwitchState()
{
	switch (this->currentState)
	{
	case StateGame::Intro:
		this->currentState = StateGame::Buy;
		break;
	case StateGame::Buy:
		this->currentState = StateGame::Prepare;
		break;
	case StateGame::Prepare:
		this->currentState = StateGame::Sell;
		break;
	case StateGame::Sell:
		this->currentState = StateGame::Recap;
		break;
	case StateGame::Recap:
		this->currentState = StateGame::Buy;
		break;
	case StateGame::GameOver:
		break;
	}
	this->isWrittingStep = true;
}

void ConsoleManager::SelectText() {
	
	switch (this->currentState)
	{
	case StateGame::Intro:
		this->SelectTxtIntro();
		break;
	case StateGame::Buy:
		this->SelectTxtBuy();
		break;
	case StateGame::Prepare:
		this->SelectTxtPrepare();
		break;
	case StateGame::Sell:
		this->SelectTxtSell();
		break;
	case StateGame::Recap:
		this->SelectTxtRecap();
		break;
	case StateGame::GameOver:
		this->SelectTxtGameOver();
		break;
	}
}

void ConsoleManager::SelectTxtIntro() {
	this->txts = { "vdsgdsg","fesfse" };
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
	this->txts = { "vdsgdsg","fesfse" };
	this->WriteText();
}


void ConsoleManager::ShowConsole()
{
	system("cls");
	this->SelectText();
}

void ConsoleManager::WriteText()
{
	for (int i = 0; i < this->txts.size(); i++)
	{
		if (isWrittingStep) {
			for (int j = 0; j < this->txts[i].size(); j++) {
				cout << txts[i][j];
				this_thread::sleep_for(150ms);
			}
		}
		else {
			cout << txts[i];
		}
		cout << endl;
	}
	isWrittingStep = false;
}
