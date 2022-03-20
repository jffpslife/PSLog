#include <bits/stdc++.h>

using namespace std;

int T;
int ans;

int n;
int a[1001];
int t[1001];

// Merge Sort
void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (a[l] < a[r]) {
      t[p] = a[l];
      p++;
      l++;
    } else {
      t[p] = a[r];
      p++;
      r++;
    }
  }

  for (int i = r; i <= right; i++) {
    t[p] = a[i];
    p++;
  }
  for (int i = l; i <= mid; i++) {
    t[p] = a[i];
    p++;
  }

  for (int i = left; i <= right; i++) {
    a[i] = t[i];
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
  merge_sort(1, n);
  int first = a[n];
  int second = a[n-1];
  ans = first + second;
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }

    solve();

    printf("%d\n", ans);
  }

  return 0;
}
