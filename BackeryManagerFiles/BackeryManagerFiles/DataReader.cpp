#include "DataReader.h"

void DataReader::ReadingDataGame(string path)
{
	TiXmlDocument doc("users.xml");
	if (!doc.LoadFile()) {
		cout << "Error, files not charged !";
	}
	else {
		TiXmlElement* currentBook = doc.RootElement()->FirstChildElement("book");
		vector<string> books;
		int i = 0;
		while (currentBook != NULL)
		{
			string result = currentBook->FirstChildElement("title")->GetText();
			books.push_back(result);
			cout << books[i] << endl;

			i++;
			currentBook = currentBook->NextSiblingElement("book");
	}


}
