PROGRAM = Alphabet_Reader
FILES = Main.cpp AlphabetReader.cpp AlphabetReader.h StringFunctions.cpp StringFunctions.h FileReader.cpp FileReader.h wordlist.txt

all: run
run: zip
zip: build
build: clean

run:
	./$(PROGRAM).o

zip:
	rm -f $(PROGRAM).zip
	zip $(PROGRAM).zip *.cpp *.h makefile

build:
	g++ -std=c++11 $(FILES) -o $(PROGRAM).o
    
clean:
	rm -f *.zip
	rm -f *.o
