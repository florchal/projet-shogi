all: main
CC= clang++ -stdlib=libc++ -I SFML-2.1/include -Wall
LD= clang++ -stdlib=libc++ -L SFML-2.1/lib -lsfml-system -lsfml-graphics -lsfml-window

main.o: main.cpp Deplacements.hpp Moteur.hpp Pion.hpp Plateau.hpp
	$(CC) -c main.cpp

Moteur.o: Moteur.cpp Deplacements.hpp Moteur.hpp Pion.hpp Plateau.hpp
	$(CC) -c Moteur.cpp -o Moteur.o

Deplacements.o: Deplacements.cpp Deplacements.hpp Pion.hpp Plateau.hpp
	$(CC) -c Deplacements.cpp -o Deplacements.o

Plateau.o: Plateau.cpp Plateau.hpp Pion.hpp
	$(CC) -c Plateau.cpp -o Plateau.o

Pion.o: Pion.cpp Pion.hpp
	$(CC) -c Pion.cpp -o Pion.o

main: main.o Moteur.o Deplacements.o Plateau.o Pion.o
	$(LD) main.o Moteur.o Deplacements.o Plateau.o Pion.o -o main
exec: main
	LD_LIBRARY_PATH=/lib/ && ./main
		
clean: 
	rm -rf *.o
