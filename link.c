#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[]) {
  if(argc < 3) {
    printf("Error: need path to be the first argument\n");
    return 1;
  }

  int res = link(argv[1], argv[2]);
  if(res < 0) {
    printf("Error: link failed %d\n", res);
    printf("Error: %s (errno=%d)\n", strerror(errno), errno);
    return 1;
  }
  return 0;
}
