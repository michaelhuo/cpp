LinkedListNode* reverse(LinkedListNode* head) {
  if (!head) {
    return head;
  }
  LinkedListNode* prev = nullptr, *node = head;
  while (node) {
    LinkedListNode* tmp = node->next;
    node->next = prev;
    prev = node;
    node = tmp;
  }
  return prev;
}
