//
// Created by vlad on 17.06.20.
//

#ifndef TIC_TAC_AI_LEVEL_TWO_PLAYER_H
#define TIC_TAC_AI_LEVEL_TWO_PLAYER_H

#include "player.h"

class AI_level_two_player: public Player{
    using Player::Player;
    using Player::get_player_sign;
public:
    int last_chosen_x = -1;
    int last_chosen_y = -1;

    int get_free_place_r(int row, Board *b);
    int get_free_place_c(int col, Board *b);

    void take_random_turn(Board *b);
    void take_turn(Board *b);
};
#endif //TIC_TAC_AI_LEVEL_TWO_PLAYER_H
