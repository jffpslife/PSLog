#include <bits/stdc++.h>

using namespace std;

int A, B;

int gcd(int a, int b) {
  int r = a % b;
  if (r == 0) {
    return b;
  } else {
    return gcd(b, r);
  }
}

int g;
int l;

void solve() {
  int b, s;
  if (A <= B) {
    s = A;
    b = B;
  } else {
    s = B;
    b = A;
  }
  g = gcd(b, s);
  l = A * B / g;
}

int main() {
  scanf("%d %d", &A, &B);

  solve();

  printf("%d\n", g);
  printf("%d\n", l);

  return 0;
}
