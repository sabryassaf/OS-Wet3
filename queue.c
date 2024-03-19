#include "queue.h"
#include <sys/time.h>

struct node_t {
    struct timeval arrivalTime;
    struct timeval dispatchTime;
    int fd;
    struct node_t *next;
};

Node createNode(int fd, struct timeval arrivalTime)
{
    Node newNode = malloc(sizeof(struct node_t));
    if (newNode) {
        newNode->next = NULL;
        newNode->arrivalTime = arrivalTime;
        newNode->fd = fd;
    }
    return newNode;
}

void deleteCurrentNode(Node toDelete)
{
    if(toDelete){
        free(toDelete);
    }
}
void setDispatchTime(Node node) {
    // set dispatch time to be the current time minus arrival time
    gettimeofday(getDispatchTime(node), NULL);
    timersub(getDispatchTime(node), getArrivalTime(node), getDispatchTime(node));
}

/*int getFd(Node node)
{
    if(node){
        return node->fd;
    }
    return -1;
}*/

struct timeval* getArrivalTime(Node node)
{
    return &(node->arrivalTime);
}
struct timeval* getDispatchTime(Node node)
{
    return &(node->dispatchTime);
}


// bool equal(Node n1, Node n2)
// {
//     if (n1->fd == n2->fd)
//         return true;
//     return false;
// }


typedef struct queue_t{
    int size;
    Node head;
} *Queue;

Queue createQueue()
{
    Queue newQueue = malloc(sizeof (struct queue_t));
    if(newQueue)
    {
        newQueue->size = 0;
        newQueue->head = NULL;
    }
    return newQueue;
}

void deleteQueue(Queue queue)
{
    if(queue) {
        Node toDelete = queue->head;
        while(toDelete)
        {
            Node next = toDelete->next;
            Close(toDelete->fd);
            free(toDelete);
            toDelete = next;
        }
        free(queue);
    }
}

int getSize(Queue queue)
{
    if(queue){
        return queue->size;
    }
    return -1;
}

Node getFirstRequest(Queue queue)
{
    if((queue) && (queue->head)){
        return queue->head;
    }
    return NULL;
}

int getFd(Node node) {
    if (node) {
    return node->fd;
    }

    return -1;
}

// bool find(Queue queue, Node toFind)
// {
//     if(queue){
//         Node head = queue->head;
//         while(head){
//             if(equal(head, toFind)){
//                 return true;
//             }
//             head = head->next;
//         }
//     }
//     return false;
// }

void Enqueue(Queue queue, Node node)
{
    if (node && queue){
        Node temp = queue->head;
        if (queue->size == 0)
        {
            queue->head = node;
            queue->size = 1;
            return;
        }
        while(temp->next){
            temp = temp->next;
        }
        temp->next = node;
        (queue->size)++;
    }
}

Node Dequeue(Queue queue)
{
    if(queue->head){
        Node temp = queue->head;
        queue->head = temp->next;
        (queue->size)--;
        temp->next = NULL;
        return temp;
    }
    return NULL;
}

void removeByIndex(Queue queue, int idx)
{
    if((queue) && (idx <= queue->size)){
        Node temp = queue->head;
        if(idx == 0){ //REMOVE THE HEAD
            temp = Dequeue(queue);
            if(temp){
                Close(temp->fd);
                free(temp);
            }
            return;
        }
        while(idx != 0){
            temp = temp->next;
            idx--;
        }
        removeByFd(queue, getFd(temp));
    }
}

void removeByFd(Queue queue, int fd)
{
    if ((queue) && (queue->head)) {
        Node temp = queue->head;
        if(queue->head->fd == fd) {
            Close(temp->fd);
            Dequeue(queue);
            free(temp);
            return;
        }
        while((temp->next) && (temp->next->fd != fd)) {
            temp = temp->next;
        }
        if(temp->next) {
            Node toDelete = temp->next;
            temp->next = toDelete->next;
            close(toDelete->fd);
            free(toDelete);
            (queue->size)--;
        }
    }
}

