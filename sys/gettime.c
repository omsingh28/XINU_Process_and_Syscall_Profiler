/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <proc.h>
#include <lab0.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    unsigned long start = 0;
	if (tracing==1)
	{
		start = ctr1000;
	}
    /* long	now; */

	/* FIXME -- no getutim */

    if (tracing==1)
    {
	    frequency[currpid][4]++;
	    Etime[currpid][4]= Etime[currpid][4] + (ctr1000-start) ;
    }
    return OK;
}
