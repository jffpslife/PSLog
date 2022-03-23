#include <bits/stdc++.h>

using namespace std;

int N;
int B[2200][2200];

int m;
int z;
int p;

void solve(int xl, int xh, int yl, int yh) {
  bool all_same = true;
  int item = B[xl][yl];
  for (int i = xl; i < xh; i++) {
    for (int j = yl; j < yh; j++) {
      if (item != B[i][j]) {
        all_same = false;
        break;
      }
    }
    if (!all_same) {
      break;
    }
  }

  if (all_same) {
    if (item == -1) {
      m++;
    } else if (item == 0) {
      z++;
    } else {
      p++;
    }
  } else {
    int xf = (2 * xl + xh) / 3;
    int xs = (xl + 2 * xh) / 3;
    int yf = (2 * yl + yh) / 3;
    int ys = (yl + 2 * yh) / 3;
    solve(xl, xf, yl, yf);
    solve(xl, xf, yf, ys);
    solve(xl, xf, ys, yh);
    solve(xf, xs, yl, yf);
    solve(xf, xs, yf, ys);
    solve(xf, xs, ys, yh);
    solve(xs, xh, yl, yf);
    solve(xs, xh, yf, ys);
    solve(xs, xh, ys, yh);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  solve(0, N, 0, N);

  printf("%d\n%d\n%d\n", m, z, p);

  return 0;
}
