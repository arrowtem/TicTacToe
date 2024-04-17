#include "Player/randomplayer.h"
#include "Player/smartplayer.h"
#include "GameManager/GameManager.h"
#include <iostream>

int main() {
    auto player1 = std::make_shared<RandomPlayer>(Cell::X);
    auto player2 = std::make_shared<SmartPlayer>(Cell::O);

    GameManager gameManager(player1, player2);

    gameManager.playGame(100);
    gameManager.printGameStats();
    gameManager.playGame(100);
    gameManager.printGameStats();

    gameManager.resetGameStats();
    gameManager.playGame(100);
    gameManager.printGameStats();
    return 0;
}
