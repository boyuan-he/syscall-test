#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <stdlib.h>
#include <limits.h>

extern int errno;

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Error: need path to be the first argument and number of bytes to read as the second\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        printf("Error: open failed %d\n", fd);
        printf("Error: %s (errno=%d)\n", strerror(errno), errno);
        return 1;
    }

    long int bytesToRead = strtol(argv[2], NULL, 10);
    if(bytesToRead < 0 || bytesToRead > INT_MAX) {
        printf("Error: invalid bytes to read %ld\n", bytesToRead);
        return 1;
    }

    char * buf = malloc(bytesToRead+1);
    int ret;
    int num = 0;
    while(true) {
        ret = read(fd, buf, bytesToRead);
        num ++;
        printf("Number of read done %d\n", num);
        // if (ret < 0) {
        //     printf("Error: read failed %d\n", ret);
        //     printf("Error: %s (errno=%d)\n", strerror(errno), errno);
        //     return 1;
        // }
    };
    printf("Number of read done %d\n", num);

    buf[bytesToRead] = '\0';
    printf("Read: %s\n", buf);

    free(buf);

    return 0;
}
