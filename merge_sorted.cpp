typedef LinkedListNode* node_ptr;
node_ptr merge_sorted(node_ptr head1, node_ptr head2) {
  //TODO: Write - Your - Code
  if (!head1) {
    return head2;
  } else if (!head2) {
    return head1;
  }
  node_ptr node1 = head1;
  node_ptr node2 = head2;
  node_ptr node = new LinkedListNode(-1);
  node_ptr head = node;
  while (node1 && node2) {
    if (node1->data < node2->data) {
      node->next = node1;
      node1 = node1->next;
    } else {
      node->next = node2;
      node2 = node2->next;
    }
    node = node->next;
  }
  if (node1) {
    node->next = node1;
  }
  if (node2) {
    node->next = node2;
  }
  node = head->next;
  delete head;
  return node;
}
