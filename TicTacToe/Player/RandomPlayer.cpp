#include "randomplayer.h"
#include <random>

std::pair<int, int> RandomPlayer::makeMove(const TicTacToe& game) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 2);
    int row = dis(gen);
    int col = dis(gen);
    while (game.getCell(row, col) != Cell::Empty) {
        row = dis(gen);
        col = dis(gen);
    }
    return { row, col };
}
