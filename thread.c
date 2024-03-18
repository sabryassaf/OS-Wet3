#include "thread.h"

//thread struct identefiers:

typedef struct thread_t {
    int id;
    int totalCount;
    int staticRequests;
    int dynamicRequests;
} *Thread;

Thread createThread(int id)
{
    Thread newThread = malloc(sizeof (struct thread_t));
    if(newThread){
        newThread->id = id;
        newThread->totalCount = 0;
        newThread->staticRequests = 0;
        newThread->dynamicRequests = 0;
    }
    return newThread;
}


int getId(Thread thread)
{
    return thread->id;
}

int getStatRequests(Thread thread)
{
    return thread->staticRequests;
}

int getDynamicRequests(Thread thread)
{
    return thread->dynamicRequests;
}

int getTotalRequests(Thread thread)
{
    return thread->totalCount;
}

void increaseDynamicReq(Thread thread)
{
    (thread->dynamicRequests)++;
}

void increaseStaticReq(Thread thread)
{
    (thread->staticRequests)++;
}

void increaseTotalReq(Thread thread)
{
    (thread->totalCount)++;
}