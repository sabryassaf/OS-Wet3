// #include "node.h"

// struct node_t {
//     struct timeval arrivalTime;
//     struct timeval dispatchTime;
//     struct timeval pickupTime;
//     int fd;
//     struct node_t *next;
// };

// Node createNode(int fd, struct timeval arrivalTime)
// {
//     Node newNode = malloc(sizeof(struct node_t));
//     if (newNode) {
//         newNode->next = NULL;
//         newNode->arrivalTime = arrivalTime;
//         newNode->fd = fd;
//     }
//     return newNode;
// }

// /*int getFd(Node node)
// {
//     if(node){
//         return node->fd;
//     }
//     return -1;
// }*/

// struct timeval* getArrivalTime(Node node)
// {
//     return &(node->arrivalTime);
// }
// struct timeval* getDispatchTime(Node node)
// {
//     return &(node->dispatchTime);
// }
// struct timeval* getPickUpTime(Node node)
// {
//     return &(node->pickupTime);
// }

// // bool equal(Node n1, Node n2)
// // {
// //     if (n1->fd == n2->fd)
// //         return true;
// //     return false;
// // }