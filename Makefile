CC := g++
FLAGS := -I include/ -Wall
BUILD := build/
SRC := src/
TARGET := main.out

all: main 

curupira:
	$(CC) $(FLAGS) -c $(SRC)/curupira.cpp -o $(BUILD)/curupira.o

iara:
	$(CC) $(FLAGS) -c $(SRC)/iara.cpp -o $(BUILD)/iara.o

mula:
	$(CC) $(FLAGS) -c $(SRC)/mula.cpp -o $(BUILD)/mula.o

saci:
	$(CC) $(FLAGS) -c $(SRC)/saci.cpp -o $(BUILD)/saci.o

main: curupira iara mula saci
	$(CC) $(FLAGS) $(BUILD)/*.o $(SRC)/main.cpp -o $(TARGET)

clean: 
	$(RM) -r $(BUILD)/* $(TARGET)