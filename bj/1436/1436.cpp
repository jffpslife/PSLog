#include <bits/stdc++.h>

using namespace std;

int N;
int ans;

bool has666(int n) {
  int state = 0;
  while (n != 0) {
    if (n % 10 == 6) {
      state++;
      if (state == 3) {
        return true;
      }
    } else {
      state = 0;
    }
    n /= 10;
  }

  return false;
}

void solve() {
  int cnt = 0;
  for (int i = 1; i < 6660000; i++) {
    if (has666(i)) {
      cnt++;
      if (cnt == N) {
        ans = i;
        break;
      }
    }
  }
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
