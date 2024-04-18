#pragma once

#include "../TicTacToe/TicTacToe.h"
#include "string"

class Player {
public:
    Player(Cell playerMark, std::string typeOfPlayer_) : playerMark(playerMark), opponentMark(deduceOpponent(playerMark)), typeOfPlayer(typeOfPlayer_) {}
    virtual ~Player() = default;
    virtual std::pair<int, int> makeMove(const TicTacToe& game) const = 0;
    Cell getMark() const { return playerMark; }
    const std::string& getTypeOfPlayer() const {
        return typeOfPlayer;
    }
protected:
    Cell playerMark;
    Cell opponentMark;
    const std::string typeOfPlayer;
private:
    Cell deduceOpponent(Cell playerMark) const {
        return (playerMark == Cell::X) ? Cell::O : Cell::X;
    }
};
