//
// Created by vlad on 17.06.20.
//

#include "../headers/human_player.h"

void HumanPlayer::take_turn(Board* b) {
    int row, column;
    while (true){
        std::cout << "Choose row you would like to put your sign to (0 stands for top one): ";
        std::cin >> row;

        std::cout << "Choose column you would like to put your sign to (0 stands for left one): ";
        std::cin >> column;

        row = row;
        if ( b->make_turn( row, column, get_player_sign() ) ){
            break;
        }
        std::cout << "Could not insert in the position, try once more\n";
    }
}