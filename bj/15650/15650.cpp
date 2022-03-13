#include <bits/stdc++.h>

using namespace std;

int N, M;
int history[8];

void loop(int step, int cur) {
  history[step] = cur;
  step++;

  if (step == M) {
    for (int i = 0; i < M; i++) {
      printf("%d ", history[i]);
    }
    printf("\n");
  } else {
    for (int i = cur + 1; i <= N; i++) {
      loop(step, i);
    }
  }
}

void solve() {
  for (int i = 1; i <= N; i++) {
    loop(0, i);
  }
}

int main() {
  scanf("%d %d", &N, &M);

  solve();

  return 0;
}
