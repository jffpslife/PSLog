#include <bits/stdc++.h>

using namespace std;

int N;
int ans;

void solve() {
  for (int i = 1; i <= N; i++) {
    int k = i;
    while (k % 5 == 0) {
      ans += 1;
      k /= 5;
    }
  }
}

int main() {
  scanf("%d", &N);

  solve();

  printf("%d\n", ans);

  return 0;
}
