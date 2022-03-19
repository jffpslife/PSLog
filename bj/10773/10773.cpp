#include <bits/stdc++.h>

using namespace std;

int K;
int N;
list<int> s;
int ans;

int main() {
  scanf("%d", &K);

  for (int i = 1; i <= K; i++) {
    scanf("%d", &N);
    if (N == 0) {
      s.pop_back();
    } else {
      s.push_back(N);
    }
  }

  for (auto it = s.begin(); it != s.end(); it++) {
    ans += *it;
  }

  printf("%d\n", ans);

  return 0;
}
