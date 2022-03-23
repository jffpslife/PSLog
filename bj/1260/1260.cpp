#include <bits/stdc++.h>

using namespace std;

int N, M, V;
list<int> edges[1001];
set<int> visited;
list<int> worklist;

void dfs(int v) {
  printf("%d ", v);
  visited.insert(v);
  for (auto s : edges[v]) {
    if (visited.find(s) == visited.end()) {
      dfs(s);
    }
  }
}

void bfs(int v) {
  worklist.push_back(V);
  while (!worklist.empty()) {
    int v = worklist.front();
    worklist.pop_front();
    if (visited.find(v) == visited.end()) {
      printf("%d ", v);
      visited.insert(v);
      for (auto s : edges[v]) {
        worklist.push_back(s);
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &V);
  for (int i = 0; i < M; i++) {
    int s, d;
    scanf("%d %d", &s, &d);
    edges[s].push_back(d);
    edges[d].push_back(s);
  }
  for (int i = 1; i <= N; i++) {
    edges[i].sort();
  }

  dfs(V);
  printf("\n");

  visited.clear();
  bfs(V);
  printf("\n");

  return 0;
}
