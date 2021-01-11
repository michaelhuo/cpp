LinkedListNode* find_nth_from_last(LinkedListNode* head, int n) {
  //TODO: Write - Your - Code
  LinkedListNode* node = head, *node2 = head;
  while (n > 0) {
    node = node->next;
    n --;
  }
  if (!node) {
    return nullptr;
  }
  while (node) {
    node = node->next;
    node2 = node2->next;
  }
  return node2;
}
