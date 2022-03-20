#include <bits/stdc++.h>

using namespace std;

char s[200];
list<int> st;

int main() {
  while (1) {
    fgets(s, 200, stdin);
    s[strlen(s) - 1] = '\0';
    if (!strcmp(".", s)) {
      break;
    }

    st.clear();
    bool b = true;
    for (int i = 0; i < strlen(s); i++) {
      char c = s[i];
      if (c == '(') {
        st.push_back(0);
      } else if (c == '[') {
        st.push_back(1);
      } else if (c == ']') {
        if (st.size() > 0) {
          int item = st.back();
          st.pop_back();
          if (item != 1) {
            b = false;
            break;
          }
        } else {
          b = false;
          break;
        }
      } else if (c == ')') {
        if (st.size() > 0) {
          int item = st.back();
          st.pop_back();
          if (item != 0) {
            b = false;
            break;
          }
        } else {
          b = false;
          break;
        }
      }
    }

    if (st.size() > 0) {
      b = false;
    }

    if (b) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}
