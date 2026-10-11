CC = gcc
CFLAGS = -Wall -Wextra

OBJ = project_main.o input.o create.o print.o find.o delete.o edit.o save.o load.o free.o

phonebook: $(OBJ)
	$(CC) $(CFLAGS) -o phonebook $(OBJ)

main.o: main.c contact.h
	$(CC) $(CFLAGS) -c project_main.c

input.o: input.c contact.h
	$(CC) $(CFLAGS) -c input.c

create.o: create.c contact.h
	$(CC) $(CFLAGS) -c create.c

print.o: print.c contact.h
	$(CC) $(CFLAGS) -c print.c

find.o: find.c contact.h
	$(CC) $(CFLAGS) -c find.c

delete.o: delete.c contact.h
	$(CC) $(CFLAGS) -c delete.c

edit.o: edit.c contact.h
	$(CC) $(CFLAGS) -c edit.c

save.o: save.c contact.h
	$(CC) $(CFLAGS) -c save.c

load.o: load.c contact.h
	$(CC) $(CFLAGS) -c load.c

free.o: free.c contact.h
	$(CC) $(CFLAGS) -c free.c

clean:
	rm -f *.o phonebook
