
#ifndef DataReader_h
#define DataReader_h

#include "GlobalHeader.h"

class DataReader
{
public:
	map<string, float> dataIngredient;
	map<string, map<string, float>> ingredientNeedRecipies;
	map<string, float> priceRecipies;
		
	static DataReader* GetInstance();
	static void ReadingDataGame(string path[] = {});
	static void ReadDataRecipes(string path);
	static void ReadingDataIngredient(string path);
	static float ConvertStrToFloat(string price);

private:
	static DataReader* instance;
	DataReader();
};

#endif

