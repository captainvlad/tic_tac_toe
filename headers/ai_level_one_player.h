//
// Created by vlad on 17.06.20.
//

#include "player.h"

#ifndef TIC_TAC_AI_LEVEL_ONE_PLAYER_H
#define TIC_TAC_AI_LEVEL_ONE_PLAYER_H

class AI_level_one_player: public Player{
    using Player::Player;
    using Player::get_player_sign;
public:
    void take_turn(Board *b);
};
#endif //TIC_TAC_AI_LEVEL_ONE_PLAYER_H
