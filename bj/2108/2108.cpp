#include <bits/stdc++.h>

using namespace std;

int N;
int n[8001];

int am;
int mid;
int freq;
int diff;

void solve() {
  // 1
  int sum = 0;
  for (int i = 0; i <= 8000; i++) {
    sum += n[i] * (i - 4000);
  }
  if (sum < 0) {
    if ((sum % N + N) > N / 2) {
      am = sum / N;
    } else {
      am = sum / N - 1;
    }
  } else {
    if (sum % N > N / 2) {
      am = sum / N + 1;
    } else {
      am = sum / N;
    }
  }

  // 2
  int ord = 0;
  for (int i = 0; i <= 8000; i++) {
    if (n[i] > 0) {
      ord += n[i];
      if (ord >= N / 2 + 1) {
        mid = i - 4000;
        break;
      }
    }
  }

  // 3
  int cnt = 0;
  for (int i = 0; i <= 8000; i++) {
    if (n[i] > cnt) {
      cnt = n[i];
    }
  }
  int checked = -1;
  for (int i = 0; i <= 8000; i++) {
    if (n[i] == cnt) {
      if (checked == -1) {
        checked = i;
      } else {
        checked = i;
        break;
      }
    }
  }
  freq = checked - 4000;

  // 4
  int m = 8001;
  int M = 0;
  for (int i = 0; i <= 8000; i++) {
    if (n[i] > 0) {
      m = min(m, i);
      M = max(M, i);
    }
  }
  diff = M - m;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int t;
    scanf("%d", &t);
    n[t+4000] += 1;
  }

  solve();

  printf("%d\n", am);
  printf("%d\n", mid);
  printf("%d\n", freq);
  printf("%d\n", diff);

  return 0;
}
