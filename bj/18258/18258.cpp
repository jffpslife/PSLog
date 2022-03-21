#include <bits/stdc++.h>

using namespace std;

int N;
char op[10];
int operand;
list<int> q;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%s", op);
    if (!strcmp(op, "push")) {
      scanf("%d", &operand);
    }

    if (!strcmp(op, "push")) {
      q.push_back(operand);
    } else if (!strcmp(op, "pop")) {
      if (q.empty()) {
        printf("-1\n");
      } else {
        int item = q.front();
        q.pop_front();
        printf("%d\n", item);
      }
    } else if (!strcmp(op, "size")) {
      printf("%d\n", q.size());
    } else if (!strcmp(op, "empty")) {
      if (q.empty()) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if (!strcmp(op, "front")) {
      if (q.empty()) {
        printf("-1\n");
      } else {
        int item = q.front();
        printf("%d\n", item);
      }
    } else if (!strcmp(op, "back")) {
      if (q.empty()) {
        printf("-1\n");
      } else {
        int item = q.back();
        printf("%d\n", item);
      }
    }
  }

  return 0;
}
