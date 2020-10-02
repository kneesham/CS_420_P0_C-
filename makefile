
P0: main.o argHandler.o fileManager.o util.o tree.o
	g++ -std=gnu++11 main.o util.o argHandler.o fileManager.o tree.o -o P0

argHandler.o: argHandler.cpp argHandler.h
	g++ -c -std=gnu++11 argHandler.cpp
	
fileManager.o: fileManager.cpp fileManager.h
	g++ -c -std=gnu++11 fileManager.cpp

util.o: util.cpp util.h
	g++ -c -std=gnu++11 util.cpp

tree.o: tree.cpp tree.h
	g++ -c -std=gnu++11 tree.cpp

main.o: main.cpp
	g++ -c -std=gnu++11 main.cpp

clean:
	rm *.o P0

noout:
	rm *.postorder *.preorder *.inorder

cobj:
	rm *.o

