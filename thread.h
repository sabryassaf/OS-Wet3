#ifndef THREAD_H
#define THREAD_H

typedef struct thread_t* Thread;

Thread createThread(int id);

int getId(Thread thread);
int getStatRequests(Thread thread);
int getDynamicRequests(Thread thread);
int getTotalRequests(Thread thread);

void increaseDynamicReq(Thread thread);
void increaseStaticReq(Thread thread);
void increaseTotalReq(Thread thread);
#endif //THREAD_H