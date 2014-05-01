/*****************************************************************************

SUI_HK

Surgical Robot Master control using PHANToM OMNI
Ganesh Sankaranarayanan
BioRobotics Laboratory
08/04/05
Modified by Kosy 10/24/05
Modified by Hawkeye 4/17/06
Modified by Ganesh 5/17/06

*******************************************************************************/
#include "stdafx.h"
#include <HDU/hduQuaternion.h>

#include "PracticalSocket/PracticalSocket.h"
#include "../VS_GUI_SERVER/CommonDS.h"
#include "ITPteleoperation.h"
#include "omni_comm.h"
#include "coordinateSystems.h"
#include <pthread.h>

#define FALSE 0
#define TRUE 1
#define OMNI1 0
#define OMNI2 1
#define TIMEOUT_SECS 0
#define TIMEOUT_USECS 100

#define THOUSAND 1000
#define MILLION  (THOUSAND*THOUSAND)
#define round(x) (x)

/*Identifier for two Omni device -- Name it wisely as you wish */

#define OMNI_NAME_1 "Omni_Left"
#define OMNI_NAME_2 "Omni_Right"

//Global variable for world coordinate scale uniform in all 3 axis.
HDdouble scale = 0.1;

// Three camera rotation angles
extern double th1, th2, th3;

int supportedCalibrationStyles;
int calibrationStyle;

//Global variable for reading device button
int gold_button_graspON;
int green_button_graspON;

hduVector3Dd pos_delta[2];
hduVector3Dd rot_delta[2];
hduVector3Dd pos_offset[2];
hduVector3Dd rot_offset[2];
hduMatrix xfs[2];

extern const hduMatrix rotXMx;
extern const hduMatrix rotYMx;
extern const hduMatrix rotZMx;

int g_footpedal = 0;
int g_key = 0;
unsigned int servo=0;
bool indexing= false;

#define ADDR_BUBBLES   "192.168.0.101"
#define ADDR_BUTTERCUP "192.168.0.100"

extern stMA2UI_DATA Ma2UIdata;
extern stUI2MA_DATA UI2Madata;

// Global Haptic device identifier

//HHD devHandle[OMNI1],devHandle[OMNI2]; /*Dual Master device */
HHD devHandle[2]; /*Dual Master device */

// Global variable for testing.
bool oneOmni=false;
bool leftDevice=false;
bool rightDevice=false;
bool greenArm=false;
bool goldArm=false;

int c_counter = 0;
hduVector3Dd temp_delta;
const hduQuaternion q_identity;

// Communication object for communication with SUI and Slave robot
Omni_Comm comm(&Ma2UIdata, &UI2Madata);


/*******************************************************************************
READ FORCE FROM NETWORK
********************************************************************************/
float recvString[6] = {0}; // Buffer for echo string + \0
void *readNetwork(void *p)
{
    const int MAXRCVSTRING = 4096; // Longest string to receive
    unsigned short echoServPort = atoi("5000");     // First arg:  local port
    UDPSocket sock(echoServPort);                

    string sourceAddress;              // Address of datagram source
    unsigned short sourcePort;         // Port of datagram source*/
    cout<<"\r\ncreating network thread";
    cout.flush();
    while(1){
    int bytesRcvd = sock.recvFrom(recvString, 6*sizeof(float), sourceAddress, 
                                  sourcePort);
  //  std::cout<<"\n recvString:"<<recvString[1]<<"\n";
    }
}
/*******************************************************************************
Incremental position update callback function
*******************************************************************************/
HDCallbackCode HDCALLBACK PositionUpdate(void *data)
{
	servo++;
	int nButtons = 0, footpedal;
	int bttn[2] = {0,0};
	hduVector3Dd position[2];
	hduMatrix rotMat;
	hduMatrix xform;
	static hduQuaternion qPrev[2];
	static hduVector3Dd p_position[2];

	hduQuaternion qCurr[2], qIncr[2];

	HDErrorInfo error;
	int rl2sui;

	footpedal = comm.Check_Flag(FPEDAL_RIGHT) ? TRUE : FALSE;

	for (int devID=OMNI1; devID <= OMNI2; devID++){
		hdEnable(HD_FORCE_OUTPUT);
		// Set current frame and device
		hdBeginFrame(devHandle[devID]);
		hdMakeCurrentDevice(devHandle[devID]);

		// Get button state using bitmask:
		hdGetIntegerv(HD_CURRENT_BUTTONS, &nButtons);
		
		bttn[devID] = 0;
		if ( nButtons & HD_DEVICE_BUTTON_2 ) // button 2 releases grasp
			bttn[devID] = -1;
		else if ( nButtons & HD_DEVICE_BUTTON_1 ) // button 1 engages grasp
			bttn[devID] = 1;

		// Get omni position in pedal dn state
		hdGetDoublev(HD_CURRENT_TRANSFORM, xform);

		applyTransforms(xform, devID );


		// position
		position[devID] = hduVector3Dd(xform[3][0], xform[3][1], xform[3][2]);
		hduVecScaleInPlace(position[devID],scale);		// position scaling

		// rotation
		rotMat.set(xform);
		rotMat.getRotationMatrix(rotMat);
		qCurr[devID] = hduQuaternion(rotMat);

		footpedal = comm.Check_Flag(FPEDAL_RIGHT) ? TRUE : FALSE;
		hduVector3Dd f1(recvString[devID*3],recvString[devID*3+1],recvString[devID*3+2]);
		//hduVector3Dd f1(0.0,0.0,0.0);
		if (footpedal == TRUE){
			//applyInverseTransforms(f1);
			//cout<<"I am here"<<endl;
			//hduVector3Dd f1(1,0,0);
			hdSetDoublev(HD_CURRENT_FORCE,f1);
		
	}
		//for full wrist switch to 0
		int fake_rotation = 0;
		if( comm.Check_Flag(FPEDAL_RIGHT) && comm.Check_Flag(BASIC_START) )
		{
			// Get position increment
			hduVecSubtract(pos_delta[devID],position[devID],p_position[devID]);		// delta = current - previous
			//std::cout<<pos_delta<<"\n";
			// Get quaternion increment
			qIncr[devID] = qPrev[devID].inverse()*qCurr[devID];

			
			if (fake_rotation)
			{
				rotMat.set(rotZIx);
				rotMat.getRotationMatrix(rotMat);
				qIncr[devID] = hduQuaternion(rotMat);
			}
		} 

		else 
		{
			indexing=true;

			// Set zero increments
			hduVecSet(pos_delta[devID],0.0,0.0,0.0);
			qIncr[devID] = q_identity;
			bttn[devID] = 0;
		}
		switch(g_key)
			{
			case 0: // 0
				//hduVecSet(pos_delta[0],0.0,0.0,0.0);
				break;
			case 1: // k
				hduVecSet(pos_delta[0],0.0,0.0,-0.01);
				break;
			case 2: //h
				hduVecSet(pos_delta[0],0.0,0.0,0.01);
				break;
			case 3: // u
				hduVecSet(pos_delta[0],0.01,0.0,0.0);
				break;
			case 4: // j 
				hduVecSet(pos_delta[0],-0.01,0.0,0.0);
				break;
			case 5: // a
				hduVecSet(pos_delta[0],0.000,0.0,-0.005);
				break;
		}

		// prev. position
		p_position[devID][0] = position[devID][0];
		p_position[devID][1] = position[devID][1];
		p_position[devID][2] = position[devID][2];

		// prev. rotation
		qPrev[devID] = qCurr[devID];

		// fake runlevel to GUI
		rl2sui = 3-comm.Check_Flag(FPEDAL_RIGHT);
		

		hdEndFrame(devHandle[devID]);
	}

	if(comm.Check_Flag(BASIC_PROGRAM)) { // when UI allows 'Server' run
		comm.Update_UDP_Data(pos_delta, qIncr, bttn, footpedal, servo, xfs );  // Update robot command packet
		comm.Send_UDP();
	}

	if(servo%100 == 1) {
		//std::cout<<" \t"<<pos_delta[0]<<std::endl;
		comm.Update_MA2UI(pos_delta, rl2sui, servo);			// Update SUI data
		comm.Send_TCP();
	}
	if(servo%1000 == 1) {
		//printf("f:%d s:%d IP:%d t:%d Omni_t:%d\n", UI2Madata.flag01, UI2Madata.scale, UI2Madata.UDPaddr, (int)UI2Madata.tick, servo );
		/*printf("delPos[omni1]: %d %d %d\tdelPos[omni2]: %d %d %d\n",
		int(round(pos_delta[0][0]*THOUSAND)),
		int(round(pos_delta[0][1]*THOUSAND)),
		int(round(pos_delta[0][2]*THOUSAND)),
		int(round(pos_delta[1][0]*THOUSAND)),
		int(round(pos_delta[1][1]*THOUSAND)),
		int(round(pos_delta[1][2]*THOUSAND)));*/
	}

	if (HD_DEVICE_ERROR(error = hdGetError())) {
		hduPrintError(stderr, &error, "Error during main scheduler callback\n");
		//		if (hduIsSchedulerError(&error))    return HD_CALLBACK_DONE;
	}

	return HD_CALLBACK_CONTINUE;
}

/******************************************************************************
main function
Initialize the device, create a callback to handle sphere forces, terminate
upon key press.
******************************************************************************/
int main(int argc, char* argv[])
{
	char *input="testing";

	if(argc>=2){
		if(strcmp(argv[1],input)!=0){
			printf("The input format is omniclient [testing] [0[GoldArm]/1[GreenArm]]\n");
			return -1;
		}

		oneOmni=true;
		if(argc>=3 && atoi(argv[2])==1){
			greenArm=true;
			goldArm=false;
			printf("You Have Selected Green  Arm to Control \n");}
		else {
			greenArm=false;
			goldArm=true;
			printf("You Have Selected Gold Arm (or default) to Control \n");
		}
	}

	else{
		printf("The Master is Selected to Work in Normal Mode\n");
		oneOmni=false;
		goldArm=true;
		greenArm=true;
	}

	pthread_t thread1;
    cout<<"begin thread create\r\n";
    pthread_create(&thread1,NULL,readNetwork,NULL);

	HDErrorInfo error;
	char ch = 'r';
	int hstdin = (int) GetStdHandle(STD_INPUT_HANDLE);
	fd_set readSet;
	TIMEVAL timeout = {TIMEOUT_SECS, TIMEOUT_USECS};
	int nfound;
	int the_tcpsock;

	// initialize communication with the robot //
	comm.Initialize_UDP_Robot(argc, argv);
	while(!comm.Initialize_TCP_GUI()) {
	cout << "TCPIP initialization failed retry in 5 sec." << endl;
	Sleep(5);
	//return 1;
	}
	cout << "KS : TCPIP initialized " << endl;

	// Initialize FD_SET //
	FD_ZERO(&readSet);
	the_tcpsock = comm.tcpsocket->sockDesc;
	FD_SET(the_tcpsock, &readSet);

	devHandle[OMNI1] = hdInitDevice(OMNI_NAME_1);			// Initialize the first omni device 
	if (HD_DEVICE_ERROR(error = hdGetError())) 
	{
		hduPrintError(stderr, &error, "Failed to initialize first haptic device");
		fprintf(stderr, "\nPress any key to quit.\n");
		_getch();
		return -1;

	}
//	hdEnable(HD_FORCE_OUTPUT);				// enable force for the first device
	devHandle[OMNI2] = hdInitDevice(OMNI_NAME_2);			// Initialize the first omni device 

	if (HD_DEVICE_ERROR(error = hdGetError())) 
	{
		hduPrintError(stderr, &error, "Failed to initialize second haptic device");
			fprintf(stderr, "\nPress any key to quit.\n");
			_getch();
			return -1;
	}
//	hdEnable(HD_FORCE_OUTPUT);				// enable force for the first device

	if(oneOmni && rightDevice && leftDevice){
		printf("You Are Trying to Run Testing With Both Omni's ON.\n We Are Defualting To Left Omni\n");
		rightDevice=false;
	}

	hdSetSchedulerRate(1000);				// Set the scheduler rate

	hdStartScheduler();
	if (HD_DEVICE_ERROR(error = hdGetError())) {
		hduPrintError(stderr, &error, "Failed to start scheduler");
		fprintf(stderr, "\nPress any key to quit.\n");
		return -1;
	}

	// Debug for variables
	if(oneOmni)
		printf("One Omni mode is enabled\n");
	if(greenArm)
		printf("Green Arm is Controlled\n");
	if(goldArm)
		printf("Gold Arm is Controlled\n");

	HDSchedulerHandle hMasterCallback;
	// Application loop - schedule our call to the main callback. //
	if(!oneOmni){
		printf("The Master is Operating on Normal Mode With Two Omni's\n");
		hMasterCallback = hdScheduleAsynchronous(
			PositionUpdate, 0, HD_MAX_SCHEDULER_PRIORITY);		// Setup timer callback function
	}
	else{
		printf("The Master is Operating With One Omni\n");
		hMasterCallback = hdScheduleAsynchronous(
			PositionUpdate, 0, HD_MAX_SCHEDULER_PRIORITY);
	}

	hdStartScheduler();					// Start the servo loop scheduler
	cout << "KS : Scheduler started." << endl;

	while ( ch != 'q') {// 	ENABLE ME   && comm.Check_Flag(BASIC_PROGRAM) ) {
		timeout.tv_sec = TIMEOUT_SECS;
		timeout.tv_usec = TIMEOUT_USECS;
		nfound = select( 1 , &readSet, NULL, NULL, &timeout );		// check the TCP Socket
		if ( nfound < 0 ) {						// Socket error
			cerr << "Socket error "<<nfound<<" : "<<WSAGetLastError()<<" \n";
			cout << "sockedesc:"<< comm.tcpsocket->sockDesc<<endl;
			//			Sleep(10);
			//			break;
		}
		if ( nfound > 0 && FD_ISSET(the_tcpsock, &readSet)) {			// TCP socket ready to read
			//cout << "recv TCP...\n";
			comm.Recv_TCP();
			comm.Check_UI2MA(0);// 0 means not to dispay the message
		} 
		FD_CLR(the_tcpsock,&readSet);					// Reset fd_set
		FD_SET(the_tcpsock,&readSet);					//  ""

		if( _kbhit() )							// check for keyboard input`
		{
			ch = _getch();
			switch(ch)
			{
			case 'd':
				cout << "set pedal down\n";
				g_footpedal = 1;
				break;
			case 'e':
				cout << "set pedal up\n";
				g_footpedal = 0;
				break;
			case '0':
				cout << "stop \n";
				g_key = 0;
				break;
			case 'k':
				cout << "right\n";
				g_key = 1;
				break;
			case 'h':
				cout << "left\n";
				g_key = 2;
				break;
			case 'u':
				cout << "up \n";
				g_key = 3;
				break;
			case 'j':
				cout << "down \n";
				g_key = 4;
				break;
			case 'a':
				cout << "autonomous \n";
				g_key = 5;
				break;

			}
		}
		if (!hdWaitForCompletion(hMasterCallback, HD_WAIT_CHECK_STATUS)) {
			fprintf(stderr, "\nThe main scheduler callback has exited\n");
			fprintf(stderr, "\nPress any key to quit.\n");
			_getch();
			break;
		}
	}

	try {
		comm.tcpsocket->cleanUp();
	} 
	catch (SocketException SE) {
		cerr<< "ERROR: Socket cleanUp failed.\n";
	}

	hdStopScheduler();					// Stop the servo loop scheduler
	hdUnschedule(hMasterCallback);		// un-schedule callback function
	hdDisableDevice(devHandle[OMNI1]);			// Disable omni 1
	hdDisableDevice(devHandle[OMNI2]);			// Disable omni 2

	cout << "Ended application loop\n Press any key and exit." << endl;
	_getch();
	return 0;
} // end: main






	////////////// For the second omni device ////////////
	////hdBeginFrame(devHandle[OMNI2]);
	////hdMakeCurrentDevice(devHandle[OMNI2]);

	////// Get button state using bitmask:
	////hdGetIntegerv(HD_CURRENT_BUTTONS, &nButtons);
	////if ( nButtons & HD_DEVICE_BUTTON_2 ) // button 2 releases grasp
	////	bttn[OMNI2] = -1;
	////else if ( nButtons & HD_DEVICE_BUTTON_1 ) // button 1 engages grasp
	////	bttn[OMNI2] = 1;

	////// Get current device transform in ITP frame
	////hdGetDoublev(HD_CURRENT_TRANSFORM, xform);
	////applyTransforms(xform);

	////// Get position
	////position[OMNI2] = hduVector3Dd(xform[3][0], xform[3][1], xform[3][2]);
	////hduVecScaleInPlace(position[OMNI2], scale);		// position scaling

	////// Get quaternion rotation
	////rotMat.set( xform );
	////rotMat.getRotationMatrix(rotMat);
	////qCurr[OMNI2] = hduQuaternion(rotMat);

	////if( comm.Check_Flag(FPEDAL_RIGHT) && comm.Check_Flag(BASIC_START) ) 
	////{
	////	// position delta
	////	hduVecSubtract(pos_delta[OMNI2], position[OMNI2], p_position[OMNI2]);		// delta = current - previous
	////	// rotation delta
	////	qIncr[OMNI2] = qPrev[OMNI2].inverse()*qCurr[OMNI2];
	////} 
	////// Send zero deltas in pedal up state.  (send last button state)
	////else 
	////{
	////	// Set zero deltas
	////	hduVecSet(pos_delta[OMNI2],0.0,0.0,0.0);
	////	qIncr[OMNI2] = q_identity;
	////	bttn[OMNI2] = 0;
	////}

	////// Update prev. transform
	////p_position[OMNI2][0] = position[OMNI2][0];
	////p_position[OMNI2][1] = position[OMNI2][1];
	////p_position[OMNI2][2] = position[OMNI2][2];
	////qPrev[OMNI2] = qCurr[OMNI2];
	////// Send pedal state as runlevel to SGUI
	////rl2sui =  3-(comm.Check_Flag(FPEDAL_RIGHT));	

	////hdEndFrame(devHandle[OMNI2]);
	///////////////////////////////////////////////////////
