#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void DisplayWelcomeMessage() {
  std::cout << "Welcome to this game of Rock, Paper, Scissors!" << std::endl;
  std::cout << "You face off aganist the computer for 3 rounds." << std::endl;
  std::cout << "First to 2 points wins." << std::endl;
  std::cout << "Please enter either: rock, paper, or scissors." << std::endl;
}

// Converts to text to lower case so that both uppercase and lowwercase text can be inputed
std::string ConvertToLowercase(std::string text) {
  for (int i = 0; i < static_cast<int>(text.size()); i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] = text[i] + 32;
    }
  }

  return text;
}

// Stores the players move
std::string GetPlayerChoice() {
  std::string move = "";

  while (true) {
    std::cout << "Choose rock, paper, or scissors: ";
    std::cin >> move;

    move = ConvertToLowercase(move);

    if (move == "rock" || move == "paper" || move == "scissors") {
      return move;
    }

    std::cout << "Invalid choice. Please type rock, paper, or scissors."
              << std::endl;
  }
}

// Generates a random move for the bot
std::string GenerateBotChoice() {
  int bot_move = rand() % 3;
  std::string bot_pick = "";

  if (bot_move == 0) {
    bot_pick = "rock";
  } else if (bot_move == 1) {
    bot_pick = "paper";
  } else {
    bot_pick = "scissors";
  }

  return bot_pick;
}

// Keeps track of the score and updates it depending on who won the round
void UpdateScore(const std::string& move, const std::string& bot_pick,
                 int& player_score, int& bot_score) {
  if (move == bot_pick) {
    player_score += 0;
    bot_score += 0;
  } else if ((move == "rock" && bot_pick == "scissors") ||
             (move == "paper" && bot_pick == "rock") ||
             (move == "scissors" && bot_pick == "paper")) {
    player_score++;
  } else {
    bot_score++;
  }
}

// Shows the result of the round
void DisplayRoundResult(const std::string& move, const std::string& bot_pick) {
  std::cout << "Bot chose: " << bot_pick << std::endl;

  if (move == bot_pick) {
    std::cout << "This round is a tie!" << std::endl;
  } else if ((move == "rock" && bot_pick == "scissors") ||
             (move == "paper" && bot_pick == "rock") ||
             (move == "scissors" && bot_pick == "paper")) {
    std::cout << "You win this round!" << std::endl;
  } else {
    std::cout << "Bot wins this round!" << std::endl;
  }
}


void DisplayScore(int player_score, int bot_score) {
  std::cout << "Player score: " << player_score << std::endl;
  std::cout << "Bot score: " << bot_score << std::endl;
}

// Shows the winner of the game
std::string GetWinner(int player_score, int bot_score) {
  if (player_score > bot_score) {
    return "Player";
  } else if (bot_score > player_score) {
    return "Bot";
  } else {
    return "Tie";
  }
}

void DisplayFinalResult(const std::string& winner) {
  if (winner == "Player") {
    std::cout << "You win!" << std::endl;
  } else if (winner == "Bot") {
    std::cout << "Bot wins!" << std::endl;
  } else {
    std::cout << "It's a tie!" << std::endl;
  }
}

// Generates the random number used to randomize the computers move
int main() {
  srand(time(0));

  int player_score = 0;
  int bot_score = 0;
  std::string move = "";
  std::string bot_pick = "";
  std::string winner = "";

  DisplayWelcomeMessage();

  for (int rounds = 0; rounds < 3; rounds++) {
    if (player_score >= 2) {
      winner = "Player";
      break;
    } else if (bot_score >= 2) {
      winner = "Bot";
      break;
    }

    std::cout << "\nRound " << rounds + 1 << std::endl;

    move = GetPlayerChoice();
    bot_pick = GenerateBotChoice();

    DisplayRoundResult(move, bot_pick);
    UpdateScore(move, bot_pick, player_score, bot_score);
    DisplayScore(player_score, bot_score);
  }

  if (winner == "") {
    winner = GetWinner(player_score, bot_score);
  }

  std::cout << std::endl;
  DisplayFinalResult(winner);

  return 0;
}