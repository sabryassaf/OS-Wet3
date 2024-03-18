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

struct timeval* getArrivalTime(Node node);
struct timeval* getDispatchTime(Node node);
struct timeval* getPickUpTime(Node node);

#endif