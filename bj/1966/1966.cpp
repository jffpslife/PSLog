#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
int I[101];
int S[101];
int U[101];

// Merge Sort
void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (S[l] > S[r]) {
      U[p] = S[l];
      p++;
      l++;
    } else {
      U[p] = S[r];
      p++;
      r++;
    }
  }

  for (int i = r; i <= right; i++) {
    U[p] = S[i];
    p++;
  }
  for (int i = l; i <= mid; i++) {
    U[p] = S[i];
    p++;
  }

  for (int i = left; i <= right; i++) {
    S[i] = U[i];
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

list<int> q1;
list<int> q2;

int ans;

void solve() {
  merge_sort(1, N);

  ans = 0;
  q1.clear();
  q2.clear();
  for (int i = 1; i <= N; i++) {
    q1.push_back(i);
    q2.push_back(S[i]);
  }

  int item;
  int p;
  while (1) {
    while (1) {
      item = q1.front();
      q1.pop_front();
      p = I[item];
      if (p == q2.front()) {
        q2.pop_front();
        break;
      } else {
        q1.push_back(item);
      }
    }
    if (M != item - 1) {
      ans++;
    } else {
      ans++;
      break;
    }
  }
}

int main() {
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d %d", &N, &M);
    for (int j = 1; j <= N; j++) {
      scanf("%d", &I[j]);
      S[j] = I[j];
    }

    solve();

    printf("%d\n", ans);
  }

  return 0;
}
