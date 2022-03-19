#include <bits/stdc++.h>

using namespace std;

int N;
int P[1001];
int T[1001];
int ans;

// Merge Sort
void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (P[l] < P[r]) {
      T[p] = P[l];
      p++;
      l++;
    } else {
      T[p] = P[r];
      p++;
      r++;
    }
  }

  for (int i = r; i <= right; i++) {
    T[p] = P[i];
    p++;
  }
  for (int i = l; i <= mid; i++) {
    T[p] = P[i];
    p++;
  }

  for (int i = left; i <= right; i++) {
    P[i] = T[i];
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

  int cur = 0;
  for (int i = 1; i <= N; i++) {
    ans += cur + P[i];
    cur += P[i];
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &P[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
