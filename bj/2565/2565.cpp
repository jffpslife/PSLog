#include <bits/stdc++.h>

using namespace std;

int N;
int A[101];
int B[101];

int TA[101];
int TB[101];

bool compare(int a1, int a2) {
  return a1 < a2;
}

// Merge Sort
void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (compare(A[l], A[r])) {
      TA[p] = A[l];
      TB[p] = B[l];
      p++;
      l++;
    } else {
      TA[p] = A[r];
      TB[p] = B[r];
      p++;
      r++;
    }
  }

  for (int i = r; i <= right; i++) {
    TA[p] = A[i];
    TB[p] = B[i];
    p++;
  }
  for (int i = l; i <= mid; i++) {
    TA[p] = A[i];
    TB[p] = B[i];
    p++;
  }

  for (int i = left; i <= right; i++) {
    A[i] = TA[i];
    B[i] = TB[i];
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

void sort() {
  merge_sort(1, N);
}

int DP[101];
int ans = 1;

void dp() {
  DP[1] = 1;
  for (int i = 2; i <= N; i++) {
    DP[i] = 1;
    for (int j = i - 1; j >= 1; j--) {
      if (B[j] < B[i]) {
        DP[i] = max(DP[i], DP[j] + 1);
      }
    }
    ans = max(ans, DP[i]);
  }
}

void solve() {
  sort();
  dp();

  ans = N - ans;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
