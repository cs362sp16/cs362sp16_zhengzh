CFLAGS = -Wall -fpic -coverage -lm 

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: unittest1.c
	gcc -fprofile-arcs -ftest-coverage -o unittest1 unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c
	gcc -fprofile-arcs -ftest-coverage -o unittest2 unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c
	gcc -fprofile-arcs -ftest-coverage -o unittest3 unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c
	gcc -fprofile-arcs -ftest-coverage -o unittest4 unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest1: cardtest1.c
	gcc -fprofile-arcs -ftest-coverage -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c
	gcc -fprofile-arcs -ftest-coverage -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c
	gcc -fprofile-arcs -ftest-coverage -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c
	gcc -fprofile-arcs -ftest-coverage -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

testdominion: testdominion.c
	gcc -fprofile-arcs -ftest-coverage -o testdominion testdominion.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c
	gcc -fprofile-arcs -ftest-coverage -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard1: randomtestcard1.c
	gcc -fprofile-arcs -ftest-coverage -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard2: randomtestcard2.c
	gcc -fprofile-arcs -ftest-coverage -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard1.out: randomtestcard1
	./randomtestcard1 42 &> randomtestcard1.out
	gcov -f dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: dominion.o randomtestcard2
	./randomtestcard2 42 &> randomtestcard2.out
	gcov -f dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer
	./randomtestadventurer 42 &> randomtestadventurer.out
	gcov -b -c dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

unittestresults.out: dominion.o unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

all: playdom player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2 testdominion

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
