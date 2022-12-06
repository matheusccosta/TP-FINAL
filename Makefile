CC := g++
FLAGS := -I third_party -I include/ -Wall
BUILD := build/
SRC := src/
TESTDIR = tests
TARGET := main.out
TARGET_TEST := test.out

all: main 

curupira:
	$(CC) $(FLAGS) -c $(SRC)/curupira.cpp -o $(BUILD)/curupira.o

iara:
	$(CC) $(FLAGS) -c $(SRC)/iara.cpp -o $(BUILD)/iara.o

mula:
	$(CC) $(FLAGS) -c $(SRC)/mula.cpp -o $(BUILD)/mula.o

saci:
	$(CC) $(FLAGS) -c $(SRC)/saci.cpp -o $(BUILD)/saci.o

jogo: curupira iara mula saci
	$(CC) $(FLAGS) -c $(SRC)/jogo.cpp -o $(BUILD)/jogo.o

test: 
	$(CC) $(FLAGS) $(TESTDIR)/testGeral.cpp $(BUILD)/*.o -o test.out

main: curupira iara mula saci jogo test
	$(CC) $(FLAGS) $(BUILD)/*.o $(SRC)/main.cpp -o $(TARGET)

clean: 
	$(RM) -r $(BUILD)/*.o $(TARGET) $(TARGET_TEST)