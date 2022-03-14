#include <bits/stdc++.h>

using namespace std;

int T, N;
long long table[120];

void build() {
  table[1] = 1;
  table[2] = 1;
  table[3] = 1;
  table[4] = 2;
  table[5] = 2;
  table[6] = 3;
  table[7] = 4;
  table[8] = 5;
  table[9] = 7;
  table[10] = 9;
  table[11] = 12;

  int i = 12;
  while (i <= 100) {
    table[i] = table[i-1] + table[i-5];
    table[i+1] = table[i] + table[i-4];
    table[i+2] = table[i+1] + table[i-3];
    table[i+3] = table[i+2] + table[i-2];
    table[i+4] = table[i+3] + table[i-1];
    table[i+5] = table[i+4] + table[i];
    i += 6;
  }
}

int main() {
  scanf("%d", &T);
  build();

  for (int i = 1; i <= T; i++) {
    scanf("%d", &N);

    printf("%lld\n", table[N]);
  }

  return 0;
}
