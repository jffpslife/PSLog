#include <bits/stdc++.h>

using namespace std;

int N;
int S[21][21];

int historyA[10];
int historyB[10];

int ans = 10000;
int sum = 0;

void loop(int state, int cur) {
  historyA[state] = cur;
  state++;

  if (state == N / 2) {
    int scoreA = 0;
    for (int i = 0; i < N / 2; i++) {
      for (int j = 0; j < N / 2; j++) {
        scoreA += S[historyA[i]][historyA[j]];
      }
    }

    int idxA = 0;
    int idxB = 0;
    int cur = 1;
    while (cur <= N && idxA < N / 2 && idxB < N / 2) {
      if (cur < historyA[idxA]) {
        historyB[idxB] = cur;
        idxB++;
        cur++;
      } else {
        idxA++;
        cur++;
      }
    }
    while (cur <= N && idxB < N / 2) {
      historyB[idxB] = cur;
      cur++;
      idxB++;
    }

    int scoreB = 0;
    for (int i = 0; i < N / 2; i++) {
      for (int j = 0; j < N / 2; j++) {
        scoreB += S[historyB[i]][historyB[j]];
      }
    }

    ans = min(ans, abs(scoreA - scoreB));
  } else {
    for (int i = cur + 1; i <= N; i++) {
      loop(state, i);
    }
  }
}

void solve() {
  for (int i = 1; i <= N; i++) {
    loop(0, i);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &S[i][j]);
      sum += S[i][j];
    }
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
