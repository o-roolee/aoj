#include <bits/stdc++.h>
using namespace std;


int main() {
  string x;
  getline(cin, x);
  stringstream ss(x);

  stack<int> stk;


  while (getline(ss, x, ' ')) {
    if (x == "+" || x == "-" || x == "*" || x == "/") {
      stk = operate(stk, x);
    } else {
      stk.push(atoi(x.c_str()));
    }
  }

  cout << stk.top() << endl;
  return 0;
}
