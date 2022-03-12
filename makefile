EXECS = deque.o fight.o fighter.o main.o specs.o threads.o stats.o
LIBS = -lpthread

project:	$(EXECS)
		gcc -o proj $(EXECS) $(LIBS)

deque.o:	deque.c defs.h
		gcc -c deque.c $(LIBS)

fight.o:	fight.c defs.h
		gcc -c fight.c $(LIBS)

fighter.o:	fighter.c defs.h
		gcc -c fighter.c $(LIBS)

main.o:	main.c	defs.h
		gcc -c main.c $(LIBS)

specs.o:	specs.c defs.h
		gcc -c specs.c $(LIBS)

threads.o:	threads.c defs.h
		gcc -c threads.c $(LIBS)

stats.o:	stats.c defs.h
		gcc -c stats.c $(LIBS)

clean:
		rm -f $(EXECS)


