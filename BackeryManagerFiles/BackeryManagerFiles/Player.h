#ifndef Player_h
#define Player_h

#include"GlobalHeader.h"

class Player
{
public:
	float GetMoney();
	bool TryBuySmth(string obj,float price, int quantity);

	bool CheckFurnitureRequired(map<string, int> recipe);

	void ShowInventory();

private:
	float money = 100;
	map <string, int> inventory;

	void BuyFurniture(float price);
	void AddFurnitureInventory(string obj, int quantity);

	void RemoveFurnitureInventory(string obj, const int quantity);

};
#endif
