// Node indices starts from 1.
LinkedListNode* swap_nth_node(LinkedListNode* head, int n) {
  //TODO: Write - Your - Code
  if (!head || n < 1) {
    return head;
  }
  LinkedListNode * node = head;
  while (n > 2 && node->next) {
    node = node->next;
    n --;
  }
  if (!node) {
    return head;
  }
  LinkedListNode* prev, *curr, *tmp;
  prev = node;
  curr = node->next;
  tmp = head->next;
  head->next = curr->next;
  prev->next = head;
  curr->next = tmp;
  return curr;
}
