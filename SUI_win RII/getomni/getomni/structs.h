#pragma pack(push)  /* push current alignment to stack */
#pragma pack(1)     /* set alignment to 1 byte boundary */
struct u_struct {
	unsigned int sequence;
	unsigned int pactyp;  
	unsigned int version;

	int delx[2];
	int dely[2];
	int delz[2];
	double Qx[2];
	double Qy[2];
	double Qz[2];
	double Qw[2];
	
	int buttonstate[2];
	int grasp[2];         
	int surgeon_mode;     
	int checksum; 
};
#pragma pack(pop)   /* restore original alignment from stack */