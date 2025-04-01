all: sbbe pbbe fbbe

sbbe: bibly.c common.h die.h strutil.h util.h info.h token.h lexer.h cite.h parser.h
	gcc bibly.c -o sbbe -O3 -g --std=c89

pbbe: bpick.c common.h die.h strutil.h
	gcc bpick.c -o pbbe -O3 -g --std=c89

fbbe: bfind.c common.h die.h strutil.h
	gcc bfind.c -o fbbe -O3 -g --std=c89

clean:
	rm sadb padb fadb
