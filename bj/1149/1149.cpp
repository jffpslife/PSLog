#include <bits/stdc++.h>

using namespace std;

int N;
int R[1001];
int G[1001];
int B[1001];

int CR[1001];
int CG[1001];
int CB[1001];

int ans;

void solve() {
  CR[1] = R[1];
  CG[1] = G[1];
  CB[1] = B[1];

  for (int i = 2; i <= N; i++) {
    CR[i] = min(CG[i - 1], CB[i - 1]) + R[i];
    CG[i] = min(CR[i - 1], CB[i - 1]) + G[i];
    CB[i] = min(CR[i - 1], CG[i - 1]) + B[i];
  }

  ans = min(CR[N], min(CG[N], CB[N]));
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d %d", &R[i], &G[i], &B[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
