#include <bits/stdc++.h>

using namespace std;

int N, K;
int ans;

int C2;
int C3;
int C5;
int C7;

void solve() {
  for (int i = 1; i <= N; i++) {
    int k = i;
    while (k % 2 == 0) {
      C2 += 1;
      k /= 2;
    }
    k = i;
    while (k % 3 == 0) {
      C3 += 1;
      k /= 3;
    }
    while (k % 5 == 0) {
      C5 += 1;
      k /= 5;
    }
    while (k % 7 == 0) {
      C7 += 1;
      k /= 7;
    }
  }
  for (int i = 1; i <= K; i++) {
    int k = i;
    while (k % 2 == 0) {
      C2 -= 1;
      k /= 2;
    }
    k = i;
    while (k % 3 == 0) {
      C3 -= 1;
      k /= 3;
    }
    while (k % 5 == 0) {
      C5 -= 1;
      k /= 5;
    }
    while (k % 7 == 0) {
      C7 -= 1;
      k /= 7;
    }
  }
  for (int i = 1; i <= N - K; i++) {
    int k = i;
    while (k % 2 == 0) {
      C2 -= 1;
      k /= 2;
    }
    k = i;
    while (k % 3 == 0) {
      C3 -= 1;
      k /= 3;
    }
    while (k % 5 == 0) {
      C5 -= 1;
      k /= 5;
    }
    while (k % 7 == 0) {
      C7 -= 1;
      k /= 7;
    }
  }

  ans = 1;
  for (int i = 0; i < C2; i++) {
    ans *= 2;
  }
  for (int i = 0; i < C3; i++) {
    ans *= 3;
  }
  for (int i = 0; i < C5; i++) {
    ans *= 5;
  }
  for (int i = 0; i < C7; i++) {
    ans *= 7;
  }
}

int main() {
  scanf("%d %d", &N, &K);

  solve();

  printf("%d\n", ans);

  return 0;
}
