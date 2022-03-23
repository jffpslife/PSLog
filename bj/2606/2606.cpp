#include <bits/stdc++.h>

using namespace std;

int V, E;
list<int> edges[101];
int ans;

set<int> visited;

void dfs(int v) {
  visited.insert(v);
  for (auto s : edges[v]) {
    if (visited.find(s) == visited.end()) {
      dfs(s);
    }
  }
}

void solve() {
  dfs(1);

  ans = visited.size() - 1;
}

int main() {
  scanf("%d", &V);
  scanf("%d", &E);
  for (int i = 0; i < E; i++) {
    int s, d;
    scanf("%d %d", &s, &d);
    edges[s].push_back(d);
    edges[d].push_back(s);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
