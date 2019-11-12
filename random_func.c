#include "random_header.h"

int random_num() {
  int fd = open("/dev/random", O_RDONLY);
  if (fd == -1){
    printf("%s\n", strerror(errno));
  }
  int num = 0;
  int *p = &num;
  if (read(fd, p, sizeof(int)) == -1){
    printf("%s\n", strerror(errno));
  }
  close(fd);
  return num;
}
