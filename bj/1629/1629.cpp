#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll A, B, C;
ll ans = 1;
int b[32];

void solve() {
  ll t = B;
  int idx = 0;
  while (t != 0) {
    if (t % 2) {
      b[idx] = 1;
    } else {
      b[idx] = 0;
    }
    idx++;
    t /= 2;
  }

  for (int i = idx - 1; i >= 0; i--) {
    ans = (ans * ans) % C;
    if (b[i] == 1) {
      ans = (ans * A) % C;
    }
  }
}

int main() {
  scanf("%lld %lld %lld", &A, &B, &C);

  solve();

  printf("%lld\n", ans);

  return 0;
}
