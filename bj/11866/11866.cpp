#include <bits/stdc++.h>

using namespace std;

int N, K;
list<int> q;

void solve() {
  for (int i = 1; i <= N; i++) {
    q.push_back(i);
  }

  printf("<");
  while (q.size() != 1) {
    for (int i = 1; i <= K - 1; i++) {
      int item = q.front();
      q.pop_front();
      q.push_back(item);
    }
    int item = q.front();
    printf("%d, ", item);
    q.pop_front();
  }

  int item = q.front();
  printf("%d>\n", item);
}

int main() {
  scanf("%d %d", &N, &K);

  solve();

  return 0;
}
