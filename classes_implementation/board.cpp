//
// Created by vlad on 16.06.20.
//
#include "../headers/board.h"
#include <iostream>

void Board::represent() {
    for ( int i = 0; i < height; i++ ){
        for ( int j = 0; j < width; j++ ){

            if ( cells[i * width + j] == '\0' ){
                std::cout << "|_|";
            } else {
                std::cout << '|' << cells[ i * width + j ] << '|';
            }

        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool Board::check_valid_turn(int row, int column) {
    bool result = row >= 0 && column >= 0;
    result &= row < height && column < width;
    if (result){
        return get_item(row, column) == '\0';
    }
    return false;
}

bool Board::make_turn(int row, int column, char player_symbol) {

    if ( !check_valid_turn(row, column) ){
        return false;
    }

    cells [row * width + column] = player_symbol;
    return true;
}

char Board::check_rows() {
    char result;
    bool only_one = true;

    for (int i = 0; i < height; i++){
        result = cells[i * width];

        for (int j = 0; j < width; j++ ){
            only_one &= result == cells[ i * width + j];
        }

        if (only_one && result != '\0'){
            return result;
        } else {
            only_one = true;
        }
    }
    return '\0';
}

char Board::check_columns() {
    char result;
    bool only_one = true;

    for (int i = 0; i < width; i++){
        result = cells[i];

        for (int j = 0; j < height; j++){
            only_one &= result == cells[ j * width + i ];
        }

        if (only_one && result != '\0'){
            return result;
        } else {
            only_one = true;
        }
    }
    return '\0';
}

char Board::check_diagonals() {
    char result = cells[0];
    bool only_one = true;

    for (int i = 0; i < height; i++){
            only_one &= result == cells[ i * width + i ];
    }

    if (only_one && result != '\0'){
        return result;
    }

    result = cells[ 2 * width ];
    only_one = true;

    for (int i = 0; i < height; i++){
        only_one &= result == cells[ i * width + width - i - 1 ];
    }

    if (only_one){
        return result;
    }
    return '\0';
}

char Board::check_winner() {
    if (check_rows() != '\0'){
        return check_rows();
    } else if (check_columns() != '\0'){
        return check_columns();
    } else if (check_diagonals() != '\0'){
        return check_diagonals();
    } else{
        return '\0';
    }
}

int Board::get_width(){
    return width;
}

int Board::get_height() {
    return height;
}

int Board::get_item(int row, int column) {
    return cells[ row * width + column ];
}

bool Board::check_draw() {
    for ( auto x: cells ){
        if ( x == '\0' ){
            return false;
        }
    }
    return true;
}