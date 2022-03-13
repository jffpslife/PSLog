#include <bits/stdc++.h>

using namespace std;

int T;

int table0[41];
int table1[41];

void solve() {
  table0[0] = 1;
  table0[1] = 0;
  table1[0] = 0;
  table1[1] = 1;
  for (int i = 2; i <= 40; i++) {
    table0[i] = table0[i-1] + table0[i-2];
    table1[i] = table1[i-1] + table1[i-2];
  }
}

int main() {
  scanf("%d", &T);

  solve();

  for (int i = 0; i < T; i++) {
    int N;
    scanf("%d", &N);
    printf("%d %d\n", table0[N], table1[N]);
  }

  return 0;
}
