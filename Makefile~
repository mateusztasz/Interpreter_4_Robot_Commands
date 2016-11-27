__start__: obj interp __plugin__
	export LD_LIBRARY_PATH="./libs"; rlwrap -pGreen -S'Twoj wybor>' ./interp


obj:
	mkdir obj

__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -pedantic -iquote inc -std=c++11 
LDFLAGS=-Wall

interp: obj/main.o obj/lacze_do_gnuplota.o  obj/plugin.o \
        obj/funkcje_dla_menu.o obj/ZbiorPluginow.o obj/funkcje_wykonujace.o obj/xmlparser4scene.o obj/Obiekt.o obj/MojeLaczeDoGNUplota.o obj/Scene.o obj/RobotMobilny.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/lacze_do_gnuplota.o\
                obj/RobotMobilny.o obj/plugin.o  obj/funkcje_dla_menu.o \
                obj/ZbiorPluginow.o obj/funkcje_wykonujace.o obj/xmlparser4scene.o obj/Obiekt.o obj/MojeLaczeDoGNUplota.o obj/Scene.o -lxerces-c -ldl -lreadline

obj/xmlparser4scene.o: src/xmlparser4scene.cpp inc/xmlparser4scene.hh
	g++ -c ${CPPFLAGS} -o obj/xmlparser4scene.o src/xmlparser4scene.cpp

obj/main.o: src/main.cpp inc/command.hh  inc/Scene.hh inc/lacze_do_gnuplota.hh inc/xmlparser4scene.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp 

obj/plugin.o:src/plugin.cpp inc/plugin.hh inc/command.hh
	g++ -c ${CPPFLAGS} -o obj/plugin.o src/plugin.cpp

obj/RobotMobilny.o: src/RobotMobilny.cpp inc/RobotMobilny.hh inc/robotpose.hh\
           inc/command.hh
	g++ -c ${CPPFLAGS} -o obj/RobotMobilny.o src/RobotMobilny.cpp

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hh
	g++ -c ${CPPFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/funkcje_dla_menu.o:  src/funkcje_dla_menu.cpp  inc/funkcje_dla_menu.hh inc/plugin.hh inc/ZbiorPluginow.hh inc/funkcje_wykonujace.hh
	g++ -c ${CPPFLAGS} -o obj/funkcje_dla_menu.o src/funkcje_dla_menu.cpp

obj/ZbiorPluginow.o:  src/ZbiorPluginow.cpp  inc/ZbiorPluginow.hh inc/plugin.hh
	g++ -c ${CPPFLAGS} -o obj/ZbiorPluginow.o src/ZbiorPluginow.cpp

obj/funkcje_wykonujace.o:  src/funkcje_wykonujace.cpp  inc/funkcje_wykonujace.hh inc/robotpose.hh inc/RobotMobilny.hh
	g++ -c ${CPPFLAGS} -o obj/funkcje_wykonujace.o src/funkcje_wykonujace.cpp


obj/Obiekt.o: inc/Obiekt.hh
	g++  -c ${CPPFLAGS} -o obj/Obiekt.o src/Obiekt.cpp

obj/MojeLaczeDoGNUplota.o: inc/MojeLaczeDoGNUplota.hh inc/lacze_do_gnuplota.hh inc/Obiekt.hh
	g++  -c ${CPPFLAGS} -o obj/MojeLaczeDoGNUplota.o src/MojeLaczeDoGNUplota.cpp

obj/Scene.o: inc/Scene.hh inc/Obiekt.hh inc/MojeLaczeDoGNUplota.hh inc/RobotMobilny.hh
	g++  -c ${CPPFLAGS} -o obj/Scene.o src/Scene.cpp

clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
