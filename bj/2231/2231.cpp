#include <bits/stdc++.h>

using namespace std;

int N;
int ans;

int sum(int n) {
  int s = n;
  while (n != 0) {
    s += n % 10;
    n /= 10;
  }
  return s;
}

void solve() {
  for (int i = 1; i < N; i++) {
    if (sum(i) == N) {
      ans = i;
      return;
    }
  }
  ans = 0;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  solve();
  cout << ans << endl;

  return 0;
}
