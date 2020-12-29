int find_low_index(vector<int>& arr, int key) {
  //TODO: Write - Your - Code
  if (arr.empty()) {
    return -1;
  }
  int size = arr.size();
  int low = 0, high = size - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  if (low < size && arr[low] == key) {
    while (low > 0 && arr[low - 1] == key) {
      low --;
    }
    return low;
  }
  return -1;
}

int find_high_index(vector<int>& arr, int key) {
  //TODO: Write - Your - Code
  if (arr.empty()) {
    return -1;
  }
  int size = arr.size();
  int low = 0, high = size - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid;
    }
  } 
  if (low < size && arr[low] == key) {
    while (low < size - 1 && arr[low + 1] == key) {
      low ++;
    }
    return low;
  }
  return -1;
}
