#pragma once

#include <array>
#include <concepts>

enum class Cell { Empty, X, O };

class TicTacToe {
public:
    TicTacToe();
    Cell getCell(int row, int col) const;
    bool makeMove(int row, int col, Cell player);
    void undoMove(int row, int col);
    Cell checkWinner() const;
    bool checkDraw() const;
    void reset();

private:
    std::array<std::array<Cell, 3>, 3> board;
};
