LinkedListNode* intersect(LinkedListNode* head1, LinkedListNode* head2) {
  //TODO: Write - Your - Code
  if (!head1 || !head2) {
    return nullptr;
  }
  LinkedListNode* node, *node2;
  int size = 0, size1 = 0, size2 = 0;
  node = head1;
  while (node) {
    node = node->next;
    size1 ++;
  }
  node = head2;
  while (node) {
    node = node->next;
    size2 ++;
  }
  if (size1 < size2) {
    node = head2;
    node2 = head1;
    size = size2 - size1;
  } else {
    node = head1;
    node2 = head2;
    size = size1 - size2;
  }
  for(int i = 0; i < size; ++i) {
    node = node->next;
  }
  LinkedListNode* result = nullptr;
  while (node && node2) {
    if (node == node2) {
      if (!result) {
        result = node;
      }
    } else {
      result = nullptr;
    }
    node = node->next;
    node2 = node2->next;
  }

  return result;
}
