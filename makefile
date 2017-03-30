main:Elo.o elo.o
	g++ -o main Elo.o elo.o
Elo.o:Elo.cpp elo.h
	g++ -c Elo.cpp
elo.o:elo.cpp elo.h
	g++ -c elo.cpp
clean:
	rm main *.o
