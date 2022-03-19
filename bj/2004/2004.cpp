#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll N, M;
int ans;

ll c2;
ll c5;

void add(ll n) {
  ll d;
  d = 2;
  while (d <= n) {
    c2 += n / d;
    d *= 2;
  }

  d = 5;
  while (d <= n) {
    c5 += n / d;
    d *= 5;
  }
}

void sub(ll n) {
  ll d;
  d = 2;
  while (d <= n) {
    c2 -= n / d;
    d *= 2;
  }

  d = 5;
  while (d <= n) {
    c5 -= n / d;
    d *= 5;
  }
}

void solve() {
  add(N);
  sub(M);
  sub(N - M);

  ans = min(c2, c5);
}

int main() {
  scanf("%lld %lld", &N, &M);

  solve();

  printf("%d\n", ans);

  return 0;
}
