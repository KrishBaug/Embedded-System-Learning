// pass array to a function

#include <stdio.h>

int sum(int arr[], int n) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += arr[i];
  }
  return total;
}

int main(void) {
  int numbers[] = {2, 4, 6, 8};
  int n = sizeof(numbers) / sizeof(numbers[0]);

  printf("Sum: %d\n", sum(numbers, n));
  return 0;
}
