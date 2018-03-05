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

village: dominion.o randomtestcard1.c
	gcc -o village randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
great: dominion.o randomtestcard2.c
	gcc -o great randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

compiletests:
	make testAdv
	make village
	make great

runtests:
	make compiletests
	./adv
	echo "------------Random Test Adventurer results--------------------\n\n\n" >> coverageResults.txt 
	gcov randomtestadventurer.c >> coverageResults.txt 
	cat randomtestadventurer.c.gcov >> coverageResults.txt
	./village
	echo "\n\n\n--------------------------Random test card one-----------------------\n\n\n" >> coverageResults.txt
	gcov randomtestcard1.c >> coverageResults.txt
	cat randomtestcard1.c.gcov >> coverageResults.txt
	echo "\n\n\n---------------------------Random test card two------------------------\n\n\n" >> coverageResults.txt
	./great
	gcov randomtestcard2.c >> coverageResults.txt
	cat randomtestcard2.c.gcov >> coverageResults.txt
	

########################END TESTING##########################################


all: playdom

clean:
	rm -f adv village great *.o playdom.exe playdom player player.exe  *.txt *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
