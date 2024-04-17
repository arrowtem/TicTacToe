#pragma once

#include "../Player/Player.h"
#include "../TicTacToe/TicTacToe.h"
#include <memory>
#include <string>

class GameManager {
public:
    GameManager(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
    void playGame(unsigned numGames);
    double getPlayer1WinPercentage() const;
    double getPlayer2WinPercentage() const;
    void printGameStats() const;
    void printBoard() const;
    void resetGameStats();

private:
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    TicTacToe game;
    int player1Wins;
    int player2Wins;
    int draws;
    int totalGamesPlayed{ 0 };
    void playSingleGame();
};
