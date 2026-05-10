/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
	unsigned long start = 0;
	if (tracing==1)
	{
		start = ctr1000;
	}
extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE){
		if(tracing==1)
		{
			frequency[currpid][10]++;
			Etime[currpid][10]= Etime[currpid][10] + (ctr1000-start) ;
		}
		return(SYSERR);
	}
	if(tracing==1)
	{
		frequency[currpid][10]++;
		Etime[currpid][10]= Etime[currpid][10] + (ctr1000-start) ;
	}
	return(semaph[sem].semcnt);
}
