all: sadb padb fadb

sadb: bibly.c common.h die.h strutil.h util.h info.h token.h lexer.h cite.h parser.h
	gcc bibly.c -o sadb -O3 -g --std=c89

padb: bpick.c common.h die.h strutil.h
	gcc bpick.c -o padb -O3 -g --std=c89

fadb: bfind.c common.h die.h strutil.h
	gcc bfind.c -o fadb -O3 -g --std=c89

clean:
	rm sadb padb fadb
