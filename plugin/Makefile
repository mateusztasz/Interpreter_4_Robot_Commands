__start__: obj ../libs/command4move.so ../libs/command4turn.so ../libs/command4rotate.so ../libs/command4grasper.so
	@echo "  Tworzenie wtyczek zakonczone sukcesem."
	@echo

obj:
	mkdir obj

CPPFLAGS=-Wall -fPIC -pedantic -Iinc -I../inc
LDFLAGS=-Wall -shared


#Komendy dla stworzenia biblioteki move
#
../libs/command4move.so: obj/command4move.o
	g++ ${LDFLAGS} -o ../libs/command4move.so obj/command4move.o
	@echo
	@echo "  Wtyczka dla polecenia 'Move' zostala utworzona."
	@echo


obj/command4move.o: src/command4move.cpp ../inc/command.hh\
                        inc/command4move.hh 
	g++ -c ${CPPFLAGS} -o obj/command4move.o src/command4move.cpp



#Komendy dla stworzenia biblioteki turn
#
../libs/command4turn.so: obj/command4turn.o
	g++ ${LDFLAGS} -o ../libs/command4turn.so obj/command4turn.o
	@echo
	@echo "  Wtyczka dla polecenia 'Turn' zostala utworzona."
	@echo


obj/command4turn.o: src/command4turn.cpp ../inc/command.hh\
                        inc/command4turn.hh 
	g++ -c ${CPPFLAGS} -o obj/command4turn.o src/command4turn.cpp


#Komendy dla stworzenia biblioteki rotate
#
../libs/command4rotate.so: obj/command4rotate.o
	g++ ${LDFLAGS} -o ../libs/command4rotate.so obj/command4rotate.o
	@echo
	@echo "  Wtyczka dla polecenia 'Rotate' zostala utworzona."
	@echo


obj/command4rotate.o: src/command4rotate.cpp ../inc/command.hh\
                        inc/command4rotate.hh 
	g++ -c ${CPPFLAGS} -o obj/command4rotate.o src/command4rotate.cpp



#Komendy dla stworzenia biblioteki grasper
#
../libs/command4grasper.so: obj/command4grasper.o
	g++ ${LDFLAGS} -o ../libs/command4grasper.so obj/command4grasper.o
	@echo
	@echo "  Wtyczka dla polecenia 'Grasper' zostala utworzona."
	@echo


obj/command4grasper.o: src/command4grasper.cpp ../inc/command.hh\
                        inc/command4grasper.hh 
	g++ -c ${CPPFLAGS} -o obj/command4grasper.o src/command4grasper.cpp






clean:
	rm -f obj/*

cleanall: clean
	find . -name \*~ -print -exec rm {} \;
