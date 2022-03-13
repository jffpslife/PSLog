#include <bits/stdc++.h>

using namespace std;

int N;
int A[100];
int ops[4];

int ans;
int maxA = -1000000000;
int minA = 1000000000;

void solve(int step) {
  if (step == N - 1) {
    minA = min(minA, ans);
    maxA = max(maxA, ans);
  } else {
    int old_ans;
    if (ops[0] > 0) {
      old_ans = ans;
      ans += A[step + 1];
      ops[0]--;
      solve(step + 1);
      ops[0]++;
      ans = old_ans;
    }
    if (ops[1] > 0) {
      old_ans = ans;
      ans -= A[step + 1];
      ops[1]--;
      solve(step + 1);
      ops[1]++;
      ans = old_ans;
    }
    if (ops[2] > 0) {
      old_ans = ans;
      ans *= A[step + 1];
      ops[2]--;
      solve(step + 1);
      ops[2]++;
      ans = old_ans;
    }
    if (ops[3] > 0) {
      old_ans = ans;
      ans /= A[step + 1];
      ops[3]--;
      solve(step + 1);
      ops[3]++;
      ans = old_ans;
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d %d %d %d", &ops[0], &ops[1], &ops[2], &ops[3]);

  ans = A[0];
  solve(0);

  printf("%d\n", maxA);
  printf("%d\n", minA);

  return 0;
}
