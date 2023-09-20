#include "TheLife.h"
#include <iostream>

int main() {
    std::cout << "Enter the number of rows: " << std::endl;
    int rows;
    std::cin >> rows;
    std::cout << "Enter the number of columns: " << std::endl;
    int columns;
    std::cin >> columns;

    std::vector<std::vector<int>> gameBoard = createGameBoard(rows, columns);
    std::vector<std::vector<int>> gameBoardPrevious(rows, std::vector<int>(columns, 0));

    std::cout << "Enter the initial state of the playing field (use . for empty cells and * for live cells):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            char cell;
            std::cin >> cell;
            if (cell == '*') {
                gameBoard[i][j] = 1;
            }
        }
    }

    std::cout << "_________" << std::endl;

    for (int i = 0; i < 30; ++i) {
        if (checkForAlive(gameBoard) == false) {
            drawGameBoard(gameBoard);
            std::cout << "The colony died." << std::endl;
            return 0;
        }
        else {
            drawGameBoard(gameBoard);
            std::cout << std::endl;
            gameBoardPrevious = gameBoard;
            gameBoard = updateGameBoard(gameBoard);

            if (gameBoard == gameBoardPrevious) {
                std::cout << "The colony is stationary with the condition: " << std::endl;
                drawGameBoard(gameBoard);
                return 0;
            }
        }
    }

    return 0;
}
