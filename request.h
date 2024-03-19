#ifndef __REQUEST_H__
#define __REQUEST_H__
#include "thread.h"
#include "queue.h"

void requestHandle(int fd, Thread thread, Node nodeRequest);
void requestError(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg, Thread thread, Node nodeRequest);
void requestServeDynamic(int fd, char *filename, char *cgiargs, Thread thread,  Node nodeRequest);
void requestServeStatic(int fd, char *filename, int filesize, Thread thread, Node nodeRequest);


#endif
