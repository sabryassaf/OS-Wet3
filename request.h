#ifndef __REQUEST_H__
#define __REQUEST_H__
#include "thread.h"
#include "queue.h"

void requestHandle(int fd, Thread thread, Node nodeRequest);
void requestError(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg, Node nodeRequest);
void requestServeDynamic(int fd, char *filename, char *cgiargs, Node nodeRequest);
void requestServeStatic(int fd, char *filename, int filesize, Node nodeRequest);


#endif
