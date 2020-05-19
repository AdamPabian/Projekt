#include <cstdlib>
#include <iostream>
#include <string>
#include "GameClass.h"

int main()
{
    Game game;
    while (game.windowOpen()) {

            game.update();

            game.render();

    }
    return 0;
}
