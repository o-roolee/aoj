#include <bits/stdc++.h>
using namespace std;


struct Process {
  string name;
  int time;
};

int main() {
  int N;
  int q;
  queue<struct Process> que;
  queue<struct Process> ans;


  cin >> N >> q;

  for (int i = 0; i < N; i++) {
    struct Process p;
    cin >> p.name >> p.time;
    que.push(p);
  }

  int elapsed = 0; // 経過時間

  while (!que.empty()) {
    struct Process p = que.front();
    que.pop();

    if (p.time > q) {
      elapsed += q;
      p.time -= q;
      que.push(p);
    } else {
      elapsed += p.time;

      struct Process ans_p;
      ans_p.name = p.name;
      ans_p.time = elapsed;
      ans.push(ans_p);
    }

  }


  while (!ans.empty()) {
    struct Process ans_p = ans.front();
    ans.pop();
    cout << ans_p.name << " " << ans_p.time << endl;
  }

  return 0;
}
