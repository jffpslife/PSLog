#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int table[21][21][21];
bool f[21][21][21];

int w(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }
  if (a > 20 || b > 20 || c > 20) {
    return w(20, 20, 20);
  }
  if (f[a][b][c]) {
    return table[a][b][c];
  }
  if (a < b && b < c) {
    int res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    f[a][b][c] = true;
    table[a][b][c] = res;
    return res;
  } else {
    int res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    f[a][b][c] = true;
    table[a][b][c] = res;
    return res;
  }
}

int main() {
  while (1) {
    scanf("%d %d %d", &a, &b, &c);

    if (a == -1 && b == -1 && c == -1) {
      break;
    }

    int ans = w(a, b, c);

    printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
  }

  return 0;
}
