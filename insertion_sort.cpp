LinkedListNode* insertion_sort(LinkedListNode* head) {
   //TODO: Write - Your - Code
    if (!head) {
        return head;
    }
    LinkedListNode* dummy = new LinkedListNode(-1);
    LinkedListNode* node = head;
    while (node) {
        LinkedListNode* curr = dummy, * prev = nullptr, * tmp = node->next;
        int data = node->data;
        while (curr && curr->data < data) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = node;
        node->next = curr;
        node = tmp;
    }
    return dummy->next;
}
