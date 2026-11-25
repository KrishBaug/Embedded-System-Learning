/*
    RULE FOR USING & IN scanf():

    scanf() needs the ADDRESS of the memory location
    where it should store the input.

    & means "address of".

    +-----------------------------+------------+--------------------------------------------+
    | Expression                  | Use & ?    | Reason |
    +-----------------------------+------------+--------------------------------------------+
    | int x;                      | Yes        | &x gives the address of x | |
   scanf("%d", &x);            |            | |
    +-----------------------------+------------+--------------------------------------------+
    | int A[3][3];                | Yes        | A[1][1] is ONE integer element
   | | scanf("%d", &A[1][1]);      |            | so we need its address |
    +-----------------------------+------------+--------------------------------------------+
    | int A[3][3];                | No         | A[1] is already the address of
   A[1][0]     | | scanf("%d", A[1]);          |            | (reads into the
   first element of row 1)    |
    +-----------------------------+------------+--------------------------------------------+
    | int A[3][3];                | No         | A is already an address (start
   of array)   | | scanf("%d", A);             |            | but this reads
   into A[0][0], not all cells |
    +-----------------------------+------------+--------------------------------------------+
    | char name[20];              | No         | name is already the address of
   name[0]     | | scanf("%s", name);          |            | used for reading a
   string                  |
    +-----------------------------+------------+--------------------------------------------+
    | char c;                     | Yes        | &c gives the address of c | |
   scanf("%c", &c);            |            | |
    +-----------------------------+------------+--------------------------------------------+

    SIMPLE RULE:
    - Use & for a SINGLE variable or a SINGLE array element.
    - Do NOT use & when the expression is already an array name
      or already represents an address.
*/

#include <stddef.h>
#include <stdio.h>

void addMat(const float (*a)[2], const float (*b)[2], float result[2][2]);
void addSub(const float (*a)[2], const float (*b)[2], float result[2][2]);
void mulMat(const float (*a)[2], const float (*b)[2], float result[2][2]);
void transpose(const float (*a)[2], const float (*b)[2], float result[2][2]);
void print_mat(const float (*a)[2]);

int main() {
  float A[2][2];
  float result[2][2];
  printf("Enter the row1: ");
  scanf("%f %f", &A[0][0], &A[0][1]);
  printf("Enter the row2: ");
  scanf("%f %f", &A[1][0], &A[1][1]);

  printf("The Matrix : \n");
  printf("%.2f %.2f\n", A[0][0], A[0][1]);
  printf("%.2f %.2f\n", A[1][0], A[1][1]);
  float B[2][2];
  printf("Enter the row1: ");
  scanf("%f %f", &B[0][0], &B[0][1]);
  printf("Enter the row2: ");
  scanf("%f %f", &B[1][0], &B[1][1]);

  printf("The Matrix : \n");
  printf("%.2f %.2f\n", B[0][0], B[0][1]);
  printf("%.2f %.2f\n", B[1][0], B[1][1]);

  mulMat(A, B, result);
  return 0;
}

void print_mat(const float (*a)[2]) {
  printf("The Matrix : \n");
  printf("%.2f %.2f\n", a[0][0], a[0][1]);
  printf("%.2f %.2f\n", a[1][0], a[1][1]);
}

// when using size_t = 0 is required setting it to zero as it can start from any
// no. unpredictably
void addMat(const float (*a)[2], const float (*b)[2], float result[2][2]) {
  for (size_t i = 0; i < 2; i++) {
    for (size_t j = 0; j < 2; j++) {
      result[i][j] = a[i][j] + b[i][j];
    }
  }
  printf("Addtion of the Matrix");
  print_mat(result);
}

void addSub(const float (*a)[2], const float (*b)[2], float result[2][2]) {
  for (size_t i = 0; i < 2; i++) {
    for (size_t j = 0; j < 2; j++) {
      result[i][j] = a[i][j] - b[i][j];
    }
  }
  printf("Subtraction of the Matrix");
  print_mat(result);
}

void mulMat(const float (*a)[2], const float (*b)[2], float result[2][2]) {
  size_t j = 0;
  for (size_t i = 0; i < 2; i++) {
    for (size_t j = 0; j < 2; j++) {
      result[i][j] = 0;
      for (size_t k = 0; k < 2; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  print_mat(result);
}

void transpose(const float (*a)[2], const float (*b)[2], float result[2][2]);
