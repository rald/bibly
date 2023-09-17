all: bibly pick find

bibly: bibly.c common.h strutil.h util.h info.h token.h lexer.h cite.h parser.h
	gcc bibly.c -o bibly -O3 -g --std=c89
	
pick: pick.c strutil.h
	gcc pick.c -o pick -O3 -g --std=c89

find: find.c strutil.h
	gcc find.c -o find -O3 -g --std=c89

clean:
	rm bibly pick find

