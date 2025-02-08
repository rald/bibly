all: skjv pkjv fkjv

skjv: bibly.c common.h die.h strutil.h util.h info.h token.h lexer.h cite.h parser.h
	gcc bibly.c -o skjv -O3 -g --std=c89

pkjv: bpick.c common.h die.h strutil.h
	gcc bpick.c -o pkjv -O3 -g --std=c89

fkjv: bfind.c common.h die.h strutil.h
	gcc bfind.c -o fkjv -O3 -g --std=c89

clean:
	rm skjv pkjv fkjv


