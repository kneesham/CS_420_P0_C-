
P0: main.o argHandler.o fileManager.o util.o tree.o
	g++ main.o util.o argHandler.o fileManager.o tree.o -o P0

argHandler.o: argHandler.cpp argHandler.h
	g++ -c argHandler.cpp
	
fileManager.o: fileManager.cpp fileManager.h
	g++ -c fileManager.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

tree.o: tree.cpp tree.h
	g++ -c tree.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o P0 out.*

cobj:
	rm *.o