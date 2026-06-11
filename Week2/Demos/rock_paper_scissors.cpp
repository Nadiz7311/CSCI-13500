// 2 Players, 3 Rounds
// 1 point per win, 0 for tie or losing
// for loop, variables(rock,paper,scissors)
// ask player for move, then generate bot move
// who won, update score
// conditional, arritmatic, check who has more points

#include <iostream>
#include <random>

int main(){
    
    // start game (declare variables)
    int player_score = 0;
    int bot_score = 0;
    std::string move = "";
    int bot_move = 0;
    std::string bot_pick = "";
    std::string winner = "";
    

    // game loop
    for (int rounds = 0; rounds < 3; rounds++){

        //check for early winner
        if(player_score >= 2){
            winner = "Player";
            break;
        }
        else if (bot_score >= 2){
            winner = "Bot"
            break;
        }

        // ask for user input
        std::cout << "Chose rock, paper, or scissor: ";
        std::cin >> move;

        // generate bot input
        bot_move = rand() % 3;

        if (bot_move == 0){
            bot_pick = "Rock";
        }
        else if (bot_move == 1){
            bot_pick = "Paper";
        }
        else{
            bot_pick = "Scissor";
        }

        // figure out the score

        if(player_score == bot_pick){
            player_score +- 0;
            bot_score +- 0;
        }
        else if (player_move == "Rock" && bot_pick == "Scissor"){
            player_score += 1;
        }
        else if (player_move == "Paper" && bot_pick == "Rock"){
            player_score++;
        }
        else if (player == "Scissor" && bot_pick == "Paper"){
            player_score++;
        }
        else{
            bot_score++;
        }
    }

    // declare the winner
    if(player_score > bot_score){
        std::cout <<
    }
}