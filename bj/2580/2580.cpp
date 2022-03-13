#include <bits/stdc++.h>

using namespace std;

int board[9][9];
int emptyN = 0;
int emptyX[81];
int emptyY[81];
bool isDone = false;

void solve(int cur) {
  for (int i = 1; i <= 9; i++) {
    if (isDone) {
      break;
    }
    int x = emptyX[cur];
    int y = emptyY[cur];
    bool pass = true;
    for (int j = 0; j < 9; j++) {
      if (board[x][j] == i || board[j][y] == i || board[(x / 3) * 3 + j / 3][(y / 3) * 3 + j % 3] == i) {
        pass = false;
        break;
      }
    }
    if (pass) {
      board[x][y] = i;
      if (cur == emptyN - 1) {
        isDone = true;
      } else {
        solve(cur + 1);
        if (!isDone) {
          board[x][y] = 0;
        }
      }
    }
  }
}

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 0) {
        emptyX[emptyN] = i;
        emptyY[emptyN] = j;
        emptyN++;
      }
    }
  }

  solve(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}
