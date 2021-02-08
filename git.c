/* A proxy for Cygwin's git:
 * this invokes C:/cygwin64/bin/bash -c 'git-wrapper "%1" "%2" "%3"...'
 * 
 * How to build: x86_64-w64-mingw32-gcc -o git git.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buf[4000] = "C:/cygwin64/bin/sh -c 'git-wrapper";
    int rest = sizeof(buf) - strlen(buf) - 2; /* 2 for "'\0" */

    for (int i = 1; i < argc; i++) {
        rest -= strlen(argv[i]) + 3; /* 3 for " \"\"" */
        if (rest < 0) {
            fprintf(stderr, "arguments too long\n");
            return 1;
        }
        strcat(buf, " \"");
        strcat(buf, argv[i]);
        strcat(buf, "\"");
    }
    strcat(buf, "'");
    return system(buf);
}
