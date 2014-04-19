#include "apue.h"
#include <signal.h>
#include <unistd.h>

static void sig_alrm(int signo)
{
	// nothing to do	
}

unsigned int sleep1(unsigned int nsec)
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
		return (nsec);	
	}	

	alarm(nsec);
	pause();
	return (alarm(0));
}

int main(void)
{
	printf("start.....");
	sleep1(2);
	printf("end.....");	
	return 0;
}
