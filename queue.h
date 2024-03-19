#ifndef QUEUE
#define QUEUE
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include "segel.h"
#include <stdbool.h>

//// THE NODES ARE REQUESTS
typedef struct node_t* Node;

Node createNode(int fd, struct timeval arrival);
void deleteCurrentNode(Node toDelete);


//int getFd(Node node);
bool equal(Node n1, Node n2);

struct timeval* getArrivalTime(Node node);
struct timeval* getDispatchTime(Node node);
struct timeval* getPickUpTime(Node node);


// THE QUEUE IS THE REQUESTS QUEUE


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