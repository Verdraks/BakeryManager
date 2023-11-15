#include "DataReader.h"
#include "Player.h"

int main(int argc, char* argv[])
{
    //DataReader::GetInstance()->ReadingDataGame();
    Player player = *new Player();
    player.TryBuySmth("riz", 10,1);
    player.ShowInventory();
    cout << player.CheckFurnitureRequired({ {"riz", 5},{"olive",5} });S

    /*if (argc == 2) {
        DataReader::GetInstance()->ReadingDataGame(argv[1]);
    }*/

    return 0;
}
