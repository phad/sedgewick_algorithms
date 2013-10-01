#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int i;
  struct _node* next;
} node;

node* add(int v, node* prev) {
  node* n = malloc(sizeof(node));
  n->i = v;
  n->next = NULL;
  if (prev) {
    prev->next = n;
  }
  return n;
}

void del(node* head) {
  node* next = NULL;
  while (head) {
    next = head->next;
    free(head);
    head = next;
  }
}

void output(node* n) {
  printf("HEAD: ");
  while (n) {
    printf("%d -> ", n->i);
    n = n->next;
  }
  printf("NULL\n");
}

node* reverse(node* root) {
  node* new_root = 0;
  while (root) {
    node* next = root->next;
    root->next = new_root;
    new_root = root;
    output(new_root);
    root = next;
    output(root);
  }
  return new_root;
}

int main(int argc, char** argv) {
  node* head = add(1, NULL);
  node* next = add(2, head);
  next = add(3, next);
  add(4, next);
  output(head);
  node* reversed = reverse(head);
  output(reversed);
  del(reversed);
  return 0;
}
