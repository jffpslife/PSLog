// typedef. I'll use B
typedef A B;

// Merge Sort
void merge(int left, int mid, int right) {
  int l = left;
  int r = mid + 1;
  int p = left;

  while (l <= mid && r <= right) {
    if (COMPARE(ARR[l], ARR[r])) {
      SORTED[p] = ARR[l];
      p++;
      l++;
    } else {
      SORTED[p] = ARR[r];
      p++;
      r++;
    }
  }

  for (int i = r; i <= right; i++) {
    SORTED[p] = ARR[i];
    p++;
  }
  for (int i = l; i <= mid; i++) {
    SORTED[p] = ARR[i];
    p++;
  }

  for (int i = left; i <= right; i++) {
    ARR[i] = SORTED[i];
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

// LCS
int DP[L1][L2];
int B[L1][L2];

int dp(char *S1, char *S2, int i, int j) {
  if (B[i][j]) {
    return DP[i][j];
  } else {
    if (i < 0 || j < 0) {
      return 0;
    } else {
      if (S1[i] == S2[j]) {
        int res = dp(i - 1, j - 1) + 1;
        B[i][j] = true;
        DP[i][j] = res;
        return res;
      } else {
        int res1 = dp(i - 1, j);
        int res2 = dp(i, j - 1);
        int res = max(res1, res2);
        B[i][j] = true;
        DP[i][j] = res;
        return res;
      }
    }
  }
}

void lcs(char *S1, char *S2, int L1, int L2) {
  return dp(S1, S2, L1 - 1, L2 - 1);
}

int egcd(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  } else {
    int x_, y_;
    int g = egcd(b % a, a, &x_, &y_);

    *x = y_ - (b / a) * x_;
    *y = x_;

    return g;
  }
}

int mod_inv(int a, int m) {
  int x, y;
  int g = egcd(a, m, &x, &y);
  // Assume g is 1
  return (x % m + m) % m;
}

set<T> dfs_visited;
list<T> dfs_edges[N];
void dfs(T v) {
  dfs_visited.insert(v);
  for (auto s : dfs_edges[v]) {
    if (dfs_visited.find(s) == dfs_visited.end()) {
      dfs(s);
    }
  }
}

set<T> bfs_visited;
list<T> bfs_queue;
list<T> bfs_edges[N];
void bfs(T v) {
  bfs_queue.push_back(v);
  while (!bfs_queue.empty()) {
    int v = bfs_queue.front();
    bfs_queue.pop_front();
    if (bfs_visited.find(v) == bfs_visited.end()) {
      bfs_visited.insert(v);
      for (auto s : bfs_edges[v]) {
        bfs_queue.push_back(s);
      }
    }
  }
}
