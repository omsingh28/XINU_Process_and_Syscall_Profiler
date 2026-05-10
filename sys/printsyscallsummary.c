#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

int tracing = 0;
int frequency[NPROC][TSC];
int Etime[NPROC][TSC];

char sname[TSC][15] = 
{
    "freemem",
    "chprio",
    "getpid",
    "getprio",
    "gettime",
    "kill",
    "receive",
    "recvclr",
    "recvtim",
    "resume",
    "scount",
    "sdelete",
    "send",
    "setdev",
    "setnok",
    "screate",
    "signal",
    "signaln",
    "sleep",
    "sleep10",
    "sleep100",
    "sleep1000",
    "sreset",
    "stacktrace",
    "suspend",
    "unsleep",
    "wait"
};

void printsyscallsummary(void)
{
    int i = 0;
    int j = 0;
    int Eavg = 0;
    
    for(i= 0;i<NPROC;i++)
    {
        int flag = TRUE;
        for(j=0;j<TSC;j++)
        {   
            if (frequency[i][j]>0)
            {
                if(flag == TRUE){
                    kprintf("Process [pid:%d]\n",i);
                    flag = FALSE;
                }
                Eavg = Etime[i][j]/frequency[i][j];
                kprintf("\tSyscall: %s, count: %d, average execution time: %d (ms)\n",sname[j],frequency[i][j],Eavg);
            }
        }
    }
}

void syscallsummary_start(void)
{
    int i=0;
    int j=0;
    for(i=0;i<NPROC;i++){
        for(j=0;j<TSC;j++){
            frequency[i][j]=0;
            Etime[i][j]=0;
        }
    }
    tracing = 1;
}
void syscallsummary_stop(void)
{
    tracing = 0;
}