#include <bits/stdc++.h>

using namespace std;

int t, n;
map<string, int> cnt;

char s1[20];
char s2[20];

int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    cnt.clear();
    for (int j = 1; j <= n; j++) {
      scanf("%s %s", s1, s2);
      string s = string(s2);
      if (cnt.find(s) == cnt.end()) {
        cnt.insert(pair<string, int>(s, 1));
      } else {
        cnt[s] = cnt[s] + 1;
      }
    }

    int ans = 1;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
      ans *= (it->second + 1);
    }
    ans--;
    printf("%d\n", ans);
  }

  return 0;
}
