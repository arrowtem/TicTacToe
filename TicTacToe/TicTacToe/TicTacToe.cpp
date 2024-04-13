#include "tictactoe.h"

TicTacToe::TicTacToe() {
    reset();
}

Cell TicTacToe::getCell(int row, int col) const {
    return board[row][col];
}

bool TicTacToe::makeMove(int row, int col, Cell player) {
    if (board[row][col] == Cell::Empty) {
        board[row][col] = player;
        return true;
    }
    return false;
}

void TicTacToe::undoMove(int row, int col) {
    board[row][col] = Cell::Empty;
}

Cell TicTacToe::checkWinner() const {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != Cell::Empty && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != Cell::Empty && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] != Cell::Empty && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != Cell::Empty && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // No winner
    return Cell::Empty;
}

bool TicTacToe::checkDraw() const {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == Cell::Empty) {
                return false; // There is an empty cell, game is not a draw
            }
        }
    }
    // All cells are occupied, game is a draw
    return true;
}

void TicTacToe::reset() {
    board.fill({ Cell::Empty });
}
