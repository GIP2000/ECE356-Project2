all: hash.o heap.o useHeap.out

useHeap.out:useHeap.o heap.o hash.o 
	g++ -o useHeap.out useHeap.o heap.o hash.o

useHeap.o: useHeap.cpp heap.h hash.h heap.cpp hash.cpp
	g++ -c useHeap.cpp

heap.o: heap.cpp heap.h hash.h hash.cpp heap.h
	g++ -c heap.cpp

hash.o: hash.cpp hash.h
	g++ -c hash.cpp

debug:
	g++ -g -o useHeap.out useHeap.cpp hash.cpp heap.cpp

clean:
	rm -f *.out *.o *.stackdump *~

backup:
	test -d backups || mkdir backups
	cp *.cpp backups
	cp *.h backups
	cp Makefile backups
