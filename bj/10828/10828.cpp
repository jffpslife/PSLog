#include <bits/stdc++.h>

using namespace std;

int N;
char op[6];
int operand;
list<int> s;

int main() {
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    scanf("%s", op);
    if (!strcmp(op, "push")) {
      scanf("%d", &operand);
    }

    if (!strcmp(op, "push")) {
      s.push_back(operand);
    } else if (!strcmp(op, "pop")) {
      if (s.empty()) {
        printf("%d\n", -1);
      } else {
        int item = s.back();
        s.pop_back();
        printf("%d\n", item);
      }
    } else if (!strcmp(op, "size")) {
      printf("%d\n", s.size());
    } else if (!strcmp(op, "empty")) {
      if (s.empty()) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if (!strcmp(op, "top")) {
      if (s.empty()) {
        printf("%d\n", -1);
      } else {
        printf("%d\n", s.back());
      }
    }
  }

  return 0;
}
