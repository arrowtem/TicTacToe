#pragma once

#include "Player.h"

class RandomPlayer : public Player {
public:
    std::pair<int, int> makeMove(const TicTacToe& game) const override;
};
