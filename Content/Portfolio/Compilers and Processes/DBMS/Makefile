#Instructions for compilation.

G = g++-4.9
CFLAGS = -I/usr/local/lib/Oracle/instantclient_11_2/sdk/include
LFLAGS = -L/usr/local/lib/Oracle/instantclient_11_2 -locci -lociei
Obj = bin/MainUI.o bin/CreateDatabase.o bin/DeleteDatabase.o bin/InsertData.o bin/Populate.o bin/Invoice.o bin/NetWeight.o bin/GrossProffit.o bin/Help.o bin/src.o

all: bin MainUI

bin:
	mkdir bin

MainUI: MainUI.cpp $(Obj)
	$(G) $(CFLAGS) $(LFLAGS) $(Obj) -o MainUI

bin/MainUI.o: MainUI.cpp src/src.h
	$(G) -c $(CFLAGS) MainUI.cpp -o bin/MainUI.o

bin/A_CreateDatabase.o: src/CreateDatabase.cpp
	$(G) -c $(CFLAGS) src/CreateDatabase.cpp -o bin/CreateDatabase.o

bin/B_DeleteDatabase.o: src/DeleteDatabase.cpp
	$(G) -c $(CFLAGS) src/DeleteDatabase.cpp -o bin/DeleteDatabase.o

bin/C_InsertData.o: src/InsertData.cpp
	$(G) -c $(CFLAGS) src/InsertData.cpp -o bin/InsertData.o

bin/D_Populate.o: src/Populate.cpp
	$(G) -c $(CFLAGS) src/Populate.cpp -o bin/Populate.o

bin/E_Invoice.o: src/Invoice.cpp
	$(G) -c $(CFLAGS) src/Invoice.cpp -o bin/Invoice.o

bin/F_NetWeight.o: src/NetWeight.cpp
	$(G) -c $(CFLAGS) src/NetWeight.cpp -o bin/NetWeight.o

bin/G_GrossProffit.o: src/GrossProffit.cpp
	$(G) -c $(CFLAGS) src/GrossProffit.cpp -o bin/GrossProffit.o

bin/H_Help.o: src/Help.cpp
	$(G) -c $(CFLAGS) src/Help.cpp -o bin/Help.o

bin/src.o: src/src.cpp
	$(G) -c $(CFLAGS) src/src.cpp -o bin/src.o

clean:
	rm -f bin/*.o MainUI
