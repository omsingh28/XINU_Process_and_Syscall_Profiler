/* signaln.c - signaln */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  signaln -- signal a semaphore n times
 *------------------------------------------------------------------------
 */
SYSCALL signaln(int sem, int count)
{
	unsigned long start = 0;
	if (tracing==1)
		{
			start = ctr1000;
		}
	STATWORD ps;    
	struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || semaph[sem].sstate==SFREE || count<=0) {
		restore(ps);
		if(tracing==1)
		{
			frequency[currpid][17]++;
			Etime[currpid][17]= Etime[currpid][17] + (ctr1000-start) ;
		}
		return(SYSERR);
	}
	sptr = &semaph[sem];
	for (; count > 0  ; count--)
		if ((sptr->semcnt++) < 0)
			ready(getfirst(sptr->sqhead), RESCHNO);
	resched();
	restore(ps);
	if(tracing==1)
	{
		frequency[currpid][17]++;
		Etime[currpid][17]= Etime[currpid][17] + (ctr1000-start) ;
	}
	return(OK);
}
