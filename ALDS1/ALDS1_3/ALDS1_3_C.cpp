#include <bits/stdc++.h>
using namespace std;


struct node {
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil;

void init() {
  nil = (node *)malloc(sizeof(struct node));
  nil->next;
  nil->prev;
}

void insert(int key) {
  NodePointer x;
  x = (node *)malloc(sizeof(struct node));
  x->key = key;

  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

void deleteNode(NodePointer t) {
  if (t == nil) return;
  t->next->prev = t->prev;
  t->prev->next = t->next;
  free(t);
}

void deleteFirst() {
  deleteNode(nil->next);
}

void deleteLast() {
  deleteNode(nil->prev);
}

NodePointer listSearch(int key) {
  NodePointer cur;
  cur = nil->next;

  while (!(cur == nil || cur->key == key)) {
    cur = cur->next;
  }

  return cur;
}

void delete_by(int key) {
  deleteNode(listSearch(key));
}

// void printList(){
//   NodePointer cur = nil->next;
//   int isf = 1;
//   while(1){
//     if ( cur == nil ) break;
//     if ( isf == 0)  printf(" ");
//     printf("%d", cur->key);
//     cur = cur->next;
//     isf = 0;
//   }
//   printf("\n");
// }

int main(){
  int n;
  cin >> n;

  string command;
  int key;
  queue<pair<string, int>> Q;

  for (int i = 0; i < n; i++) {
    cin >> command >> key;
    Q.push(make_pair(command, key));
  }

  init();

  while (!Q.empty()) {
    pair<string, int> q = Q.front(); Q.pop();

    if (q.first == "insert") {
      insert(q.second);
    } else if (q.first == "delete") {
      delete_by(q.second);
    } else if (q.first == "deleteFirst") {
      deleteFirst();
    } else if (q.first == "deleteLast") {
      deleteLast();
    }
  }

  return 0;
}
