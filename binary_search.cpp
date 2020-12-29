int binary_search(int A[], int key, int len) {
  //TODO: Write - Your - Code
  if (!A || len < 1) {
    return -1;
  }
  int low = 0, high = len - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (A[mid] < key) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  if (low < len && A[low] == key) {
    return low;    
  }

  return -1;
}
