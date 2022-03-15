#include <bits/stdc++.h>

using namespace std;

int N;
int P[301];
int DP1[301];
int DP2[301];

void solve() {
  DP1[0] = 0;
  DP2[0] = 0;
  DP1[1] = P[1];
  DP2[1] = 0;
  DP1[2] = DP1[1] + P[2];
  DP2[2] = P[2];

  for (int i = 3; i <= N; i++) {
    DP1[i] = DP2[i-1] + P[i];
    DP2[i] = max(DP1[i-2], DP2[i-2]) + P[i];
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &P[i]);
  }

  solve();

  printf("%d\n", max(DP1[N], DP2[N]));

  return 0;
}
