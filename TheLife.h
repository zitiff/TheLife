#include <vector>

// Функция для создания игрового поля
std::vector<std::vector<int>> createGameBoard(int rows, int columns);

// Функция для отрисовки игрового поля
void drawGameBoard(const std::vector<std::vector<int>>& gameBoard);

// Функция для проверки на наличие живых клеток
bool checkForAlive(const std::vector<std::vector<int>>& gameBoard);

// Функция для обновления состояния игрового поля
std::vector<std::vector<int>> updateGameBoard(const std::vector<std::vector<int>>& gameBoard);

