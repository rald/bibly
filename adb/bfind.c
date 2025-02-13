#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <errno.h>

#include "common.h"

#define DIE_IMPLEMENTATION
#include "die.h"

#define STRUTIL_IMPLEMENTATION
#include "strutil.h"

int main(int argc,char **argv) {


	char *line=NULL;
	size_t llen=0;
	ssize_t rlen=0;
	FILE *fp=NULL;
	size_t i;
	char **t=NULL;
	size_t nt=0;

  if(argc<2) {
    printf("syntax: %s \"search text\"",argv[0]);
    return 1;
  }

	if((fp=fopen(CSV_FILE,"r"))==NULL) {
    die(1,"main: fopen: %s",strerror(errno));
	}

	while((rlen=getline(&line,&llen,fp))!=-1) {

    for(i=1;i<argc;i++) {
      if(strcasestr(line,argv[i])) {

        char *line2=strdup(line);

      	tokenize(&t,&nt,line,"|");

      	printf("%s %s:%s -> %s\n",t[0],t[1],t[2],t[3]);

        tokfree(&t,&nt);

        break;
      }
    }

		free(line);
		line=NULL;
		llen=0;
		rlen=0;
	}

	free(line);
	line=NULL;
	llen=0;
	rlen=0;

	return 0;
}
