#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Coord;

int T;
int M, N, K;
int board[50][50];

set<Coord> unvisited;
map<Coord, list<Coord>> edges;

void build_node(int i, int j) {
  Coord c = Coord(i, j);
  unvisited.insert(c);
  edges[c] = list<Coord>();
}

void build_left_edge(int i, int j) {
  if (j > 0) {
    if (board[i][j-1] != 0) {
      Coord src = Coord(i, j);
      Coord dst = Coord(i, j-1);
      edges[src].push_back(dst);
    }
  }
}

void build_right_edge(int i, int j) {
  if (j < M - 1) {
    if (board[i][j+1] != 0) {
      Coord src = Coord(i, j);
      Coord dst = Coord(i, j+1);
      edges[src].push_back(dst);
    }
  }
}

void build_up_edge(int i, int j) {
  if (i > 0) {
    if (board[i-1][j] != 0) {
      Coord src = Coord(i, j);
      Coord dst = Coord(i-1, j);
      edges[src].push_back(dst);
    }
  }
}

void build_down_edge(int i, int j) {
  if (i < N - 1) {
    if (board[i+1][j] != 0) {
      Coord src = Coord(i, j);
      Coord dst = Coord(i+1, j);
      edges[src].push_back(dst);
    }
  }
}

void build_graph() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != 0) {
        build_node(i, j);
        build_left_edge(i, j);
        build_right_edge(i, j);
        build_up_edge(i, j);
        build_down_edge(i, j);
      }
    }
  }
}

bool dfs(int i, int j) {
  Coord c = Coord(i, j);
  if (unvisited.find(c) != unvisited.end()) {
    unvisited.erase(c);
    for (auto w : edges[c]) {
      dfs(w.first, w.second);
    }
    return true;
  } else {
    return false;
  }
}

int ans = 0;

void solve() {
  unvisited.clear();
  edges.clear();
  ans = 0;

  build_graph();

  for (auto [src, _] : edges) {
    if (dfs(src.first, src.second)) {
      ans++;
    }
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        board[i][j] = 0;
      }
    }
    for (int k = 0; k < K; k++) {
      int X, Y;
      scanf("%d %d", &X, &Y);
      board[Y][X] = 1;
    }

    solve();

    printf("%d\n", ans);
  }

  return 0;
}
