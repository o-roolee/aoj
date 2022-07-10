#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int cnt;

void insertionSort(int *A, int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
        A[j+g] = A[j];
        j -= g;
        cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int *A, int n) {
  cnt = 0;
  int r = 1;
  vector<int> G;

  while (r <= n) {
    G.push_back(r);
    r *= 2;
  }

  int m = G.size();
  reverse(G.begin(), G.end());

  cout << m << endl;
  rep(i, m) cout << G[i] << " \n" [i == m-1];
  rep(i, m) insertionSort(A , n , G[i]);
  cout << cnt << endl;
}

int main() {
  int n;
  cin >> n;

  int A[n];
  rep(i, n) cin >> A[i];

  shellSort(A, n);
  rep(i, n) cout << A[i] << endl;

  return 0;
}
