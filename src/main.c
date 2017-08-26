#include <zmq.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "zhelpers.h"

static const char *JSON_STRING =
 "{\"type\": \"sensorValue\", \"value\": [retro, true], \"location\": 1000,\n  "
 "\"groups\": [\"users\", \"wheel\", \"audio\", \"video\"]}";


int main (void)
{
  	
  	 static const s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

     void *context = zmq_ctx_new();
     void *publisher = zmq_socket(context, ZMQ_PUB);

     zmq_bind(publisher, "tcp://*:8088");

     while(1){
	      s_send(publisher,"ALIM");
	       printf("fired");
	       fflush(stdout);
	       sleep(1);
     }
     zmq_close(publisher);


    return 0;
}
