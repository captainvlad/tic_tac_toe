cmake_minimum_required(VERSION 3.15)
project(tic_tac)

set(CMAKE_CXX_STANDARD 14)

add_executable(tic_tac main.cpp headers/board.h classes_implementation/board.cpp
        headers/player.h classes_implementation/player.cpp headers/human_player.h
        classes_implementation/human_player.cpp headers/ai_level_one_player.h
        classes_implementation/ai_level_one_player.cpp headers/ai_level_two_player.h
        classes_implementation/ai_level_two_player.cpp headers/game.h classes_implementation/game.cpp)