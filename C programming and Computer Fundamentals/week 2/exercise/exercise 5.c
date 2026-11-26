// Write a C program to demonstrate how a function can modify multiple variables
// through pointers. Create a function named updateValues() that accepts the
// addresses of two integer variables as pointer parameters. Inside the
// function, double the value of the first variable and add 10 to the value of
// the second variable. In the main() function, declare and initialize two
// integer variables, display their values before calling the function, call
// updateValues() by passing the addresses of the variables using the address-of
// operator (&), and then display their updated values. The program should show
// that changes made inside the function are reflected in the original variables
// because pointers allow a function to access and modify the memory locations
// of the passed variables
#include <stdio.h>

// Function to modify two variables through pointers
void updateValues(int *a, int *b) {
  *a = *a * 2;  // Doubles the value of the first variable
  *b = *b + 10; // Adds 10 to the value of the second variable
}

int main() {
  int x = 5;
  int y = 20;

  printf("Before function call:\n");
  printf("x = %d\n", x);
  printf("y = %d\n\n", y);

  // Pass addresses of x and y
  updateValues(&x, &y);

  printf("After function call:\n");
  printf("x = %d\n", x);
  printf("y = %d\n", y);

  return 0;
}
