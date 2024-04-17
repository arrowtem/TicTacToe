#include "smartplayer.h"
#include <limits>

std::pair<int, int> SmartPlayer::makeMove(const TicTacToe& game) const {
    int bestScore = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = { -1, -1 };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (game.getCell(i, j) == Cell::Empty) {
                TicTacToe tempGame = game;
                tempGame.makeMove(i, j, playerMark);

                int score = minimax(tempGame, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false);

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = { i, j };
                }
            }
        }
    }

    return bestMove;
}

int SmartPlayer::minimax(TicTacToe& game, int depth, int alpha, int beta, bool maximizingPlayer) const {

    if (depth == maxDepth || game.checkWinner() != Cell::Empty || game.checkDraw()) {
        return evaluatePosition(game);
    }

    if (maximizingPlayer) {
        int bestScore = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (game.getCell(i, j) == Cell::Empty) {
                    game.makeMove(i, j, playerMark);
                    int score = minimax(game, depth + 1, alpha, beta, false);
                    game.undoMove(i, j); 
                    bestScore = std::max(bestScore, score);
                    alpha = std::max(alpha, score);
                    if (beta <= alpha) {
                        break; 
                    }
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (game.getCell(i, j) == Cell::Empty) {
                     
                    game.makeMove(i, j, opponentMark);
                    int score = minimax(game, depth + 1, alpha, beta, true);
                    game.undoMove(i, j); 
                    bestScore = std::min(bestScore, score);
                    beta = std::min(beta, score);
                    if (beta <= alpha) {
                        break; 
                    }
                }
            }
        }
        return bestScore;
    }
}

int SmartPlayer::evaluatePosition(const TicTacToe& game) const {
    Cell winner = game.checkWinner();
    if (winner == playerMark) {
        return 10;
    }
    else if (winner == opponentMark) {
        return -10;
    }
    return 0;
}
