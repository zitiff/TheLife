#include <iostream>
#include <vector>

// Функция для создания игрового поля
std::vector<std::vector<int>> createGameBoard(int rows, int columns) {
    std::vector<std::vector<int>> gameBoard(rows, std::vector<int>(columns, 0));
    return gameBoard;
}

// Функция для отрисовки игрового поля
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
// Функция для проверки на наличие живых клеток
bool checkForAlive(const std::vector<std::vector<int>>& gameBoard)
{
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

// Функция для обновления состояния игрового поля
std::vector<std::vector<int>> updateGameBoard(const std::vector<std::vector<int>>& gameBoard) {
    int rows = gameBoard.size();
    int columns = gameBoard[0].size();
    std::vector<std::vector<int>> newGameBoard(rows, std::vector<int>(columns, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int liveNeighbors = 0;
            // Подсчет количества соседей клетки
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
            // Обновление состояния клетки на основе количества соседей
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

// Основная функция
int main() {
    std::cout << "Enter the number of rows: " << std::endl;
    int rows;
    std::cin>>rows;
    std::cout << "Enter the number of columns: " << std::endl;
    int columns;
    std::cin >> columns;

    std::vector<std::vector<int>> gameBoard = createGameBoard(rows, columns);
    std::vector<std::vector<int>> gameBoardPrevious(rows, std::vector<int>(columns, 0));

    // Запрос у пользователя исходного состояния игрового поля
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
    
        
     // Обновление и отрисовка состояния игрового поля
    for (int i = 0; i < 30; ++i) {

        if (checkForAlive(gameBoard) == false)
        {
            std::cout << "The colony died." << std::endl;
            return 0;
        }

        else
        {
            drawGameBoard(gameBoard);
            std::cout << std::endl;
            gameBoardPrevious = gameBoard;
            gameBoard = updateGameBoard(gameBoard);

        // проверка на повтор предыдущего состояния
            if (gameBoard == gameBoardPrevious)
            {
                std::cout << "The colony is stationary with the condition: " << std::endl;
                drawGameBoard(gameBoard);
                return 0;
            }
        }
    }

    return 0;
}