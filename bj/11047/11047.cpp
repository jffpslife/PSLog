#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[11];
int ans = 0;

void solve() {
  for (int i = N; i >= 1; i--) {
    ans += K / A[i];
    K = K % A[i];
  }
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
