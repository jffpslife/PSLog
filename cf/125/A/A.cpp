#include <bits/stdc++.h>

using namespace std;

int T;
int x, y;
int ans;

void solve() {
  if (x == 0 && y == 0) {
    ans = 0;
  } else {
    int s = sqrt(x * x + y * y);
    if (s * s == x * x + y * y) {
      ans = 1;
    } else {
      ans = 2;
    }
  }
}

int main() {
  setbuf(stdout, NULL);

  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d %d", &x, &y);
    solve();
    printf("%d\n", ans);
  }

  return 0;
}
