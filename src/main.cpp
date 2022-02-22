#include "Game.h"

int main()
{
    //Random
    srand(static_cast<unsigned int>(time(0)));

    //Inicializa o Jogo
    Game game;
    
    //Game Loop
    while (game.running())
        {
            game.update();
            game.render();
        }

    return 0;
}