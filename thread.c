#include "thread.h"
#include <stdlib.h>


//thread struct identefiers:

struct thread_custom {
    int id;
    int total_count;
    int stattic_requests;
    int dynamic_requests;
};

Thread newThread(int id) {
    Thread new_thread = (Thread)malloc(sizeof(struct thread_custom));
    if (!new_thread) {
        return NULL;
    }
    new_thread->id = id;
    new_thread->total_count = 0;
    new_thread->stattic_requests = 0;
    new_thread->dynamic_requests = 0;
    return new_thread;
}