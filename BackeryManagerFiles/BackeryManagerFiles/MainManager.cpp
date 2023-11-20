#include "MainManager.h"
#include "DataReader.h"

MainManager::MainManager()
{
	srand(time(NULL));
	this->currentPriceIngredient = DataReader::GetInstance()->dataIngredient;
	this->player = *new Player();
	this->consoleManager = *new ConsoleManager;
}

void MainManager::ManageGame()
{
	do 
	{
		this->consoleManager.ShowConsole();
		//this->IncrementDay();
		this_thread::sleep_for(500ms);
	} while (!this->exitGame);
}

void MainManager::RefreshPrice()
{
	for (auto const x : DataReader::GetInstance()->dataIngredient) {
		this->currentPriceIngredient[x.first] = x.second * MainManager::CalculRandomPrice();
	}
}

void MainManager::IncrementDay()
{
	this->day += 1;
}

bool MainManager::CheckEndGame() {
	return this->player.GetMoney() <= 0;
}

float MainManager::CalculRandomPrice() {
	return 1 - (rand() % 10 - 5) / static_cast<float>(100);
}