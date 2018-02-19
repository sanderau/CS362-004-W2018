CFLAGS = -Wall -fpic -lm -coverage

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

###########################TESTING###########################################

testAdv: dominion.o randomtestadventurer.c
	gcc -o adv randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

runtests:
	./adv
	echo "------------Random Test Adventurer results--------------------\n\n\n" > coverageResults.txt 
	gcov randomtestadventurer.c >> coverageResults.txt 
	cat randomtestadventurer.c.gcov >> coverageResults.txt

########################END TESTING##########################################


all: playdom

clean:
	rm -f adv *.o playdom.exe playdom player player.exe  *.txt *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
