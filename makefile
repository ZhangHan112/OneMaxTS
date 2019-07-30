all: OneMaxTS

OneMaxTS: OneMaxTS.o main.o 
	g++ -ggdb -o OneMaxTS OneMaxTS.o main.o

OneMaxTS.o: OneMaxTS.cpp
	g++ -ggdb -c OneMax.cpp

main.o: main.cpp
	g++ -ggdb -c main.cpp

plot: 
	gnuplot pic.gp

dep:
	echo "Do nothing"

clean:
	rm -f OneMaxTS OneMaxTS *.o

cleanDat:
	rm -f OneMaxTS *.dat
