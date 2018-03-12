#include "game.h"

using namespace com::ding;

Game* game;

void initGame()
{
    game = new Game();
}

void quitGame()
{
    delete game;
}

int main(int argc, char const *argv[])
{
    initGame();
    AS3_GoAsync();
    quitGame();

    return 0;
}