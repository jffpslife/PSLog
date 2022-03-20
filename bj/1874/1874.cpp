#include <bits/stdc++.h>

using namespace std;

int N;
int A[100001];
char ans[200000];
list<int> st;

void solve() {
  int ptr = 1;
  int n = 1;
  bool suc = true;
  for (int i = 0; i < 2 * N; i++) {
    if (n <= A[ptr]) {
      ans[i] = '+';
      st.push_back(n);
      n++;
    } else {
      if (st.size() > 0) {
        int item = st.back();
        if (item == A[ptr]) {
          ans[i] = '-';
          st.pop_back();
          ptr++;
        } else {
          suc = false;
          break;
        }
      } else {
        suc = false;
        break;
      }
    }
  }

  if (suc) {
    for (int i = 0; i < 2 * N; i++) {
      printf("%c\n", ans[i]);
    }
  } else {
    printf("NO\n");
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  solve();

  return 0;
}
