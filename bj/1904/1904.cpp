#include <bits/stdc++.h>

using namespace std;

int N;
int T[1000001];
bool F[1000001];

int solve(int N) {
  if (N == 1) {
    return 1;
  } else if (N == 2) {
    return 2;
  } else if (F[N]) {
    return T[N];
  } else {
    int res = (solve(N - 1) + solve(N - 2)) % 15746;
    F[N] = true;
    T[N] = res;
    return res;
  }
}

int main() {
  scanf("%d", &N);

  int ans = solve(N);

  printf("%d\n", ans);

  return 0;
}
