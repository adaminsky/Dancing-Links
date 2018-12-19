dance: dancinglinks.o main.o
	g++ -g dancinglinks.o main.o -o dance
main.o: main.cpp dancinglinks.h
	g++ -c main.cpp
dancinglinks.o: dancinglinks.cpp dancinglinks.h
	g++ -c dancinglinks.cpp
clean:
	rm *.o
	rm dance
