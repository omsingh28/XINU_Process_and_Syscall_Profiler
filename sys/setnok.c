/* setnok.c - setnok */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  setnok  -  set next-of-kin (notified at death) for a given process
 *------------------------------------------------------------------------
 */
SYSCALL	setnok(int nok, int pid)
{
	unsigned long start = 0;
	if (tracing==1)
	{
		start = ctr1000;
	}
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid)) {
		restore(ps);
		if(tracing==1)
		{
			frequency[currpid][14]++;
			Etime[currpid][14]= Etime[currpid][14] + (ctr1000-start) ;
		}
		return(SYSERR);
	}
	pptr = &proctab[pid];
	pptr->pnxtkin = nok;
	restore(ps);
	if(tracing==1)
	{
		frequency[currpid][14]++;
		Etime[currpid][14]= Etime[currpid][14] + (ctr1000-start) ;
	}
	return(OK);
}
