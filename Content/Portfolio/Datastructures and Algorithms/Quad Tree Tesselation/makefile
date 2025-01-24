tilex: mainTile.o  tesselation.o
	g++ -o tile mainTile.o tesselation.o

mainTile.o: mainTile.cpp  tesselation.h
	g++ -c mainTile.cpp

tesselation.o: tesselation.cpp  tesselation.h
	g++ -c tesselation.cpp

clean:
	rm mainTile.o tesselation.o 
