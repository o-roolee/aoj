#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> A, int N) {
  for (int i = 0; i < N; i++) {
    if (i != 0) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int count = 0;
  int minj;

  for (int i = 0; i <= N-2; i++) {
    minj = i;

    for (int j = i+1; j < N; j++) {
      if (A.at(j) < A.at(minj)) minj = j;
    }

    if (i != minj) {
      swap(A.at(i), A.at(minj));
      count++;
    }
  }


  trace(A, N);
  cout << count << endl;

  return 0;
}
