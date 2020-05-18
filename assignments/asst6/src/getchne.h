/*---------------------------------------------------------------------------
	getchne.h -	do unbuffered single-character I/O from a UNIX dumb 
			terminal just like the getch() of Turbo-C / MS-DOS.
			Written: TEK, 990426.
References: stty(), open(), read(), fflush() in Unix Programmer's Manual.
---------------------------------------------------------------------------*/
#ifndef GETCHNE_H
#define GETCHNE_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int getchne(void)
{
	int fd, c ;              /* fd = "file descriptor" for system-level file i/o */
	fflush(stdout) ; 
	fflush(stdin) ; 
	fd = open("/dev/tty",O_RDONLY) ;  /* system level open, read only of /dev/tty */
	if (fd == -1)                    /* it returns -1 when if fails */
		exit(-1) ;
	system("stty raw") ;             /* change terminal mode */
	system("stty -echo") ;
	read(fd, &c, 1) ;                /* read from keyboard */
	system("stty echo") ;            /* restore terminal settings */
	system("stty cooked") ;
	close(fd) ;
	fflush(stdin) ; 
	return c ;
}
#endif
