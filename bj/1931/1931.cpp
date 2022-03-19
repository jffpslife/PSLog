#include <bits/stdc++.h>

using namespace std;

int N;
int S[100001];
int E[100001];

int TS[100001];
int TE[100001];

bool compare(int i, int j) {
  if (S[i] == S[j]) {
    return E[i] > E[j];
  } else {
    return S[i] > S[j];
  }
}

// Merge Sort
void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (compare(l, r)) {
      TS[p] = S[l];
      TE[p] = E[l];
      p++;
      l++;
    } else {
      TS[p] = S[r];
      TE[p] = E[r];
      p++;
      r++;
    }
  }

  for (int i = r; i <= right; i++) {
    TS[p] = S[i];
    TE[p] = E[i];
    p++;
  }
  for (int i = l; i <= mid; i++) {
    TS[p] = S[i];
    TE[p] = E[i];
    p++;
  }

  for (int i = left; i <= right; i++) {
    S[i] = TS[i];
    E[i] = TE[i];
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

int maxE = 0;
int ans = 0;

void solve() {
  merge_sort(1, N);

  int cur = maxE;
  for (int i = 1; i <= N; i++) {
    if (cur >= E[i]) {
      ans += 1;
      cur = S[i];
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &S[i], &E[i]);
    maxE = max(maxE, E[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
