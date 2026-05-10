/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */
SYSCALL getprio(int pid)
{
	unsigned long start = 0;
	if (tracing==1)
	{
		start = ctr1000;
	}
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
			if (tracing==1)
			{
				frequency[currpid][3]++;
				Etime[currpid][3]= Etime[currpid][3] + (ctr1000-start) ;
			}
		return(SYSERR);
	}
	restore(ps);
		if (tracing==1)
		{
			frequency[currpid][3]++;
			Etime[currpid][3]= Etime[currpid][3] + (ctr1000-start) ;
		}
	return(pptr->pprio);
}
