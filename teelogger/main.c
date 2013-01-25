//
//  main.c
//  teelogger
//
//  Created by Arran Ubels on 25/01/13.
//  Copyright (c) 2013 Arran Ubels. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>

void usage()
{
    
}

void beginlogging()
{
}

int main(int argc, char * const * argv)
{
    int bflag, ch, fd;
    
    bflag = 0;
    while ((ch = getopt(argc, argv, "bf:")) != -1) {
        switch (ch) {
            case 'b':
                bflag = 1;
                break;
            case 'f':
                if ((fd = open(optarg, O_RDONLY, 0)) < 0) {
                    (void)fprintf(stderr,
                                  "myname: %s: %s\n", optarg, strerror(errno));
                    exit(1);
                }
                break;
            case '?':
            default:
                usage();
        }
    }
    argc -= optind;
    argv += optind;

    return 0;
}

