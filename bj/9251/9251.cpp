#include <bits/stdc++.h>

using namespace std;

char S1[1001];
char S2[1001];
int L1;
int L2;

int DP[1001][1001];
int B[1001][1001];

int ans;

int dp(int i, int j) {
  if (B[i][j]) {
    return DP[i][j];
  } else {
    if (i < 1 || j < 1) {
      return 0;
    } else {
      if (S1[i-1] == S2[j-1]) {
        int res = dp(i - 1, j - 1) + 1;
        B[i][j] = true;
        DP[i][j] = res;
        return res;
      } else {
        int res1 = dp(i - 1, j);
        int res2 = dp(i, j - 1);
        int res = max(res1, res2);
        B[i][j] = true;
        DP[i][j] = res;
        return res;
      }
    }
  }
}

void solve() {
  L1 = strlen(S1);
  L2 = strlen(S2);

  ans = dp(L1, L2);
}

int main() {
  scanf("%s", S1);
  scanf("%s", S2);

  solve();

  printf("%d\n", ans);

  return 0;
}
