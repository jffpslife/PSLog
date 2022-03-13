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
