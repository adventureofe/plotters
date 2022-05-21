output: main.o window.o rect.o tri.o
	clang main.o window.o rect.o tri.o -o curses-grapher  $(ncursesw5-config --cflags --libs)  -W -Wall -Wextra -pedantic -lncursesw -lm 

main.o: main.c
	clang -c main.c -W -Wall -Wextra -pedantic

window.o: src/window.c headers/window.h
	clang -c ./src/window.c -W -Wall -Wextra -pedantic 

rect.o: src/rect.c headers/rect.h
	clang -c ./src/rect.c -W -Wall -Wextra -pedantic

tri.o: src/tri.c headers/tri.h
	clang -c  ./src/tri.c -W -Wall -Wextra -pedantic


clean:
	rm *.o curses-grapher
