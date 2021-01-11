#include <unordered_set>
using namespace std;
LinkedListNode* remove_duplicates(LinkedListNode* head){
 //TODO: Write - Your - Code
  if (!head) {
    return head;
  }
  LinkedListNode* result = head;
  unordered_set<int> keys;
  LinkedListNode* node = result->next;
  LinkedListNode* curr = result;
  keys.insert(result->data);
  while (node) {
    int data = node->data;
    if (keys.find(data) == end(keys)) {
      keys.insert(data);
      curr->next = node;
      curr = curr->next;
    }
    node = node->next;
  }
  curr->next = nullptr;
  return result;
}
