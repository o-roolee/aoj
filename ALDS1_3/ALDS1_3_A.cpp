#include <bits/stdc++.h>
using namespace std;


void trace(stack<int> A, int N) {
  for (int i = 0; i < N; i++) {
    if (i != 0) cout << " ";
    cout << A.top();
  }
  cout << endl;
}


stack<int> operate(stack<int> stk, string operand) {
  int var2 = stk.top(); stk.pop();
  int var1 = stk.top(); stk.pop();

  if(operand == "+") stk.push(var1 + var2);
  if(operand == "-") stk.push(var1 - var2);
  if(operand == "*") stk.push(var1 * var2);
  if(operand == "/") stk.push(var1 / var2);

  return stk;
}

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
