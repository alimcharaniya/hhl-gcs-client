#include <zmq.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "zhelpers.h"

int main (void)
{
     void *context = zmq_ctx_new();
     void *publisher = zmq_socket(context, ZMQ_PUB);
	
     zmq_bind(publisher, "tcp://*:5555");
     
     while(1){
	s_send(publisher,"ALIM");
	printf("fired");
	fflush(stdout);
	sleep(1);

     }
    zmq_close(publisher);



    return 0;
}