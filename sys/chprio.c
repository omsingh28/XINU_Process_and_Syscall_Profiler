/* chprio.c - chprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{
	unsigned long start = 0;
	if (tracing==1)
	{
		start = ctr1000;
	}
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		if (tracing==1)
	{
		frequency[currpid][1]++;
		Etime[currpid][1]= Etime[currpid][1] + (ctr1000-start) ;
	}
		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);
	if (tracing==1)
	{
		frequency[currpid][1]++;
		Etime[currpid][1]= Etime[currpid][1] + (ctr1000-start) ;
	}
	return(newprio);
}
