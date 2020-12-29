void move_zeros_to_left(int A[], int n) {
  //TODO: Write - Your - Code 
  if (!A) {
    return;
  }
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i] == 0) {
      ++count;
    }
  }
  if (count == 0 || count == n) {
    return;
  }
  int write = n - 1;
  while (write >=0 && A[write] != 0) {
    --write;
  }
  if (write <= 0) {
    return;
  }
  int read = write - 1;
  while (count >= 0 && read >=0 && write >= 0) {
    if (A[read] != 0) {
      A[write] = A[read];
      --write;
    } else {
      --count;
    }
    --read;
  }
  while (write >= 0) {
    A[write] = 0;
    --write;
  }
  return;
}
