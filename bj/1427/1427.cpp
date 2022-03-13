#include <bits/stdc++.h>

using namespace std;

int N;
int d[10];

void solve() {
  while (N != 0) {
    d[N % 10]++;
    N /= 10;
  }
}

int main() {
  scanf("%d", &N);

  solve();

  for (int i = 9; i >= 0; i--) {
    for (int j = 0; j < d[i]; j++) {
      printf("%d", i);
    }
  }
  printf("\n");

  return 0;
}
