LinkedListNode* delete_node(LinkedListNode* head, int key) {
 //TODO: Write - Your - Code
  LinkedListNode* dummy = new LinkedListNode(-1);
  dummy->next = head;
  LinkedListNode* prev = dummy;
  LinkedListNode* node = dummy->next;
  while (node) {
    if (node->data != key) {
      prev->next = node;
      prev = prev->next;
    }
    node = node->next;
  }
  prev->next = nullptr;
  node = dummy->next;
  delete dummy;
  return node;
}
