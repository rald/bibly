all: bibly bpick bfind y z

bibly: bibly.c common.h strutil.h util.h info.h token.h lexer.h cite.h parser.h
	gcc bibly.c -o bibly -O3 -g --std=c89
	
bpick: bpick.c strutil.h
	gcc bpick.c -o bpick -O3 -g --std=c89

bfind: bfind.c strutil.h
	gcc bfind.c -o bfind -O3 -g --std=c89

y: y.c passage.h
	gcc y.c -o y -O3 -Lezxml -lezxml -g --std=c89

z: z.c passage.h
	gcc z.c -o z -O3 -Lezxml -lezxml -g --std=c89

clean:
	rm bibly bpick bfind y z

