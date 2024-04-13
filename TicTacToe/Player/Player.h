#pragma once

#include "../TicTacToe/TicTacToe.h"

class Player {
public:
    virtual ~Player() = default;
    virtual std::pair<int, int> makeMove(const TicTacToe& game) const = 0;
};
