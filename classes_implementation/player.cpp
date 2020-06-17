//
// Created by vlad on 17.06.20.
//

#include "../headers/player.h"

Player::Player(char character){
    my_sign = character;
}

char Player::get_player_sign() {
    return my_sign;
}