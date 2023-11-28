#include "MainManager.h"
#include "DataReader.h"
#include "ConsoleManager.h"

MainManager* MainManager::instance = NULL;

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
		this->InteractionGame();
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
	int key = 0;
	switch (this->currentState)
	{
	case StateGame::Intro:
		while (key != 13) {
			key = _getch();
		}
		this->SwitchState();
		break;
	case StateGame::Buy:
		this->BuyState();
		break;
	case StateGame::Prepare:
		break;
	case StateGame::Sell:
		break;
	case StateGame::Recap:
		while (key != 13) {
			key = _getch();
		}
		this->IncrementDay();
		break;
	case StateGame::GameOver:
		while (key != 13) {
			key = _getch();
		}
		this->exitGame = true;
		break;
	}
}

void MainManager::BuyState() {
	int key = 0;
	bool finished = false;
	while (!finished) {
		int quantity = -1;
		auto tmpValues = this->currentPriceIngredient.begin();
		cout << "What's your choice : 1) Baking Powder, 2) Cheese, 3) Egg, 4)Floor, 5) Olive " << endl;
		key = _getch();

		switch (key) {
		case 38:

			this->CheckInput(&quantity,tmpValues,&finished,"Baking Powder");
			
			break;
		case 130:
			tmpValues++;
			this->CheckInput(&quantity, tmpValues, &finished,"Cheese");
			break;
		case 34:
			tmpValues++;
			this->CheckInput(&quantity, tmpValues, &finished,"Egg");
			break;
		case 39:
			tmpValues++;
			this->CheckInput(&quantity, tmpValues, &finished,"Floor");
			break;
		case 40:
			tmpValues++;
			this->CheckInput(&quantity, tmpValues, &finished,"Olive");
			break;
		default:
			break;
		}
	}
}

void MainManager::CheckInput(int *quantityInput, map<string,float>::iterator tmpValues,bool *finished, string elementChoice) {
	cout << "How many " << elementChoice << " do you want ?" << endl;
	*quantityInput = stoi(to_string(cin.get()));

	if (*quantityInput < 0) {
		cout << "Error Syntax !" << endl;
		this->CheckInput(quantityInput,tmpValues,finished, elementChoice);
	}
	else 
	{
		if (this->player.TryBuySmth(tmpValues->first, tmpValues->second, *quantityInput)) cout << "You have purchase" << tmpValues->first << " " << *quantityInput << endl; else cout << "You don't have enoght money !";

		cout << "Would you buy others things ? 0:No, 1:Yes" << endl;
		string tmp = to_string(cin.get());
		while (tmp != "0" || "1") {
			cout << "Error Syntax !" << endl;
			tmp = to_string(cin.get());
		}
		*finished = (tmp == "1");
	}
	


}

void MainManager::SetGameOver()
{
	this->currentState = StateGame::GameOver;
}

MainManager::StateGame MainManager::GetState()
{
	return this->currentState;
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