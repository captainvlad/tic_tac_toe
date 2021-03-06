//
// Created by vlad on 17.06.20.
//

#include "../headers/game.h"
#include "../headers/human_player.h"
#include "../headers/ai_level_one_player.h"
#include "../headers/ai_level_two_player.h"

Game::Game(){
    welcome();
    offer_choose_player(0);
    offer_choose_player(1);

    Board b = Board();
    process_game();
}

void Game::welcome() {
    std::cout << "\nWelcome to the tic tac toe game, you are going to play with 'X'"
                 " symbols and your turn will be first\n";
}

void Game::offer_choose_player(int num_player) {
    int type_of_player = -1;
    char symbol = num_player == 0 ? 'X': 'O';

    while (true){
        std::cout << "Choose player you want to play as player " << num_player + 1 << ": 0 for human, 1 for level 1 AI, 2 for level 2 AI: ";
        std::cin >> type_of_player;
        if (type_of_player >= 0 && type_of_player <= 2 ){

            if (type_of_player == 0){
                players[num_player] = new HumanPlayer(symbol);
            } else if (type_of_player == 1){
                players[num_player] = new AI_level_one_player(symbol);
            } else if (type_of_player == 2){
                players[num_player] = new AI_level_two_player(symbol);
            }
            break;
        }

        std::cout << "\nNot correct number may be inserted. Try again\n";
    }
}

void Game::process_game(){

    b.represent();
    while ( true ){

        std::cout<<"Player 1 turns now\n";
        players[0]->take_turn(&b);
        b.represent();

        if ( b.check_winner() == 'X' ){
            std::cout << "Player 1 won!\n";
            break;
        } else if ( b.check_draw() ){
            std::cout << "Draw has been done!\n";
            break;
        }

        std::cout<<"Player 2 turns now\n";
        players[1]->take_turn(&b);
        b.represent();

        if ( b.check_winner() == 'O' ){
            std::cout << "Player 2 won!\n";
            break;
        } else if ( b.check_draw() ){
            std::cout << "The game ended in a draw!\n";
            break;
        }
    }
}