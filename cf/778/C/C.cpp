#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int T;
int ans;

int n;
int a[200001];
int t[200001];
ll s;
priority_queue<ll> qu;

// Merge Sort
void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (a[r] < a[l]) {
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

  int idx = 1;
  while (idx <= n) {
    ll c = qu.top();
    if (c > a[idx]) {
      if (c % 2) {
        qu.pop();
        qu.push((c / 2));
        qu.push((c / 2) + 1);
      } else {
        qu.pop();
        qu.push(c / 2);
        qu.push(c / 2);
      }
    } else if (c == a[idx]) {
      qu.pop();
      idx++;
    } else {
      break;
    }
  }

  if (idx == n + 1 && qu.empty()) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &n);
    s = 0;
    while (!qu.empty()) {
      qu.pop();
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      s += a[i];
    }
    qu.push(s);

    solve();
  }

  return 0;
}
