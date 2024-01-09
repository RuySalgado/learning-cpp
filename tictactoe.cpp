#include <iostream>

using namespace std;

void printBoard(char board[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) 
      cout << "|" << board[i][j] << " ";
    cout << "|" << "\n";
  }
}

int main() {
  char board[][3] = { { '*', '*', '*' }, { '*', '*', '*' }, { '*', '*', '*' } };

  printBoard(board);
}