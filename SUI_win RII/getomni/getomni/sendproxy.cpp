
#include "stdafx.h"
#include <iostream>
#include "PracticalSocket.h"
#include <pthread.h>
#include "structs.h"

#include <string.h> // memcpy

	//addr_Robot = ADDR_BUBBLES;
	strcpy(addr_Robot, ADDR_BUBBLES);
	port_Robot = 36000;

u_struct del_proxymsg;
memcpy(&del_proxymsg , &msgHeader , sizeof(struct u_struct));
del_proxymsg

udpsocket.sendTo(&msgHeader,sizeof(u_struct),addr_Robot,port_Robot);