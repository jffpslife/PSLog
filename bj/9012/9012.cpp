#include <bits/stdc++.h>

using namespace std;

int T;
char S[51];
int h = 0;

int main() {
  scanf("%d", &T);

  for (int i = 1; i <= T; i++) {
    scanf("%s", S);

    h = 0;
    bool isValid = true;
    for (int j = 0; j < strlen(S); j++) {
      char c = S[j];
      if (c == '(') {
        h++;
      } else if (c == ')') {
        if (h > 0) {
          h--;
        } else {
          isValid = false;
          break;
        }
      }
    }
    if (h != 0) {
      isValid = false;
    }

    if (isValid) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
