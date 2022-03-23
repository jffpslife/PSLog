#include <bits/stdc++.h>

using namespace std;

int N;
int B[64][64];

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
    printf("%d", item);
  } else {
    printf("(");
    int xm = (xl + xh) / 2;
    int ym = (yl + yh) / 2;
    solve(xl, xm, yl, ym);
    solve(xl, xm, ym, yh);
    solve(xm, xh, yl, ym);
    solve(xm, xh, ym, yh);
    printf(")");
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    char buf[65];
    scanf("%s", buf);
    for (int j = 0; j < N; j++) {
      B[i][j] = buf[j] - '0';
    }
  }

  solve(0, N, 0, N);

  printf("\n");

  return 0;
}
