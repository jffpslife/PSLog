#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];
int DP[1001];
int ans;

void solve() {
  DP[1] = 1;
  for (int i = 2; i <= N; i++) {
    DP[i] = 1;
    for (int j = i - 1; j >= 1; j--) {
      if (A[j] < A[i]) {
        DP[i] = max(DP[j] + 1, DP[i]);
      }
    }
  }

  ans = DP[1];
  for (int i = 2; i <= N; i++) {
    ans = max(ans, DP[i]);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
