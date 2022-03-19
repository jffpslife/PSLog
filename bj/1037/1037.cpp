#include <bits/stdc++.h>

using namespace std;

int N;
int A[51];
int T[51];

int ans;

// Merge Sort
void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (A[l] < A[r]) {
      T[p] = A[l];
      p++;
      l++;
    } else {
      T[p] = A[r];
      p++;
      r++;
    }
  }

  for (int i = r; i <= right; i++) {
    T[p] = A[i];
    p++;
  }
  for (int i = l; i <= mid; i++) {
    T[p] = A[i];
    p++;
  }

  for (int i = left; i <= right; i++) {
    A[i] = T[i];
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
  ans = A[1] * A[N];
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
