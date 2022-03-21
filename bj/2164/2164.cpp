#include <bits/stdc++.h>

using namespace std;

int N;
int ans;
list<int> q;

void solve() {
  for (int i = 1; i <= N; i++) {
    q.push_back(i);
  }

  while (q.size() != 1) {
    q.pop_front();
    int item = q.front();
    q.pop_front();
    q.push_back(item);
  }

  ans = q.front();
}

int main() {
  scanf("%d", &N);

  solve();

  printf("%d\n", ans);

  return 0;
}
