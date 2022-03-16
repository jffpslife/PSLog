#include <bits/stdc++.h>

using namespace std;

int n;
int a[100001];
int DP[100001];
int ans;

void solve() {
  DP[1] = a[1];
  ans = a[1];
  for (int i = 2; i <= n; i++) {
    DP[i] = max(a[i], DP[i-1] + a[i]);
    ans = max(ans, DP[i]);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
