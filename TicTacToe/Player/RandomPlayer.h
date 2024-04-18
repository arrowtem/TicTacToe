#pragma once

#include "Player.h"

class RandomPlayer : public Player {
public:
    RandomPlayer(Cell playerMark_) : Player(playerMark_,"RandomPlayer") {};
    std::pair<int, int> makeMove(const TicTacToe& game) const override;
};
