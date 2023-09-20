#include "TheLife.h"
#include <iostream>

std::vector<std::vector<int>> createGameBoard(int rows, int columns) {
    std::vector<std::vector<int>> gameBoard(rows, std::vector<int>(columns, 0));
    return gameBoard;
}

void drawGameBoard(const std::vector<std::vector<int>>& gameBoard) {
    for (const auto& row : gameBoard) {
        for (int cell : row) {
            if (cell == 0) {
                std::cout << ".";
            }
            else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}

bool checkForAlive(const std::vector<std::vector<int>>& gameBoard) {
    bool isAlive = false;
    for (const auto& row : gameBoard) {
        for (int cell : row) {
            if (cell == 1) {
                isAlive = true;
            }
        }
    }
    return isAlive;
}

std::vector<std::vector<int>> updateGameBoard(const std::vector<std::vector<int>>& gameBoard) {
    int rows = gameBoard.size();
    int columns = gameBoard[0].size();
    std::vector<std::vector<int>> newGameBoard(rows, std::vector<int>(columns, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int liveNeighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) {
                        continue;
                    }
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < columns && gameBoard[ni][nj] == 1) {
                        liveNeighbors++;
                    }
                }
            }
            if (gameBoard[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newGameBoard[i][j] = 0;
                }
                else {
                    newGameBoard[i][j] = 1;
                }
            }
            else {
                if (liveNeighbors == 3) {
                    newGameBoard[i][j] = 1;
                }
            }
        }
    }

    return newGameBoard;
}
