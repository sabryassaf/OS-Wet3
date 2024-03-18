#ifndef NODE
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "segel.h"

//// THE NODES ARE REQUESTS
typedef struct node_t* Node;

Node createNode(int fd, struct timeval arrival);
//int getFd(Node node);
bool equal(Node n1, Node n2);

timeval* getArrivalTime(Node node);
timeval* getDispatchTime(Node node);
timeval* getPickUpTime(Node node);

#endif