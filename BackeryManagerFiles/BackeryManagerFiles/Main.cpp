#include "DataReader.h"

int main(int argc, char* argv[])
{
    DataReader::ReadingDataGame();

    if (argc == 2) {
        DataReader::ReadingDataGame(argv[1]);
    }
    return 0;
}
