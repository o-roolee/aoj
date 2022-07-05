#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

vector<int> &insertionSort(vector<int> &A, int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A.at(i);
    int j = i - g;
    while (j >= 0 && A[j] > v) {
        A[j+g] = A[j];
        j = j - g;
        cnt++;
    }
    A[j+g] = v;
  }

  return A;
}

vector<int> &shellSort(vector<int> &A, int n) {
  vector<int> G;
  int r = 1;
  while (r <= n) {
    G.push_back(r);
    r *= 2;
  }

  int m = G.size();
  reverse(G.begin(),G.end());

  cout << m << endl;
  for(int i = 0; i < m; i++) cout << G.at(i) << " \n" [i == m-1];

  for(int i = 0; i < m; i++) A = insertionSort(A , n , G.at(i));
  cout << cnt << endl;

  return A;
}

int main() {
  int n;
  vector<int> A(n);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> A.at(i);

  A = shellSort(A, n);
  for(int k = 0; k < n; k++) cout << A.at(k) << endl;

  return 0;
}
