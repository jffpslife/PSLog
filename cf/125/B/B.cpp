#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int T;
ll n, B, x, y;
ll ans;

void solve() {
  int a = 0;
  for (int i = 1; i <= n; i++) {
    if (a + x <= B) {
      a += x;
    } else {
      a -= y;
    }
    ans += a;
  }
}

int main() {
  setbuf(stdout, NULL);

  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%lld %lld %lld %lld", &n, &B, &x, &y);
    ans = 0;
    solve();
    printf("%lld\n", ans);
  }

  return 0;
}
