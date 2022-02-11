dead1:dead1.o
	cc -o dead1 dead1.o -lpthread -lrt
dead1.o:dead1.c
	cc -c dead1.c
dead2:dead2.o
	cc -o dead2 dead2.o -lpthread -lrt
dead2.o:dead2.c
	cc -c dead2.c
prod:prod.o
	cc -o prod prod.o -lpthread -lrt
prod.o:prod.c
	cc -c prod.c
crit:crit.o
	cc -o crit crit.o -lpthread -lrt
crit.o:crit.c
	cc -c crit.c
critsem:critsem.o
	cc -o critsem critsem.o -lpthread -lrt
critsem.o:critsem.c
	cc -c critsem.c
fork_socket:fork_socket.o
	cc -o fork_socket fork_socket.o -lnsl
fork_socket.o:fork_socket.c
	cc -c fork_socket.c
child_socket:child_socket.o
	cc -o child_socket child_socket.o -lnsl
child_socket.o:child_socket.c
	cc -c child_socket.c
clean:
	rm -f *.o prod dead1 dead2 crit fork_socket child_socket *.~

