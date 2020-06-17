//
// Created by vlad on 17.06.20.
//

#ifndef TIC_TAC_HUMAN_PLAYER_H
#define TIC_TAC_HUMAN_PLAYER_H

#include "player.h"

class HumanPlayer: public Player{
    using Player::Player;
    using Player::get_player_sign;
public:
    void take_turn(Board *b);
};
#endif //TIC_TAC_HUMAN_PLAYER_H
