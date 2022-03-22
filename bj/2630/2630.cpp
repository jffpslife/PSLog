#include <bits/stdc++.h>

using namespace std;

int N;
int B[128][128];

int b, w;

void aux(int xl, int xh, int yl, int yh) {
  if (xl + 1 == xh) {
    if (B[xl][yl] == 1) {
      b += 1;
    } else {
      w += 1;
    }
  } else {
    int c = B[xl][yl];
    int s = true;
    for (int i = xl; i < xh; i++) {
      for (int j = yl; j < yh; j++) {
        if (c != B[i][j]) {
          s = false;
          break;
        }
      }
      if (!s) {
        break;
      }
    }
    if (s) {
      if (c == 1) {
        b += 1;
      } else {
        w += 1;
      }
    } else {
      int xm = (xl + xh) / 2;
      int ym = (yl + yh) / 2;
      aux(xl, xm, yl, ym);
      aux(xl, xm, ym, yh);
      aux(xm, xh, yl, ym);
      aux(xm, xh, ym, yh);
    }
  }
}

void solve() {
  aux(0, N, 0, N);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  solve();

  printf("%d\n%d\n", w, b);

  return 0;
}
