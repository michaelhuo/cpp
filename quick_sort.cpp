#include <cstdlib>
int partition(int* arr, int left, int right) {
  if (right - left < 1) {
    return -1;
  }
  if (right - left == 1) {
    if (arr[left] > arr[right]) {
      int tmp = arr[right];
      arr[right] = arr[left];
      arr[left] = tmp;
      return -1;
    }
  }
  int pivot_index = rand() % (right - left + 1) + left;
  int pivot = arr[pivot_index];
  arr[pivot_index] = arr[right];
  arr[right] = pivot;
  int j = left;
  while (j < right && arr[j] < arr[j + 1]) {
    j++;
  }
  if (j == right) {
    return j;
  }
  int i = j + 1;
  while (i < right) {
    if (arr[i] < pivot) {
      int tmp = arr[j];
      arr[j] = arr[i];
      arr[i] = tmp;
      j++;
    }
    i++;
  }
  pivot = arr[right];
  arr[right] = arr[j];
  arr[j] = pivot;
  return j;
}

void helper(int* arr, int left, int right) {
  int pivot_index = partition(arr, left, right);
  if (pivot_index == -1) {
    return;
  }
  helper(arr, 0, pivot_index - 1);
  helper(arr, pivot_index + 1, right);
}

void quick_sort(int arr[], int size) {
  if (size < 2) {
    return;
  }
  helper(arr, 0, size - 1);
}
