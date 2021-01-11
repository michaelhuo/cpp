typedef LinkedListNode* node_ptr;

node_ptr find_premid(node_ptr head) {
  if (!head) {
    return nullptr;
  }
  node_ptr prev = nullptr, slow = head, fast = head->next;
  if (!fast) {
    return nullptr;
  }
  while (slow && slow->next && fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  return prev;
}

node_ptr merge(node_ptr head1, node_ptr head2) {
  if (!head1) {
    return head2;
  } else if (!head2) {
    return head1;
  }
  node_ptr head = nullptr;
  if (head1->data < head2->data) {
    head = head1;
    head1 = head1->next;
  } else {
    head = head2;
    head2 = head2->next;
  }
  node_ptr node = head;
  while (head1 && head2) {
    if (head1->data < head2->data) {
      node->next = head1;
      head1 = head1->next;
    } else {
      node->next = head2;
      head2 = head2->next;
    }
    node = node->next;
  }
  if (head1) {
    node->next = head1;
  }
  if (head2) {
    node->next = head2;
  }
  return head;
}

node_ptr merge_sort(node_ptr head) {
  //TODO: Write - Your - Code
  if (!head) {
    return head;
  }
  node_ptr prev = find_premid(head);
  if (!prev || !prev->next) {
    return head;
  }
  node_ptr head2 = prev->next;
  prev->next = nullptr;
  return(merge(merge_sort(head), merge_sort(head2))); 
} 



