All: Agenda.cpp AgendaUI.o AgendaService.o Storage.o Date.o Meeting.o User.o
	g++ -std=c++0x -o main *.o Agenda.cpp
AgendaUI.o: AgendaUI.cpp AgendaUI.h
	g++ -std=c++0x -c AgendaUI.cpp
AgendaService.o: AgendaService.cpp AgendaService.h
	g++ -std=c++0x -c AgendaService.cpp
Storage.o: Storage.cpp Storage.h
	g++ -std=c++0x -c Storage.cpp
Date.o: Date.cpp Date.h
	g++ -std=c++0x -c Date.cpp
Meeting.o: Meeting.cpp Meeting.h
	g++ -std=c++0x -c Meeting.cpp
User.o: User.cpp User.h
	g++ -std=c++0x -c User.cpp
clean:
	rm -f Date.o Meeting.o User.o Storage.o AgendaService.o
