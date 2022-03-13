#include <bits/stdc++.h>

using namespace std;

int N;
int n[1000001];

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int t;
    cin >> t;
    if (t > 0) {
      n[abs(t)] += 1;
    } else if (t < 0) {
      n[abs(t)] += 2;
    } else {
      n[abs(t)] = 3;
    }
  }

  for (int i = 1000000; i >= 0; i--) {
    if (n[i] == 2 || n[i] == 3) {
      printf("%d\n", -i);
    }
  }
  for (int i = 1; i <= 1000000; i++) {
    if (n[i] == 1 || n[i] == 3) {
      printf("%d\n", i);
    }
  }

  return 0;
}
