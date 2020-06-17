//
// Created by vlad on 16.06.20.
//

#ifndef TIC_TAC_BOARD_H
#define TIC_TAC_BOARD_H

#include <iostream>

class Board {

private:
    static const int height = 3;
    static const int width = 3;
    char cells[height * width]{'\0'};

public:
    void represent();
    bool check_valid_turn(int row, int column);

    bool make_turn(int row, int column, char player_symbol);
    char check_rows();

    char check_columns();
    char check_diagonals();

    char check_winner();
    bool check_draw();

    int get_width();
    int get_height();
    int get_item(int row, int column);
};

#endif //TIC_TAC_BOARD_H
