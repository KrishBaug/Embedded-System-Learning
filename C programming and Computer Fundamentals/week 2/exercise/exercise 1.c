// Implement custom string length and copy functions.
//
#include <stddef.h>
// size_t	An unsigned integer type used for sizes and counts
// Used for string lengths, array sizes, and sizeof results.

#include <stdio.h>

size_t count_len(const char *s) {
  if (s == NULL) {
    return 0;
  }
  int length = 0;
  while (s[length] != '\0') {
    length++;
  }
  return length;
}

// char *my_strcpy	The function returns the address of the destination
// string
char *my_strcpy(const char *s, char *destination) {
  int length = 0;
  while (s[length] != '\0') {
    destination[length] = s[length];
    length++;
  }

  return destination;
}

int main() {
  char source[50] = "";
  char destination[32] = "";

  printf("Enter the word :");
  scanf("%s", source);
  printf("Length of the word : %d\n", count_len(source));
  printf("Copied string %s\n", my_strcpy(source, destination));
  return 0;
}
