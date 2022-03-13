#include <bits/stdc++.h>

using namespace std;

struct Point {
  int X;
  int Y;
};

int N;
vector<Point> P;

bool compare(struct Point p1, struct Point p2) {
  if (p1.X == p2.X) {
    return p1.Y < p2.Y;
  } else {
    return p1.X < p2.X;
  }
}

void solve() {
  sort(P.begin() + 1, P.end(), compare);
}

void print(int i) {
  Point p = P[i];
  printf("%d %d\n", p.X, p.Y);
}

int main() {
  scanf("%d", &N);
  P.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    P[i].X = x;
    P[i].Y = y;
  }

  solve();

  for (int i = 1; i <= N; i++) {
    print(i);
  }

  return 0;
}
