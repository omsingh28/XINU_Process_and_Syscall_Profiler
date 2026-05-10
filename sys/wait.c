/* wait.c - wait */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * wait  --  make current process wait on a semaphore
 *------------------------------------------------------------------------
 */
SYSCALL	wait(int sem)
{
	unsigned long start = 0;
	if (tracing==1)
		{
			start = ctr1000;
		}
	STATWORD ps;    
	struct	sentry	*sptr;
	struct	pentry	*pptr;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		if(tracing==1)
		{
			frequency[currpid][26]++;
			Etime[currpid][26]= Etime[currpid][26] + (ctr1000-start) ;
		}
		return(SYSERR);
	}
	
	if (--(sptr->semcnt) < 0) {
		(pptr = &proctab[currpid])->pstate = PRWAIT;
		pptr->psem = sem;
		enqueue(currpid,sptr->sqtail);
		pptr->pwaitret = OK;
		resched();
		restore(ps);
		if(tracing==1)
		{
			frequency[currpid][26]++;
			Etime[currpid][26]= Etime[currpid][26] + (ctr1000-start) ;
		}
		return pptr->pwaitret;
	}
	restore(ps);
	if(tracing==1)
		{
			frequency[currpid][26]++;
			Etime[currpid][26]= Etime[currpid][26] + (ctr1000-start) ;
		}
	return(OK);
}
