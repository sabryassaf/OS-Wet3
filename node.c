#include "node.h"

struct node_custom {
    struct node_custom *next;
    struct timeval arrivalTime;
    struct timeval dispatchTime;
    struct timeval pickupTime;
    int fd;
};

Node node_create(int fd, struct timeval arrivalTime) {
    Node new_node = malloc(sizeof(struct node_custom));
    if (!new_node) {
        return NULL;
    };
    // initiate a Node for the job, with the file descriptor and the arrival time
    new_node->fd = fd;
    new_node->arrivalTime = arrivalTime;
    new_node->next = NULL;
    return new_node;
    //test git
}