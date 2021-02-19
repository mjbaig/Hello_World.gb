CC = ./gbdk/bin/lcc -Wa-l -Wl-m -Wl-j


install:
	$(CC) -o hello_world.gb main.c

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi