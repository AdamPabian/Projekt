#include <cstdlib>
#include <iostream>
#include <string>
#include "GameClass.h"

int main()
{
    srand(time(NULL));
    Game game;
    game.run();
    return 0;
}
