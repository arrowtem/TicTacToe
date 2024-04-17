#pragma once

#include "../TicTacToe/TicTacToe.h"

class Player {
public:
    Player(Cell playerMark) : playerMark(playerMark), opponentMark(deduceOpponent(playerMark)) {}
    virtual ~Player() = default;
    virtual std::pair<int, int> makeMove(const TicTacToe& game) const = 0;
    Cell getMark() const { return playerMark; }
protected:
    Cell playerMark;
    Cell opponentMark;
private:
    Cell deduceOpponent(Cell playerMark) const {
        return (playerMark == Cell::X) ? Cell::O : Cell::X;
    }
};
