/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	unsigned long start = 0;
	if (tracing==1)
	{
		start = ctr1000;
	}
	short	*nxtdev;

	if (isbadpid(pid)){
		if(tracing==1)
		{
			frequency[currpid][13]++;
			Etime[currpid][13]= Etime[currpid][13] + (ctr1000-start) ;
		}
		return(SYSERR);
	}
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	if(tracing==1)
	{
		frequency[currpid][13]++;
		Etime[currpid][13]= Etime[currpid][13] + (ctr1000-start) ;
	}
	return(OK);
}
