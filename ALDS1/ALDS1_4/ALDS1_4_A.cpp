#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> S(n+1);
  for (int i = 0; i < n; i++) {cin >> S.at(i); }

  int q;
  cin >> q;
  vector<int> T(q);
  for (int i = 0; i < q; i++) {cin >> T.at(i); }

  int ans = 0;
  S.at(n) = -1;

  for (int i = 0; i < q; i++) {
    int j = 0;
    int key = T.at(i);
    S.at(n) = key;

    while (S.at(j) != key) j++;
    if (j != n) ans++;
  }

  cout << ans << endl;
  return 0;
}
