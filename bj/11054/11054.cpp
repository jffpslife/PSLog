#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];
int I[1001];
int D[1001];
int ans;

void solve() {
  I[1] = 1;
  for (int i = 2; i <= N; i++) {
    I[i] = 1;
    for (int j = i - 1; j >= 1; j--) {
      if (A[j] < A[i]) {
        I[i] = max(I[i], I[j] + 1);
      }
    }
  }

  D[N] = 1;
  for (int i = N - 1; i >= 1; i--) {
    D[i] = 1;
    for (int j = i + 1; j <= N; j++) {
      if (A[j] < A[i]) {
        D[i] = max(D[i], D[j] + 1);
      }
    }
  }

  ans = I[1] + D[1] - 1;
  for (int i = 2; i <= N; i++) {
    ans = max(ans, I[i] + D[i] - 1);
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
