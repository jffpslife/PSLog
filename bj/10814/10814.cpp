#include <bits/stdc++.h>

using namespace std;

struct Person {
  int age;
  char name[101];
};

int N;
struct Person P[100001];
int I[100001];
int T[100001];

bool compare(int n1, int n2) {
  if (P[n1].age == P[n2].age) {
    return n1 < n2;
  } else {
    return P[n1].age < P[n2].age;
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
  printf("%d %s\n", P[I[i]].age, P[I[i]].name);
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d %s", &P[i].age, P[i].name);
    I[i] = i;
  }

  solve();

  for (int i = 1; i <= N; i++) {
    print(i);
  }

  return 0;
}
