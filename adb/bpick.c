#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

#include "common.h"

#define STRUTIL_IMPLEMENTATION
#include "strutil.h"

double drand() {
	return rand()/(1.0+RAND_MAX);
}

int main(int argc,char *argv[]) {

	srand(time(NULL));

	FILE *fp=NULL;

	char *line=NULL;
	size_t llen=0;
	ssize_t rlen=0;

	size_t n=0;

  char **t=NULL;
  size_t nt=0;

	char *sel=NULL;

  size_t i,c=1;

  if(argc==2) c=atoi(argv[1]);

  for(i=0;i<c;i++) {

  	fp=fopen(CSV_FILE,"r");

    n=0;

  	while((rlen=getline(&line,&llen,fp))!=-1) {

  		if(drand()<1.0/++n) {
  			if(sel!=NULL) free(sel);
  			sel=strdup(line);
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

  	tokenize(&t,&nt,sel,"|");

  	printf("%s %s:%s -> %s\n",t[0],t[1],t[2],t[3]);

    tokfree(&t,&nt);

  	free(sel);
    sel=NULL;

    fclose(fp);
  }

	return 0;
}


