#include <bits/stdc++.h>

using namespace std;

int A, B;

void solve() {
  if (B % A == 0) {
    printf("factor\n");
  } else if (A % B == 0) {
    printf("multiple\n");
  } else {
    printf("neither\n");
  }
}

int main() {
  while (1) {
    scanf("%d %d", &A, &B);

    if (A == 0 && B == 0) {
      break;
    }

    solve();
  }

  return 0;
}
