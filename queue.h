#ifndef QUEUE
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include "segel.h"

typedef struct queue_t* Queue;

Queue createQueue();
void deleteQueue(Queue toDelete);
int getSize(Queue queue);
Node getFirstRequest(Queue queue);
Node find(Queue queue, Node toFind);
void Enqueue(Queue queue, Node toAdd);
Node Dequeue(Queue queue);
void removeByIndex(Queue queue, int idx);
void removeByFd(Queue queue, int fd);

#endif