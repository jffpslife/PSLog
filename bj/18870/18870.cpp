#include <bits/stdc++.h>

using namespace std;

struct Num {
  int x;
  int y;
};

int N;
struct Num P[1000001];
int I[1000001];
int T[1000001];

bool compare1(int n1, int n2) {
  return P[n1].x < P[n2].x;
}

bool compare2(int n1, int n2) {
  return P[n1].y < P[n2].y;
}

void merge(int step, int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (step == 1) {
      if (compare1(I[l], I[r])) {
        T[p] = I[l];
        p++;
        l++;
      } else {
        T[p] = I[r];
        p++;
        r++;
      }
    } else {
      if (compare2(I[l], I[r])) {
        T[p] = I[l];
        p++;
        l++;
      } else {
        T[p] = I[r];
        p++;
        r++;
      }
    }
  }

  for (int i = r; i <= right; i++) {
    T[p] = I[i];
    p++;
  }
  for (int i = l; i <= mid; i++) {
    T[p] = I[i];
    p++;
  }

  for (int i = left; i <= right; i++) {
    I[i] = T[i];
  }
}

// XXX: Inclusive
void merge_sort(int step, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(step, left, mid);
    merge_sort(step, mid + 1, right);
    merge(step, left, mid, right);
  }
}

void solve() {
  merge_sort(1, 1, N);

  int new_x = 0;
  int cur_x = P[I[1]].x;
  for (int i = 1; i <= N; i++) {
    if (P[I[i]].x != cur_x) {
      new_x++;
      cur_x = P[I[i]].x;
    }
    P[I[i]].x = new_x;
  }

  merge_sort(2, 1, N);
}

void print(int i) {
  printf("%d ", P[I[i]].x);
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &P[i].x);
    P[i].y = i;
    I[i] = i;
  }

  solve();

  for (int i = 1; i <= N; i++) {
    print(i);
  }
  printf("\n");

  return 0;
}
