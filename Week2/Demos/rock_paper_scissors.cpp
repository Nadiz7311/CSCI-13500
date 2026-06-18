// 2 Players, 3 Rounds
// 1 point per win, 0 for tie or losing
// for loop, variables(rock,paper,scissors)
// ask player for move, then generate bot move
// who won, update score
// conditional, arritmatic, check who has more points

#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>

int main(){
    
    srand(time(0));

    // start game (declare variables)
  int player_score = 0;
    int bot_score    = 0;
    int bot_move     = 0;
    std::string move     = "";
    std::string bot_pick = "";
    std::string winner   = "";

    // game loop
    for (int rounds = 0; rounds < 3; rounds++) {

        // check for early winner
        if (player_score >= 2) {
            winner = "Player";
            break;
        }
        else if (bot_score >= 2) {
            winner = "Bot";
            break;
        }

        // ask for user input (with validation)
        while (true) {
            std::cout << "Choose rock, paper, or scissors: ";
            std::cin  >> move;

            // convert input to lowercase
            for (int i = 0; i < (int)move.size(); i++) {
                if (move[i] >= 'A' && move[i] <= 'Z') {
                    move[i] = move[i] + 32;
                }
            }

            if (move == "rock" || move == "paper" || move == "scissors") {
                break;
            }

            std::cout << "Invalid choice. Please type rock, paper, or scissors." << std::endl;
        }

        // generate bot input
        bot_move = rand() % 3;

        if (bot_move == 0) {
            bot_pick = "rock";
        }
        else if (bot_move == 1) {
            bot_pick = "paper";
        }
        else {
            bot_pick = "scissors";
        }

        // print bot move
        std::cout << "Bot chose: " << bot_pick << std::endl;

        // figure out the score
        if (move == bot_pick) {
            player_score += 0;
            bot_score    += 0;
        }
        else if ((move == "rock"     && bot_pick == "scissors") ||
                 (move == "paper"    && bot_pick == "rock")     ||
                 (move == "scissors" && bot_pick == "paper")) {
            player_score++;
        }
        else {
            bot_score++;
        }
    }

    // declare the winner
    if (winner == "") {
        if (player_score > bot_score) {
            winner = "Player";
        }
        else if (bot_score > player_score) {
            winner = "Bot";
        }
        else {
            winner = "Tie";
        }
    }

    if (winner == "Player") {
        std::cout << "You win!" << std::endl;
    }
    else if (winner == "Bot") {
        std::cout << "Bot wins!" << std::endl;
    }
    else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}