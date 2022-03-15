#include <bits/stdc++.h>

using namespace std;

int N;
int DP[1000001];
int B[1000001];

int solve(int n) {
  if (n == 1) {
    B[n] = true;
    DP[n] = 0;
    return 0;
  } else if (B[n]) {
    return DP[n];
  } else {
    int op3 = 1000001;
    int op2 = 1000001;
    int op1 = 1000001;
    if (n % 3 == 0) {
      op3 = solve(n / 3) + 1;
    }
    if (n % 2 == 0) {
      op2 = solve(n / 2) + 1;
    }
    op1 = solve(n - 1) + 1;
    int res = min(op3, min(op2, op1));
    B[n] = true;
    DP[n] = res;
    return res;
  }
}

int main() {
  scanf("%d", &N);

  int ans = solve(N);

  printf("%d\n", ans);

  return 0;
}
