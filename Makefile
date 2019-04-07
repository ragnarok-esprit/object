prog:score.o main.o 
	gcc score.o  main.o -o prog -lSDL -lSDL_image -lSDL_mixer  -lSDL_ttf -g
main.o:main.c
	 gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
score.o:score.c score.h
	gcc -c score.c  -lSDL -lSDL_image -lSDL_mixer  -lSDL_ttf -g
