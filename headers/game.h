//
// Created by vlad on 17.06.20.
//

#ifndef TIC_TAC_GAME_H
#define TIC_TAC_GAME_H

#include "player.h"

class Game {
public:
    Game();

    Player* players[2];
    Board b;

    void offer_choose_player(int num_player);
    void welcome();
    void process_game();
};
#endif //TIC_TAC_GAME_H
