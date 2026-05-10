#ifndef _LAB0_H_
#define _LAB0_H_
long zfunction(long param);
void printprocstks(int priority);
void printsyscallsummary(void);
void syscallsummary_start(void);
void syscallsummary_stop(void);

#define TSC 27

extern int tracing;
extern int frequency[NPROC][TSC];
extern int Etime[NPROC][TSC];
extern unsigned long ctr1000;

#endif