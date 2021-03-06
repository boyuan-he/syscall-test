#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Error: need path to be the first argument\n");
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if(fd < 0) {
    printf("Error: open failed %d\n", fd);
    printf("Error: %s (errno=%d)\n", strerror(errno), errno);
    return 1;
  }

  if(close(fd)) {
    printf("Error: %s (errno=%d)\n", strerror(errno), errno);
    return 1;
  }
  return 0;
}
