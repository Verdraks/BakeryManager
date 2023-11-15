#include "DataReader.h"

DataReader* DataReader::instance = NULL;

DataReader::DataReader(){}

DataReader* DataReader::GetInstance()
{
	if (DataReader::instance == NULL) {
		DataReader::instance = new DataReader();
	}
	return DataReader::instance;
}

void DataReader::ReadingDataGame(string path)
{
	if (DataReader::instance != NULL) {

		DataReader::instance->priceRecipies = map <string, float>();
		DataReader::instance->ingredientNeedRecipies = map <string, map<string, float>>();


		TiXmlDocument doc("D:\\Projects\\Programmation\\C++\\BakeryManager\\DatasRecipies.xml");
		if (!doc.LoadFile()) {
			cout << "Error, files not charged !";
		}
		else
		{
			TiXmlElement* currentRecipie = doc.RootElement()->FirstChildElement("Recipie");

			string tmpNameRecipie;
			float tmpPrice;

			string currentIngredient;
			float currentQuantity;
			map <string, float> tmpIngredients;

			while (currentRecipie != NULL)
			{
				tmpNameRecipie = currentRecipie->FirstChildElement("name")->GetText();
				tmpPrice = DataReader::ConvertStrToFloat(currentRecipie->FirstChildElement("cost")->GetText());

				cout << tmpNameRecipie << " | " << tmpPrice << endl;

				TiXmlElement* currentIngredientRecipie = currentRecipie->FirstChildElement("Ingredient");

				while (currentIngredientRecipie != NULL) {

					currentIngredient = currentIngredientRecipie->FirstChildElement("name")->GetText();
					currentQuantity = DataReader::ConvertStrToFloat(currentIngredientRecipie->FirstChildElement("quantity")->GetText());

					tmpIngredients[currentIngredient] = currentQuantity;//.insert(make_pair(currentIngredient, currentQuantity));

					cout << currentIngredient << " | " << currentQuantity << endl;


					currentIngredientRecipie = currentIngredientRecipie->NextSiblingElement("Ingredient");
				}

				DataReader::instance->priceRecipies[tmpNameRecipie] = tmpPrice; //.insert(make_pair(tmpNameRecipie,tmpPrice));
				DataReader::instance->ingredientNeedRecipies[tmpNameRecipie] = tmpIngredients; //.insert(make_pair(tmpNameRecipie, tmpIngredients));

				tmpIngredients.clear();

				currentRecipie = currentRecipie->NextSiblingElement("Recipie");
			}
		}
	}
}

float DataReader::ConvertStrToFloat(string price){
	return stof(price);
}
