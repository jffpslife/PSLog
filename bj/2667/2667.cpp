#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Coord;

int N;
int B[26][26];
map<Coord, int> vertices;
map<Coord, list<Coord>> edges;

void build_node(int i, int j) {
  Coord c = Coord(i, j);
  vertices[c] = -1;
  edges[c] = list<Coord> ();
}

void build_left_edge(int i, int j) {
  if (j > 1) {
    if (B[i][j-1] == 1) {
      Coord src = Coord(i, j);
      Coord dst = Coord(i, j-1);
      edges[src].push_back(dst);
    }
  }
}

void build_right_edge(int i, int j) {
  if (j < N) {
    if (B[i][j+1] == 1) {
      Coord src = Coord(i, j);
      Coord dst = Coord(i, j+1);
      edges[src].push_back(dst);
    }
  }
}

void build_up_edge(int i, int j) {
  if (i > 1) {
    if (B[i-1][j] == 1) {
      Coord src = Coord(i, j);
      Coord dst = Coord(i-1, j);
      edges[src].push_back(dst);
    }
  }
}

void build_down_edge(int i, int j) {
  if (i < N) {
    if (B[i+1][j] == 1) {
      Coord src = Coord(i, j);
      Coord dst = Coord(i+1, j);
      edges[src].push_back(dst);
    }
  }
}

void build_graph() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (B[i][j] == 1) {
        build_node(i, j);
        build_left_edge(i, j);
        build_right_edge(i, j);
        build_up_edge(i, j);
        build_down_edge(i, j);
      }
    }
  }
}

int marks[26 * 26];

set<Coord> dfs_visited;
void dfs(int mark, int i, int j) {
  Coord c = Coord(i, j);
  if (dfs_visited.find(c) == dfs_visited.end()) {
    vertices[c] = mark;
    marks[mark]++;
    dfs_visited.insert(c);
    for (auto s : edges[c]) {
      dfs(mark, s.first, s.second);
    }
  }
}

void solve() {
  build_graph();

  int mark = 1;
  for (auto [v, _] : edges) {
    dfs(mark, v.first, v.second);
    mark++;
  }

  sort(marks + 1, marks + N * N);
  int cnt = 0;
  for (int i = 1; i <= N * N; i++) {
    if (marks[i] != 0) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= N * N; i++) {
    if (marks[i] != 0) {
      printf("%d\n", marks[i]);
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    char buf[26];
    scanf("%s", buf);
    for (int j = 1; j <= N; j++) {
      B[i][j] = buf[j-1] - '0';
    }
  }

  solve();

  return 0;
}
