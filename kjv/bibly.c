#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFO_IMPLEMENTATION
#include "info.h"

#define TOKEN_IMPLEMENTATION
#include "token.h"

#define LEXER_IMPLEMENTATION
#include "lexer.h"

#define PARSER_IMPLEMENTATION
#include "parser.h"

#define CITE_IMPLEMENTATION
#include "cite.h"


int main(int argc,char **argv) {

	Info **infos=NULL;
	size_t ninfos=0;

	Token **tokens=NULL;
	size_t ntokens=0;

	Cite **cites=NULL;
	size_t ncites=0;

  int i;

	Info_Load(&infos,&ninfos,INFO_FILE);

  for(i=1;i<argc;i++) {

		lex(&tokens,&ntokens,argv[i]);

		parse(infos,ninfos,tokens,ntokens,&cites,&ncites);

		Cites_Print(infos,ninfos,cites,ncites);

		Tokens_Free(&tokens,&ntokens);
		Cites_Free(&cites,&ncites);

	}

	Infos_Free(&infos,&ninfos);

	return 0;
}
