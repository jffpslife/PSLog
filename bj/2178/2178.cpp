#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Coord;

int N, M;
int B[100][100];

map<Coord, int> nodes;
map<Coord, list<Coord>> edges;

void build_node(Coord &c) {
  nodes[c] = 10000;
  edges[c] = list<Coord>();
}

void build_left_edge(Coord &c) {
  if (c.second > 0) {
    if (B[c.first][c.second-1] == 1) {
      Coord dst = Coord(c.first, c.second-1);
      edges[c].push_back(dst);
    }
  }
}

void build_right_edge(Coord &c) {
  if (c.second < M - 1) {
    if (B[c.first][c.second+1] == 1) {
      Coord dst = Coord(c.first, c.second+1);
      edges[c].push_back(dst);
    }
  }
}

void build_up_edge(Coord &c) {
  if (c.first > 0) {
    if (B[c.first-1][c.second] == 1) {
      Coord dst = Coord(c.first-1, c.second);
      edges[c].push_back(dst);
    }
  }
}

void build_down_edge(Coord &c) {
  if (c.first < N - 1) {
    if (B[c.first+1][c.second] == 1) {
      Coord dst = Coord(c.first+1, c.second);
      edges[c].push_back(dst);
    }
  }
}

void build_graph() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (B[i][j] == 1) {
        Coord c = Coord(i, j);
        build_node(c);
        build_left_edge(c);
        build_right_edge(c);
        build_up_edge(c);
        build_down_edge(c);
      }
    }
  }
}

list<pair<Coord, int>> bfs_queue;
void bfs(Coord &v) {
  bfs_queue.push_back(pair<Coord, int>(v, 1));
  while (!bfs_queue.empty()) {
    pair<Coord, int> p = bfs_queue.front();
    Coord v = p.first;
    int d = p.second;
    bfs_queue.pop_front();
    if (d < nodes[v]) {
      nodes[v] = d;
      for (auto s : edges[v]) {
        bfs_queue.push_back(pair<Coord, int>(s, d+1));
      }
    }
  }
}

void solve() {
  build_graph();
  Coord c = Coord(0, 0);
  bfs(c);
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    char buf[101];
    scanf("%s", buf);
    for (int j = 0; j < M; j++) {
      B[i][j] = buf[j] - '0';
    }
  }

  solve();

  printf("%d\n", nodes[Coord(N-1, M-1)]);

  return 0;
}
