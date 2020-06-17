//
// Created by vlad on 17.06.20.
//

#include "../headers/ai_level_one_player.h"
#include <vector>
#include <stdlib.h>

void AI_level_one_player::take_turn(class Board * b) {
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

    int chosen_x = empty_x_coordinates[chosen_coordinate];
    int chosen_y = empty_y_coordinates[chosen_coordinate];

    b->make_turn(chosen_x, chosen_y, get_player_sign());
}