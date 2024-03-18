#include "segel.h"
#include "request.h"

// 
// server.c: A very, very simple web server
//
// To run:
//  ./server <portnum (above 2000)>
//
// Repeatedly handles HTTP requests sent to this port number.
// Most of the work is done within routines written in request.c
//

// HW3: Parse the new arguments too
void getargs(int *port, int argc, char *argv[], int* numberOfThreads, int* queueSize, char* schedAlgorithm)
{   

    //changed the provided function to suit our needs
    if (argc < 5) {
	fprintf(stderr, "Usage: %s <port>\n", argv[0]);
	exit(1);
    }
    *port = atoi(argv[1]);
    *numberOfThreads = atoi(argv[2]);
    *queueSize = atoi(argv[3]);

    //setUp the scheduling algorithm: block, dt, dh, bf, random
    if (strcmp(argv[4], "block") == 0) {
        *schedAlgorithm = "B";
    } else if (strcmp(argv[4], "dt") == 0) {
        *schedAlgorithm = "T";
    } else if (strcmp(argv[4], "dh") == 0) {
        *schedAlgorithm = "H";
    } else if (strcmp(argv[4], "bf") == 0) {
        *schedAlgorithm = "F";
    } else if (strcmp(argv[4], "random") == 0) {
        *schedAlgorithm = "R";
    } else {
        fprintf(stderr, "Usage: %s <port> <number of threads> <queue size> <scheduling algorithm>\n", argv[0]);
        exit(1);
    }


}


int main(int argc, char *argv[])
{
    // initiate the required integers
    int listenfd, connfd, port, clientlen, numberOfThreads, queueSize;
    
    // initiate the algorithm specifier:
    // block - B, dt - T, dh - H, bf - F, random - R
    char schedAlgorithm;

    // initiate timeval arguemnt
    struct timeval systemTime;

    struct sockaddr_in clientaddr;

    // initiate 2 pthread condidionts to fullfill block, block_flush overload handling

    //pthread cond 1: will be responsible for buffer availability (Block handling)
    pthread_cond_t available_buffer;
    int holder = pthread_cond_init(&available_buffer, NULL);
    if (holder != 0 ) {
        return 0;
    };

    // pthread cond 2: will be resposible for block_flush
    pthread_cond_t flusshed_queue;
    holder = pthread_cond_init(&flusshed_queue, NULL);
    if (holder != 0 ) {
        //incase condition 2 failed, destroy condition 1
        pthread_cond_destroy(&available_buffer);
        return 0;
    };
    
    // initiate pthread mutex lock to be used by threads
    pthread_mutex_t lock;
    holder = pthread_mutex_init(&lock, NULL);
    if (holder != 0 ) {
        //incase lock failed, destroy the 2 conditions
        pthread_cond_destroy(&available_buffer);
        pthread_cond_destroy(&flusshed_queue);
        return 0;
    }


    getargs(&port, argc, argv, &numberOfThreads, &queueSize, &schedAlgorithm);

    //initiate threads Array
    pthread_t* threadsArray = malloc(numberOfThreads*(sizeof(pthread_t)));
    if (!threadsArray) {
        //malloc failed, destory pthread conditions and mutex lock
        pthread_cond_destroy(&available_buffer);
        pthread_cond_destroy(&flusshed_queue);
        pthread_mutex_destroy(&lock);
    }
    
    


    listenfd = Open_listenfd(port);
    while (1) {
	clientlen = sizeof(clientaddr);
	connfd = Accept(listenfd, (SA *)&clientaddr, (socklen_t *) &clientlen);

	// 
	// HW3: In general, don't handle the request in the main thread.
	// Save the relevant info in a buffer and have one of the worker threads 
	// do the work. 
	// 
	requestHandle(connfd);

	Close(connfd);
    }

}


    


 