//
// Created by vlad on 17.06.20.
//

#ifndef TIC_TAC_PLAYER_H
#define TIC_TAC_PLAYER_H

#include "board.h"

class Player{
private:
    char my_sign;
public:
    Player(char character);
    char get_player_sign();
    virtual void take_turn(Board* b) = 0;
};

#endif //TIC_TAC_PLAYER_H
