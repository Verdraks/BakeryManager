#include "MainManager.h"
#include "DataReader.h"
#include "ConsoleManager.h"

MainManager::MainManager()
{
	srand(time(NULL));
	this->currentPriceIngredient = DataReader::GetInstance()->dataIngredient;
	ConsoleManager::GetInstance();
	this->player = *new Player();
}

MainManager* MainManager::GetInstance()
{
	if (MainManager::instance == NULL) {
		MainManager::instance = new MainManager();
	}
	return MainManager::instance;
}

void MainManager::ManageGame()
{
	do 
	{
		ConsoleManager::GetInstance()->ShowConsole();
		//this->IncrementDay();
		this_thread::sleep_for(100ms);
	} while (!this->exitGame);
}

void MainManager::SwitchState()
{
	switch (MainManager::GetInstance()->GetState())
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
}

void MainManager::InteractionGame() {
	switch (this->currentState)
	{
	case StateGame::Intro:
		break;
	case StateGame::Buy:
		break;
	case StateGame::Prepare:
		break;
	case StateGame::Sell:
		break;
	case StateGame::Recap:
		break;
	case StateGame::GameOver:
		break;
	}
}

void MainManager::SetGameOver()
{
	this->currentState = StateGame::GameOver;
}

MainManager::StateGame MainManager::GetState()
{
	return MainManager::StateGame();
}

void MainManager::RefreshPrice()
{
	for (auto const x : DataReader::GetInstance()->dataIngredient) {
		this->currentPriceIngredient[x.first] = x.second * MainManager::CalculRandomPrice();
	}
}

int MainManager::GetDays() {
	return this->day;
}

void MainManager::IncrementDay()
{
	this->day += 1;
}

bool MainManager::CheckEndGame() {
	return this->player.GetMoney() <= 0;
}

float MainManager::CalculRandomPrice() {
	return 1 - (rand() % 11 -5) / static_cast<float>(100);
}