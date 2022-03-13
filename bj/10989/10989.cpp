#include <bits/stdc++.h>

using namespace std;

int N;
int n[10001] = {0,};

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int t;
    scanf("%d", &t);
    n[t] += 1;
  }

  for (int i = 1; i <= 10001; i++) {
    for (int j = 0; j < n[i]; j++) {
      printf("%d\n", i);
    }
  }

  return 0;
}
