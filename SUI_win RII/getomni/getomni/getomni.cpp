// getomni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "PracticalSocket.h"
#include <pthread.h>
#include "structs.h"
#include <string.h> // memcpy

#define ADDR_BUBBLES   "128.95.205.132" // replace with r2b3 address

char addr_Robot[16];
unsigned short sourcePort, port_Robot;   
u_struct msgHeader;

int uSize=sizeof(struct u_struct);


void *readNetwork(void *p)
{
	int omni_delx[2];
	int omni_dely[2];
	int omni_delz[2];
    const int MAXRCVSTRING = 4096; // Longest string to receive
    unsigned short echoServPort = atoi("5000");     // First arg:  local port
    UDPSocket sock(echoServPort);                

    string sourceAddress;              // Address of datagram source
    unsigned short sourcePort;         // Port of datagram source*/
    cout<<"\r\ncreating network thread";
    cout.flush();
    while(1){
    int bytesRcvd = sock.recvFrom(&msgHeader, uSize, sourceAddress, 
                                  sourcePort);
    }

    for(int i=0 ; i<2 ; i++)
	{
		omni_delx[i] = msgHeader.delx[i];
		omni_dely[i] = msgHeader.dely[i];
		omni_delz[i] = msgHeader.delz[i];
	}

}

void *sendProxy(void *p)
{
	u_struct proxymsg;
	UDPSocket udpsocket;
	while(1){
	memcpy(&proxymsg , &msgHeader , sizeof(struct u_struct));
	    for(int i=0 ; i<2 ; i++)
		{
			proxymsg.delx[i] = proxy_delx[i];//in microns!! 
			proxymsg.dely[i] = proxy_dely[i];
			proxymsg.delz[i] = proxy_delz[i];
		}

	udpsocket.sendTo(&proxymsg,sizeof(u_struct),addr_Robot,port_Robot);
	}
}

int main(int argc, char* argv[])
{
	strcpy(addr_Robot, ADDR_BUBBLES);
	port_Robot = 36000;
	pthread_t thread1;
    cout<<"begin thread create\r\n";
    pthread_create(&thread1,NULL,readNetwork,NULL);



	
	return 0;
}


