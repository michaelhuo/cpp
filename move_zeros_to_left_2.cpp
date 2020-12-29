void move_zeros_to_left(int A[], int n) {
  //TODO: Write - Your - Code 
  if (!A || n < 2) {
    return;
  }
  int read_index = n - 1, write_index = n - 1;
  while (read_index >= 0) {
    if (A[read_index] != 0) {
      A[write_index] = A[read_index];
      write_index --;
    }
    read_index --;
  }
  while (write_index >= 0) {
    A[write_index] = 0;
    write_index --;
  }
}
