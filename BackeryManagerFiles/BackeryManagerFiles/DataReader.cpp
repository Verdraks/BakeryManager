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

void DataReader::ReadingDataGame(string path[])
{
	if (path->size() < 2) {
		cout << "Not all files charged !" << endl;
	}
	if (DataReader::instance != NULL) {

		DataReader::instance->priceRecipies = map <string, float>();
		DataReader::instance->ingredientNeedRecipies = map <string, map<string, float>>();
		DataReader::instance->dataIngredient = map <string, float>();

		DataReader::ReadDataRecipes(path[0]);
		DataReader::ReadingDataIngredient(path[1]);

	}
	else {
		cout << "Error, instance not initialized!" << endl;
	}
}

void DataReader::ReadDataRecipes(string path){
	
	TiXmlDocument doc(path.c_str());

	if (!doc.LoadFile()) {
		cout << "Error, files not charged !" << endl;
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

			cout << "\n";
		}
	}
}
void DataReader::ReadingDataIngredient(string path){

	TiXmlDocument doc(path.c_str());

	if (!doc.LoadFile()) {
		cout << "Error, files not charged !" << endl;
	}
	else
	{
		TiXmlElement* currentIngredient = doc.RootElement()->FirstChildElement("Ingredient");

		string tmpNameIngredient;
		float tmpPrice;


		while (currentIngredient != NULL)
		{
			tmpNameIngredient = currentIngredient->FirstChildElement("name")->GetText();
			tmpPrice = DataReader::ConvertStrToFloat(currentIngredient->FirstChildElement("price")->GetText());
			

			cout << tmpNameIngredient << " | " << tmpPrice << endl;

			DataReader::instance->dataIngredient[tmpNameIngredient] = tmpPrice;

			currentIngredient = currentIngredient->NextSiblingElement("Ingredient");
		}
	}
}

float DataReader::ConvertStrToFloat(string price){
	return stof(price);
}
