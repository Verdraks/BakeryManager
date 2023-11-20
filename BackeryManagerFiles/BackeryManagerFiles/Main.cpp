#include "DataReader.h"
#include "Player.h"
#include "MainManager.h"
#include <conio.h>

int main(/*int argc, char* argv[]*/)
{
    string paths[] = { "F:\\Projects\\Programmation\\C++\\BakeryManager\\DatasRecipies.xml","F:\\Projects\\Programmation\\C++\\BakeryManager\\DatasIngredients.xml"};

    DataReader::GetInstance()->ReadingDataGame(paths);
    MainManager::GetInstance();//->ManageGame();

    /*while (true) {
        auto c = _getch();
        cout << c << endl;
    }*/

    /*Player player = *new Player();
    player.TryBuySmth("riz", 10,1);
    player.ShowInventory();
    std::cout << player.CheckFurnitureRequired({ {"riz", 5},{"olive",5} });*/

    /*if (argc == 2) {
        DataReader::GetInstance()->ReadingDataGame(argv[1]);
    }*/

    return 0;
}
