#pragma once

#include "Player.h"
#include "../TicTacToe/TicTacToe.h"
#include <limits>

class SmartPlayer : public Player {
public:
    SmartPlayer(Cell playerMark_) : Player(playerMark_) {};
    std::pair<int, int> makeMove(const TicTacToe& game) const override;

private:
    int evaluatePosition(const TicTacToe& game) const;
    int minimax(TicTacToe& game, int depth, int alpha, int beta, bool maximizingPlayer) const;
    int maxDepth = 5;
};
