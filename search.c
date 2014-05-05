/*
Jack Daines
Apr 25. 2014
https://github.com/jakx
Dedicated to my baby girl

An application to open a google search from a terminal.

example: search how to grow a moss -- will open a firefox window with the query
*/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
	
int
main(int argc, char *argv[])
{
        char *browser = "firefox";
        int c;
        int bflag = 0;;
        while ((c = getopt (argc, argv, "b:")) != -1)
           switch (c)
           {
           case 'b':
             bflag = 1;
             browser = optarg;
             break;
           }
        char buf[256]  = "http://www.google.com/search?q=";
    	snprintf(buf, sizeof buf, "%s", "http://www.google.com/search?q=");
        int i = 0;
        for(i = optind; i < argc; i++){
               strcat(buf, argv[i]);
               if(i+1 < argc)
		       strcat(buf, " ");
        }
        char *argt[] = {browser, buf, NULL};
    	execvp(argt[0], argt);
}

