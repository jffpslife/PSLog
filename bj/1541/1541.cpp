#include <bits/stdc++.h>

using namespace std;

char s[50];
int ans;

void solve() {
  bool in_minus = false;
  int n = 0;
  for (int i = 0; i < strlen(s); i++) {
    switch (s[i]) {
      case '-':
        if (in_minus) {
          ans -= n;
        } else {
          ans += n;
        }
        in_minus = true;
        n = 0;
        break;
      case '+':
        if (in_minus) {
          ans -= n;
        } else {
          ans += n;
        }
        n = 0;
        break;
      default:
        n = 10 * n + s[i] - '0';
        break;
    }
  }
  if (in_minus) {
    ans -= n;
  } else {
    ans += n;
  }
}

int main() {
  scanf("%s", s);

  solve();

  printf("%d\n", ans);

  return 0;
}
