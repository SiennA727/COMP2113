FLAGS = -pedantic-errors -std=c++11

d2boh.o: d2boh.cpp d2boh.h
	g++ $(FLAGS) -c $<

main.o: main.cpp d2boh.h
	g++ $(FLAGS) -c $<

main: d2boh.o main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main main.o d2boh.o

.PHONY: clean
