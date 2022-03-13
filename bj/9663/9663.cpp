#include <bits/stdc++.h>

using namespace std;

int N;
int ans;
int X[15];
int Y[15];
int S[15];
int D[15];

void loop(int step, int curX, int curY) {
  X[step] = curX;
  Y[step] = curY;
  S[step] = curX + curY;
  D[step] = curX - curY;
  step++;

  if (step == N) {
    ans += 1;
  } else {
    int nextX = curX + 1;
    for (int i = 0; i < N; i++) {
      bool pass = true;
      for (int y = 0; y < step; y++) {
        if (Y[y] == i || S[y] == nextX + i || D[y] == nextX - i) {
          pass = false;
          break;
        }
      }
      if (pass) {
        loop(step, nextX, i);
      }
    }
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    loop(0, 0, i);
  }
}

int main() {
  scanf("%d", &N);

  solve();

  printf("%d\n", ans);

  return 0;
}
