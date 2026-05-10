/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	unsigned long start = 0;
	if (tracing==1)
	{
		start = ctr1000;
	}
	int val=currpid;
	if (tracing==1)
	{
		frequency[currpid][2]++;
		Etime[currpid][2]= Etime[currpid][2] + (ctr1000-start) ;
	}
	return(val);
}
