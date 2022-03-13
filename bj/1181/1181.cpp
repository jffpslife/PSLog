#include <bits/stdc++.h>

using namespace std;

struct Word {
  char buf[51];
  int l;
};

int N;
struct Word W[20001];
int I[20001];
int T[20001];

bool compare(int n1, int n2) {
  if (W[n1].l == W[n2].l) {
    for (int i = 0; i < W[n1].l; i++) {
      if (W[n1].buf[i] != W[n2].buf[i]) {
        return W[n1].buf[i] < W[n2].buf[i];
      }
    }
    return false;
  } else {
    return W[n1].l < W[n2].l;
  }
}

void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (compare(I[l], I[r])) {
      T[p] = I[l];
      p++;
      l++;
    } else {
      T[p] = I[r];
      p++;
      r++;
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
void merge_sort(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);
  }
}

void solve() {
  merge_sort(1, N);
}

void print(int i) {
  if (i > 1) {
    if (!strcmp(W[I[i-1]].buf, W[I[i]].buf)) {
      return;
    }
  }
  printf("%s\n", W[I[i]].buf);
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%s", W[i].buf);
    W[i].l = strlen(W[i].buf);
    I[i] = i;
  }

  solve();

  for (int i = 1; i <= N; i++) {
    print(i);
  }

  return 0;
}
