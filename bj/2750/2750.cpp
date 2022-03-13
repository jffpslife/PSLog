#include <bits/stdc++.h>

using namespace std;

int N;
int n[1001];

void solve() {
  sort(n + 1, n + N + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> n[i];
  }

  solve();

  for (int i = 1; i <= N; i++) {
    cout << n[i] << endl;
  }

  return 0;
}
