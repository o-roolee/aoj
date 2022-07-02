#include <bits/stdc++.h>
using namespace std;

struct Card { char suit, value; };

void trace(struct Card A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i != 0) cout << " ";
    cout << A[i].suit << A[i].value;
  }
  cout << endl;
}

void bubbleSort(struct Card A[], int N) {
  for (int i = 0; i <= N-2; i++) {
    for (int j = N-1; j > i; j--) {
      if (A[j].value < A[j-1].value) {
        swap(A[j], A[j-1]);
      }
    }
  }
}

void selectionSort(struct Card A[], int N) {
  for (int i = 0; i < N; i++) {
    int minj = i;

    for (int j = i; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
      }
    }

    swap(A[minj], A[i]);
  }
}

bool isStable(struct Card C1[], struct Card C2[], int N) {
  for (int i = 0; i < N; i++) {
    if (C1[i].suit != C2[i].suit ||
        C1[i].value != C2[i].value) {
          return false;
    }
  }

  return true;
}

string makeMessage(struct Card A1[], struct Card A2[], int N) {
  if (isStable(A1, A2, N)) {
    return "Stable";
  } else {
    return "Not stable";
  }

}

int main() {
  Card C1[100], C2[100];
  int N;
  char ch;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> C1[i].suit >> C1[i].value;
    C2[i] = C1[i];
  }

  bubbleSort(C1, N);
  trace(C1, N);
  cout << makeMessage(C1, C1, N) << endl;

  selectionSort(C2, N);
  trace(C2, N);
  cout << makeMessage(C1, C2, N) << endl;

  return 0;
}
