/*  As an exercise, I modified the code to allow for  *\
\*  users to specify the file they wish to output to. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if( argc < 2 )
    {
        printf("%s [filename]\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    assert(fd >= 0);
    char buffer[20];
    sprintf(buffer, "hello world\n");
    int rc = write(fd, buffer, strlen(buffer));
    assert(rc == ( int )(strlen(buffer)));
    fsync(fd);
    close(fd);
    return 0;
}