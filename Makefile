Game: main.o menu.o options.o selectstart.o menuanimation.o minimap.o ES.o perso.o background.o score.o enigmetf.o collisionparfaite.o enigmeif.o IA.o arduino.o sauvegarde.o
	gcc main.o menu.o options.o selectstart.o menuanimation.o minimap.o ES.o perso.o background.o score.o enigmetf.o collisionparfaite.o enigmeif.o arduino.o IA.o sauvegarde.o -o Game -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o: main.c
	gcc -c main.c -g
menu.o: menu.c
	gcc -c menu.c -g
options.o: options.c
	gcc -c options.c -g
selectstart.o: selectstart.c
	gcc -c selectstart.c -g
menuanimation.o: menuanimation.c
	gcc -c menuanimation.c -g
minimap.o: minimap.c
	gcc -c minimap.c -g
ES.o:	ES.c
	gcc -c ES.c -g
perso.o: perso.c
	gcc -c perso.c -g
background.o:	 background.c
	gcc -c  background.c -g
score.o: score.c
	gcc -c score.c -g
enigmetf.o: enigmetf.c
	gcc -c enigmetf.c -g
collisionparfaite.o: collisionparfaite.c
	gcc -c collisionparfaite.c -g
enigmeif.o :enigmeif.c
	gcc -c enigmeif.c -g
arduino.o :arduino.c
	gcc -c arduino.c -g
IA.o :IA.c
	gcc -c IA.c -g
sauvegarde.o :sauvegarde.c
	gcc -c sauvegarde.c -g
