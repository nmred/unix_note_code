#include "apue.h"
#include <fcntl.h>

void get_fl(char *filename[]);
void add_fl(char *filename[], int flags);
void del_fl(char *filename[], int flags);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		err_quit("usage: a.out <descriptor#>");	
	}	

	get_fl(&argv[1]);
	add_fl(&argv[1], O_APPEND);
	get_fl(&argv[1]);
	del_fl(&argv[1], O_APPEND);
	get_fl(&argv[1]);
	exit(0);
}

void add_fl(char *filename[], int flags)
{
	int val;
	if ((val = fcntl(atoi(*filename), F_GETFL, 0)) < 0) {
		err_sys("fcntl error for fd %d", atoi(*filename));
	}

	val |= flags;

	if (fcntl(atoi(*filename), F_SETFL, val)) {
		err_sys("fcntl error for fd %d", atoi(*filename));
	}
}

void del_fl(char *filename[], int flags)
{
	int val;
	if ((val = fcntl(atoi(*filename), F_GETFL, 0)) < 0) {
		err_sys("fcntl error for fd %d", atoi(*filename));
	}

	val &= ~flags;

	if (fcntl(atoi(*filename), F_SETFL, val)) {
		err_sys("fcntl error for fd %d", atoi(*filename));
	}
}

void get_fl(char *filename[])
{
	int val;
	if ((val = fcntl(atoi(*filename), F_GETFL, 0)) < 0) {
		err_sys("fcntl error for fd %d", atoi(*filename));
	}

	switch (val & O_ACCMODE) {
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;	
		case O_RDWR:
			printf("read write");
			break;
		default:
			err_dump("unknown access mode");
	}

	if (val & O_APPEND) {
		printf(", append");	
	}

	if (val & O_NONBLOCK) {
		printf(", nonblocking");	
	}

#if defined(O_SYNC)
	if (val & O_SYNC) {
		printf(", synchronous writes");		
	}
#endif
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if (val & O_FSYNC) {
		printf(", synchronous writes");	
	}
#endif
	putchar('\n');
}
