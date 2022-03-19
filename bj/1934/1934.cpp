#include <bits/stdc++.h>

using namespace std;

int T;
int A, B;
int ans;

// GCD
// XXX: a >= b
int gcd(int a, int b) {
  int r = a % b;
  if (r == 0) {
    return b;
  } else {
    return gcd(b, r);
  }
}

void solve() {
  int b, s;
  if (A < B) {
    b = B;
    s = A;
  } else {
    b = A;
    s = B;
  }
  int g = gcd(b, s);
  ans = A * B / g;
}

int main() {
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d %d", &A, &B);

    solve();

    printf("%d\n", ans);
  }

  return 0;
}
