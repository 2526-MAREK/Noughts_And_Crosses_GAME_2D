TASKNO=5
APP=NoughtsAndCrosses
TASKDIR=${HOME}/edu/po/zad/z${TASKNO}

#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -W -Wall -pedantic -std=c++17 

__start__: obj ./${APP}
	rm -f core.* core; ./${APP}

# Tworzy katalog "obj" gdy go nie ma
# 
obj:
	mkdir obj

./${APP}: obj/main.o obj/MainWindowApplication.o obj/MenuView.o obj/GameView.o obj/GameBoard.o obj/crosses.o obj/circle.o
	g++ obj/main.o obj/MainWindowApplication.o obj/MenuView.o obj/GameView.o obj/GameBoard.o obj/crosses.o obj/circle.o -o NoughtsAndCrosses -lsfml-graphics -lsfml-window -lsfml-system 

ext: ./${APP}_rozszerzony
	rm -f core.* core; echo "2i 1+3.1i 2 ? / + ?" | ./${APP}_rozszerzony

obj/main.o: src/main.cpp inc/MainWindowApplication.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/MainWindowApplication.o: src/MainWindowApplication.cpp inc/MainWindowApplication.hh inc/MenuView.hh
	g++ -c ${CXXFLAGS} -o obj/MainWindowApplication.o src/MainWindowApplication.cpp		

obj/MenuView.o: src/MenuView.cpp inc/MenuView.hh inc/GameView.hh 
	g++ -c ${CXXFLAGS} -o obj/MenuView.o src/MenuView.cpp			

obj/GameView.o: src/GameView.cpp inc/GameView.hh inc/GameBoard.hh 
	g++ -c ${CXXFLAGS} -o obj/GameView.o src/GameView.cpp			

obj/GameBoard.o: src/GameBoard.cpp inc/GameBoard.hh inc/crosses.hh inc/circle.hh 
	g++ -c ${CXXFLAGS} -o obj/GameBoard.o src/GameBoard.cpp	

obj/crosses.o: src/crosses.cpp inc/crosses.hh 
	g++ -c ${CXXFLAGS} -o obj/crosses.o src/crosses.cpp	

obj/circle.o: src/circle.cpp inc/circle.hh 
	g++ -c ${CXXFLAGS} -o obj/circle.o src/circle.cpp		

clean:
	rm -f obj/* ./${APP} core.* core

${TASKDIR}:
	mkdir -p ${TASKDIR}/bin.diablo ${TASKDIR}/bin.panamint

__TARGET__:
	if [ ! "${HOST}" = "diablo" ] && [ ! "${HOST}" = "panamint" ]; then exit 1; fi

export: __TARGET__ ./${APP}  ./${APP}_rozszerzony ${TASKDIR}
	mv ${APP} ${APP}_rozszerzony ${HOME}/edu/po/zad/z${TASKNO}/bin.${HOST}/

help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make ext    - tworzenie i uruchomienie aplikacji w wersji rozszerzonej"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
