#include "node.h"


typedef struct node_t {
    struct timeval arrivalTime;
    struct timeval dispatchTime;
    struct timeval pickupTime;
    int fd;
    struct node_t *next;
}*Node;

Node createNode(int fd, struct timeval arrivalTime)
{
    Node newNode = malloc(sizeof(struct node_t));
    if (newNode) {
        newNode->next = NULL;
        newNode->arrivalTime = arrivalTime;
        newNode->fd = fd;
    }
    return *newNode;
}

/*int getFd(Node node)
{
    if(node){
        return node->fd;
    }
    return -1;
}*/

timeval* getArrivalTime(Node node)
{
    return &(node.arrivalTime);
}
timeval* getDispatchTime(Node node)
{
    return &(node.dispatchTime);
}
timeval* getPickUpTime(Node node)
{
    return &(node.pickupTime);
}

bool equal(Node n1, Node n2)
{
    if ((n1->fd == n2->fd) && (n1->arrivalTime == n2->arrivalTime))
        return true;
    return false;
}