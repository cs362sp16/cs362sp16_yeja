CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittest1: unittest1.c dominion.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS) 

unittest2: unittest2.c dominion.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS) 

unittest3: unittest3.c dominion.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS) 

unittest4: unittest4.c dominion.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS) 

cardtest1: cardtest1.c dominion.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS) 

cardtest2: cardtest2.c dominion.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS) 

cardtest4: cardtest4.c dominion.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS) 
	
all: playdom player

randomtestadventurer:
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard1.c rngs.c -o randomtestcard1 -lm -g	

randomtestcard2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard2.c rngs.c -o randomtestcard2 -lm -g 
	
unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom
	./unittest1 >> unittestresults.out
	echo "UNITTEST 1" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest2 >> unittestresults.out
	echo "UNITTEST 2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest3 >> unittestresults.out
	echo "UNITTEST 3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest4 >> unittestresults.out
	echo "UNITTEST 4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest1 >> unittestresults.out
	echo "CARDTEST 1 " >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest2 >> unittestresults.out
	echo "CARDTEST 2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest3 >> unittestresults.out
	echo "CARDTEST 3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest4 >> unittestresults.out
	echo "CARDTEST 4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out


	./playdom 3 >> unittestresults.out
	echo "GCOV AFTER PLAYING A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
randomtestresult.out: randomtestadventurer randomtestcard1 randomtestcard2 playdom
	./randomtestadventurer >> randomtestadventurer.out
	echo "CARD TEST FOR ADVENTURER: " >> randomtestresult.out
	gcov dominion.c >> randomtestadventurer.out
	
	./randomtestcard1 >> randomtestcard1.out
	echo "CARD TEST FOR CUTPURSE: " >> randomtestresult.out
	gcov dominion.c >> randomtestcard1.out
	
	./randomtestcard2 >> randomtestcard2.out
	echo "CARD TEST FOR SMITHY: " >> randomtestresult.out
	gcov dominion.c >> randomtestcard2.out

testdominion: testdominion.c dominion.o rngs.o
	gcc -o testdominion -std=c99 testdominion.c dominion.o rngs.o $(CFLAGS)
	rm -f testdominion.out
	./testdominion 42 >> testdominion.out

testdominion.diff: testdominion.c dominion.o rngs.o
	gcc -o testdominion -std=c99 testdominion.c dominion.o rngs.o $(CFLAGS)


clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
