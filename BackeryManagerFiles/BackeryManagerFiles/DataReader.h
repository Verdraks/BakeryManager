#ifndef DataReader_h
#define DataReader_h

#include "GlobalHeader.h"

class DataReader
{
public:
	static map<string, float> dataIngredient;
	static map<string, map<string, float>> ingredientNeedRecipies;
	static map<string, float> priceRecipies;
	static void ReadingDataGame(string path = "");
	static float ConvertStrToFloat(string price);
};

#endif

