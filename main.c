#include "random_header.h"

int main() {
  printf("Generating random numbers:\n");

  int array[10];
  for (int i = 0; i < 10; i++) {
    array[i] = random_num();
    printf("\trandom %d: %d\n", i, array[i]);
  }

  printf("\nWriting numbers to file...\n");
  int fd = open("random_numbers", O_CREAT | O_RDWR, 0644);
  if (fd == -1) {
    printf("%s\n", strerror(errno));
    return 0;
  }
  if (write(fd, array, sizeof(int) * 10) == -1) {
    printf("%s\n", strerror(errno));
    return 0;
  }
  close(fd);

  printf("\nReading numbers from file...\n");
  int fd_test = open("random_numbers", O_RDONLY);
  if (fd_test == -1){
    printf("%s\n", strerror(errno));
    return 0;
  }
  int array_test[10];
  if (read(fd_test, array_test, sizeof(int)*10) == -1){
    printf("%s\n", strerror(errno));
    return 0;
  }

  printf("\nVerification that written values were the same:\n");
  for (int i = 0; i < 10; i++) {
    printf("\trandom %d: %d\n", i, array[i]);
  }
  return 0;
}
