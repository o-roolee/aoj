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

  int ans = 0;
  bool flag = true;

  for (int i = 1; i <= N-1; i++) {
    flag = false;

    for (int j = 1; j <= N-i; j++) {
      if (A.at(j-1) > A.at(j)) {
        swap(A.at(j-1), A.at(j));
        ans++;
        flag = true;
      }

    }
  }

  trace(A, N);
  cout << ans << endl;

  return 0;
}
