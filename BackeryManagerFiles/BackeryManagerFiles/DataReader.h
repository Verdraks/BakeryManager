#ifndef DataReader_h
#define DataReader_h

#include "GlobalHeader.h"

class DataReader
{
public:
	static map <string, float> dataIngredient;
	static map <string, map <string, int>> costIngredientRecipies;
	static map <string, float> priceRecipies;
	

	static void ReadingDataGame(string path);
};

#endif

