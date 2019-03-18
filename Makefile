wallet : main.cpp wallet.cpp wallet.h
	g++ main.cpp wallet.cpp
clean : main.o wallet.o
	rm -rf main.o wallet.o