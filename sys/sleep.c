/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{
	unsigned long start = 0;
	if (tracing==1)
		{
			start = ctr1000;
		}
	STATWORD ps;    
	if (n<0 || clkruns==0){
		if(tracing==1)
		{
			frequency[currpid][18]++;
			Etime[currpid][18]= Etime[currpid][18] + (ctr1000-start) ;
		}
		return(SYSERR);
	}
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		if(tracing==1)
		{
			frequency[currpid][18]++;
			Etime[currpid][18]= Etime[currpid][18] + (ctr1000-start) ;
		}
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
	if(tracing==1)
	{
		frequency[currpid][18]++;
		Etime[currpid][18]= Etime[currpid][18] + (ctr1000-start) ;
	}
	return(OK);
}
