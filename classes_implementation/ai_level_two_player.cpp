//
// Created by vlad on 17.06.20.
//

#include "../headers/ai_level_two_player.h"
#include <vector>
#include <stdlib.h>

void AI_level_two_player::take_turn(Board * b) {

    if (last_chosen_x != -1 && get_free_place_r(last_chosen_x, b) != -1){
        last_chosen_y = get_free_place_r(last_chosen_x, b);
        b->make_turn(last_chosen_x, last_chosen_y, get_player_sign() );

    } else if ( last_chosen_y != -1 && get_free_place_c(last_chosen_y, b) != -1 ){
        last_chosen_x = get_free_place_c(last_chosen_y, b);
        b->make_turn(last_chosen_x, last_chosen_y, get_player_sign());

    } else{
        take_random_turn(b);
    }
}

void AI_level_two_player::take_random_turn(Board *b){
    srand(time(NULL));
    std::vector<int> empty_x_coordinates;
    std::vector<int> empty_y_coordinates;

    for (int i = 0; i < b->get_height(); i++){
        for (int j = 0; j < b->get_width(); j++){
            if ( b->get_item(i, j) == '\0' ){
                empty_x_coordinates.emplace_back(i);
                empty_y_coordinates.emplace_back(j);
            }
        }
    }

    int chosen_coordinate = std::rand() % empty_x_coordinates.size();

    last_chosen_x= empty_x_coordinates[chosen_coordinate];
    last_chosen_y = empty_y_coordinates[chosen_coordinate];

    b->make_turn(last_chosen_x, last_chosen_y, get_player_sign() );
}

int AI_level_two_player::get_free_place_r(int row, Board *b){
    for (int i = 0; i < b->get_width(); i++ ){
        if ( b->get_item(row, i) == '\0' ){
            return i;
        }
    }
    return -1;
}

int AI_level_two_player::get_free_place_c(int col, Board * b) {
    for (int i = 0; i < b->get_height(); i++ ){
        if ( b->get_item(i, col) == '\0' ){
            return i;
        }
    }
    return -1;
}