#include <bits/stdc++.h>

using namespace std;

int N;
char op[20];
int operand;
list<int> dq;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%s", op);
    if (!strcmp(op, "push_front") || !strcmp(op, "push_back")) {
      scanf("%d", &operand);
    }

    if (!strcmp(op, "push_front")) {
      dq.push_front(operand);
    } else if (!strcmp(op, "push_back")) {
      dq.push_back(operand);
    } else if (!strcmp(op, "pop_front")) {
      if (dq.empty()) {
        printf("-1\n");
      } else {
        int item = dq.front();
        dq.pop_front();
        printf("%d\n", item);
      }
    } else if (!strcmp(op, "pop_back")) {
      if (dq.empty()) {
        printf("-1\n");
      } else {
        int item = dq.back();
        dq.pop_back();
        printf("%d\n", item);
      }
    } else if (!strcmp(op, "size")) {
      printf("%d\n", dq.size());
    } else if (!strcmp(op, "empty")) {
      if (dq.empty()) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if (!strcmp(op, "front")) {
      if (dq.empty()) {
        printf("-1\n");
      } else {
        int item = dq.front();
        printf("%d\n", item);
      }
    } else if (!strcmp(op, "back")) {
      if (dq.empty()) {
        printf("-1\n");
      } else {
        int item = dq.back();
        printf("%d\n", item);
      }
    }
  }

  return 0;
}
