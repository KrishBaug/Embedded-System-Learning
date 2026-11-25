// reversing an array using pointer arithematic
// start    /* 1000: the address of number */
// *start   /* 10: the value stored at address 1000 */
// &start   /* 2000: the address where start itself is stored */l

#include <stddef.h>
#include <stdio.h>

void reverse_array(int *arr, int size);
void print_arr(int *arr, int size);

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int size = 5;
  reverse_array(arr, size);
  print_arr(arr, size);

  return 0;
}

void reverse_array(int *arr, int size) {
  int *start = arr;
  int *end = arr + size - 1;
  int temp;
  while (start < end) {
    temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }
}

void print_arr(int *arr, int size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}
