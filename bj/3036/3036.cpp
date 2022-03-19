#include <bits/stdc++.h>

using namespace std;

int N;
int R[101];

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

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &R[i]);
  }

  for (int i = 2; i <= N; i++) {
    int b = max(R[1], R[i]);
    int s = min(R[1], R[i]);
    int g = gcd(b, s);
    printf("%d/%d\n", R[1]/g, R[i]/g);
  }

  return 0;
}
