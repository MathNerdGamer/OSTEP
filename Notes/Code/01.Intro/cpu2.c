/* As an exercise, I modified the code to allow for strings  *\
\* with spaces without requiring the use of quotation marks. */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
    if( argc < 2 )
    {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }

    while( 1 )
    {
        for( int i = 1; i < argc; ++i )
        {
            printf("%s", argv[i]);

            if( i < argc - 1 )
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
        Spin(1);
    }
    return 0;
}