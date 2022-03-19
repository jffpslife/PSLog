#include <bits/stdc++.h>

using namespace std;

int N;
int A[101];

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

int D[101];
int g;

void solve() {
  g = abs(A[2] - A[1]);
  for (int i = 2; i < N; i++) {
    int b, s;
    int d = abs(A[i + 1] - A[i]);
    if (g < d) {
      b = d;
      s = g;
    } else {
      b = g;
      s = d;
    }
    g = gcd(b, s);
  }
}

vector<int> Div;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  solve();

  for (int i = 2; i <= sqrt(g); i++) {
    if (g % i == 0) {
      printf("%d ", i);
      if (i != g / i) {
        Div.push_back(g / i);
      }
    }
  }
  for (auto it = Div.rbegin(); it != Div.rend(); it++) {
    printf("%d ", *it);
  }
  printf("%d\n", g);

  return 0;
}
