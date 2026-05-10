/* signal.c - signal */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * signal  --  signal a semaphore, releasing one waiting process
 *------------------------------------------------------------------------
 */
SYSCALL signal(int sem)
{
	unsigned long start = 0;
	if (tracing==1)
		{
			start = ctr1000;
		}
	STATWORD ps;    
	register struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		if(tracing==1)
		{
			frequency[currpid][16]++;
			Etime[currpid][16]= Etime[currpid][16] + (ctr1000-start) ;
		}
		return(SYSERR);
	}
	if ((sptr->semcnt++) < 0)
		ready(getfirst(sptr->sqhead), RESCHYES);
	restore(ps);
	if(tracing==1)
	{
		frequency[currpid][16]++;
		Etime[currpid][16]= Etime[currpid][16] + (ctr1000-start) ;
	}
	return(OK);
}
