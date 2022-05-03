$(CC)=gcc

application: main.o csvToLl.o deleteAtIndex.o display.o exitCode.o serch.o sort.o insertion.o
	$(CC) main.o csvToLl.o deleteAtIndex.o display.o exitCode.o serch.o sort.o insertion.o -o application

main.o: main.c headerfile.h
	$(CC) -c main.c

csvToLl.o: csvToLl.c headerfile.h
	$(CC) -c csvToLl.c

deleteAtIndex.o: deleteAtIndex.c headerfile.h
	$(CC) -c deleteAtIndex.c

display.o: display.c headerfile.h
	$(CC) -c display.c

exitCode.o: exitCode.c headerfile.h
	$(CC) -c exitCode.c

insertion.o: insertion.c headerfile.h
	$(CC) -c insertion.c

#serch.o: serch.c headerfile.h
	$(CC) -c serch.c

sort.o: sort.c headerfile.h
	$(CC) -c sort.c

clean :
	rm -f *.o
