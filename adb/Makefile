all: bibly bpick bfind

bibly: bibly.c common.h die.h strutil.h util.h info.h token.h lexer.h cite.h parser.h
	gcc bibly.c -o bibly -O3 -g --std=c89

bpick: bpick.c common.h die.h strutil.h
	gcc bpick.c -o bpick -O3 -g --std=c89

bfind: bfind.c common.h die.h strutil.h
	gcc bfind.c -o bfind -O3 -g --std=c89

clean:
	rm bibly bpick bfind

