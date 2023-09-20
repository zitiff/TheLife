#include <vector>

// ������� ��� �������� �������� ����
std::vector<std::vector<int>> createGameBoard(int rows, int columns);

// ������� ��� ��������� �������� ����
void drawGameBoard(const std::vector<std::vector<int>>& gameBoard);

// ������� ��� �������� �� ������� ����� ������
bool checkForAlive(const std::vector<std::vector<int>>& gameBoard);

// ������� ��� ���������� ��������� �������� ����
std::vector<std::vector<int>> updateGameBoard(const std::vector<std::vector<int>>& gameBoard);

