#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, q;
  cin >> n >> q;

  queue<pair<string, int> > Q;
  int time;
  string name;

  for (int i = 0; i < n; i++) {
    cin >> name >> time;
    Q.push(make_pair(name, time));
  }

  int elaps = 0; // 経過時間

  while (!Q.empty()) {
    pair<string, int> u = Q.front();
    Q.pop();

    int a = min(u.second, q);
    u.second -= a;
    elaps += a;

    if (u.second > 0) {
      Q.push(u);
    } else {
      cout << u.first << " " << elaps << endl;
    }
  }
  return 0;
}
