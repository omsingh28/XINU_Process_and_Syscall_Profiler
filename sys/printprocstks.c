#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

static inline unsigned long read_esp(void) {
    unsigned long v;
    __asm__ __volatile__("movl %%esp, %0" : "=r"(v));
    return v;
}

void printprocstks(int priority){

    int id=0;
    for (id=0;id< NPROC; id++){
        struct pentry *process = &proctab[id];
        if(process && (process->pprio > priority) && process->pstate != PRFREE ){
            kprintf("Process[%s]\n", process->pname);
            kprintf("\tpid: %d\n", id);
            kprintf("\tpriority: %d\n", process->pprio);
            kprintf("\tbase: 0x%08x\n",process->pbase);
            kprintf("\tlimit: 0x%08x\n", process->plimit);
            kprintf("\tlen: %d\n", process->pstklen);
            if(process->pstate == PRCURR)
            {
                kprintf("\tpointer: 0x%08x\n",read_esp());
            }
            else
            {
                kprintf("\tpointer: 0x%08x\n", process->pesp);
            }
        }
    }
}

