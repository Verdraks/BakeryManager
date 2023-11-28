#include "Player.h"

float Player::GetMoney()
{
	return this->money;
}

void Player::BuyFurniture(float price)
{
	this->money -= price;
}

void Player::AddFurnitureInventory(string obj, const int quantity)
{
	if (this->inventory.find(obj) == this->inventory.end()){
		this->inventory[obj] = quantity;
	}
	else {
		this->inventory[obj] = this->inventory.at(obj) + quantity;
	}
}

void Player::RemoveFurnitureInventory(string obj, const int quantity)
{
	this->inventory[obj] = this->inventory.at(obj) - quantity;
}

bool Player::TryBuySmth(string obj,float price, int quantity)
{
	if (this->money >= quantity * price) {
		this->BuyFurniture(quantity * price);
		AddFurnitureInventory(obj, quantity);
		return true;
	}
	return false;
}

bool Player::CheckFurnitureRequired(map<string,int> recipe) {

	for (auto x : recipe)
	{
		if (this->inventory[x.first] < x.second) {
			return false;
		}
	}
	return true;
}

void Player::ShowInventory() {
	for (auto x : this->inventory)
	{
		cout << x.first << ':' << x.second << endl;
	}
}
