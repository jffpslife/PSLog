#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[51];
list<int> q;
int ans;

void solve() {
  for (int i = 1; i <= N; i++) {
    q.push_back(i);
  }

  for (int i = 1; i <= M; i++) {
    int pos;
    pos = 0;
    for (int item : q) {
      if (item == A[i]) {
        break;
      }
      pos++;
    }

    if (pos <= q.size() / 2) {
      while (q.front() != A[i]) {
        int item = q.front();
        q.pop_front();
        q.push_back(item);
        ans++;
      }
      q.pop_front();
    } else {
      while (q.front() != A[i]) {
        int item = q.back();
        q.pop_back();
        q.push_front(item);
        ans++;
      }
      q.pop_front();
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d", &A[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
