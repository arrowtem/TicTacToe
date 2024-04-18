#include "gamemanager.h"
#include <iostream>
#include <chrono>
#include <random>

GameManager::GameManager(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
    : player1(player1), player2(player2), player1Wins(0), player2Wins(0), draws(0) {}

void GameManager::playGame(unsigned numGames) {
    for (int i = 0; i < numGames; ++i) {
        playSingleGame();
        ++totalGamesPlayed;
    }
}

double GameManager::getPlayer1WinPercentage() const {
    return static_cast<double>(player1Wins) / totalGamesPlayed * 100;
}

double GameManager::getPlayer2WinPercentage() const {
    return static_cast<double>(player2Wins) / totalGamesPlayed * 100;
}


void GameManager::printGameStats() const {
    std::cout << "Total games played: " << totalGamesPlayed << std::endl;
    std::cout << "Player 1 wins: " << player1Wins << " (" << getPlayer1WinPercentage() << "%)\n";
    std::cout << "Player 2 wins: " << player2Wins << " (" << getPlayer2WinPercentage() << "%)\n";
    std::cout << "Draws: " << draws << " (" << 100 - (getPlayer1WinPercentage() + getPlayer2WinPercentage()) << "%)\n";
}


void GameManager::playSingleGame() {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    static std::uniform_int_distribution<int> distribution(0, 1);

    bool player1Turn = distribution(rng) == 0;

    while (game.checkWinner() == Cell::Empty && !game.checkDraw()) {
        std::pair<int, int> move;
        Cell currentMark;
        if (player1Turn) {
            move = player1->makeMove(game);
            currentMark = player1->getMark();
        }
        else {
            move = player2->makeMove(game);
            currentMark = player2->getMark();
        }

        if (!game.makeMove(move.first, move.second, currentMark))
            break;

        player1Turn = !player1Turn;
    }

    Cell winner = game.checkWinner();
    if (winner == player1->getMark()) {
        ++player1Wins;
        std::cout << "Game " << totalGamesPlayed + 1 << ": Player 1 wins!\n";
    }
    else if (winner == player2->getMark()) {
        ++player2Wins;
        std::cout << "Game " << totalGamesPlayed + 1 << ": Player 2 wins!\n";
    }
    else {
        ++draws;
        std::cout << "Game " << totalGamesPlayed + 1 << ": Draw!\n";
    }

    game.reset();
}



void GameManager::printBoard() const {
    std::cout << "Current Game Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            switch (game.getCell(i, j)) {
            case Cell::X:
                std::cout << "X ";
                break;
            case Cell::O:
                std::cout << "O ";
                break;
            case Cell::Empty:
                std::cout << "_ ";
                break;
            }
        }
        std::cout << std::endl;
    }
}

void GameManager::resetGameStats()
{
    player1Wins = 0;
    player2Wins = 0; 
    draws = 0;
    totalGamesPlayed = 0;
}
