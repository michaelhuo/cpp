int binary_search_rotated(vector<int>& arr, int key) {
  // TODO: Write - Your - Code
  if (arr.empty() || arr.size() == 1 && arr[0] != key) {
    return -1;
  }
  int size = arr.size();
  int low = 0, high = size - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (key == arr[mid]) {
      return mid;
    } else if (key < arr[mid]) {
      if (arr[mid] < arr[high]) {
        high = mid - 1;
      } else if (key <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    } else {
      if (arr[mid] > arr[high]) {
        low = mid + 1;
      } else if (key <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  
  return -1;
}
