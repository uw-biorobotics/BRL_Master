/*

File: cameraAngle.cpp
Author: Hawkeye King
Written June-2008

This file implements rotation from the Omni frame to the camera view angle.

*/

#include "stdafx.h"
#include <math.h>
#include <HDU/hduMatrix.h>

#define PI 3.14159265358979323846
#define DEGREES PI/180
#define OMNI1 0
#define OMNI2 1


double th1 = 0, th2 = 0, th3 = 0;  // Three camera rotation angles
int useITP = 1;

using namespace std;

void omni2ITPTransform(hduMatrix & xform , int devID)
{
	if (devID == OMNI1){ 
	const hduMatrix omni2ITP(	0	,	1	,	0	,	0	,
								0	,	0	,	-1	,	0	,
								-1	,	0	,	0	,	0	,
								0   ,	0	,	0	,	1	);
	xform.multRight(omni2ITP);
	}
	if (devID == OMNI2){ 
	const hduMatrix omni2ITP(	0	,	1	,	0	,	0	,
								0	,	0	,	-1	,	0	,
								-1	,	0	,	0	,	0	,
								0   ,	0	,	0	,	1	);
	xform.multRight(omni2ITP);
	}


	/*const hduMatrix omni2ITP_x(	0	,	0	,	-1	,	0	,
								1	,	0	,	0	,	0	,
								0	,	-1	,	0	,	0	,
								0   ,	0	,	0	,	1	);*/

}

//
// convertToITP()
//
//  If we're in ITP coordinates perform the conversion her.e
//  If not, return without modifying pos.
//
void convertToITP(hduVector3Dd &pos) {

	// Not using ITP coordinates.  Return
	//if (!useITP) {
	//	return;
	//}

	// Using ITP coordinates.  Apply orthogonal rotation.
	hduVector3Dd temp;

	double R[3][3] = 
	{{	0	,	0	,	-1 },
	 {	1	,	0	,	0 },
	 {	0	,	-1	,	0 }};

	// Matrix-vector multiply R.p
	for (int i = 0; i<3; i++){
		temp[i]=0;
		for (int j=0; j<3; j++){
			temp[i] += R[i][j]*pos[j];
		}
	}

	// Set output
	for (int i = 0; i<3; i++){
		pos[i] = temp[i];
	}

}

//
// applyCameraAngle()
//   Rotation to match omni frame with camera view.
//
//   Precondition: pos is a position vector in the Omni frame.
//   Postcondition: pos is a position vector in the camera view frame. 
//
void applyCameraAngle(hduMatrix &xform){
	double c1 = cos(-th1*DEGREES), c2 = cos(-th2*DEGREES), c3 = cos(th3*DEGREES);
	double s1 = sin(-th1*DEGREES), s2 = sin(-th2*DEGREES), s3 = sin(th3*DEGREES);

	hduMatrix R( c1*c3+s1*s2*s3	,	c3*s1*s2-c1*s3	,	c2*s1 , 0,
				c2*s3			,	c2*c3			,	-1*s2 , 0,
				c1*s2*s3-c3*s1	,	c1*c3*s2+s1*s3	,	c1*c2 , 0,
				0				,	0				,	0	,   1);

	xform = xform.multRight(R);
	// Print rotation matrix
	//cout << R[0][0] << "\t" << R[0][1] << "\t" << R[0][2] << "\n";
	//cout << R[1][0] << "\t" << R[1][1] << "\t" << R[1][2] << "\n";
	//cout << R[2][0] << "\t" << R[2][1] << "\t" << R[2][2] << "\n" <<"\n";

	// Matrix-vector multiply R.p
	//for (int i = 0; i<4; i++){
	//	temp[i]=0;
	//	for (int j=0; j<4; j++){
	//		temp[i] += R[i][j]*pos[3][j];
	//	}
	//}

	//// Set output
	//for (int i = 0; i<3; i++){
	//	pos[3][i] = temp[i];
	//}
}



void convertToInverseITP(hduVector3Dd &f) {

	// Not using ITP coordinates.  Return
	//if (!useITP) {
	//	return;
	//}

	// Using ITP coordinates.  Apply orthogonal rotation.
	hduVector3Dd temp;

	double R[3][3] = 
	{{	-1	,	0	,	0 },
	 {	0	,	0	,	1 },
	 {	0	,	1	,	0 }};

	// Matrix-vector multiply R.p
	for (int i = 0; i<3; i++){
		temp[i]=0;
		for (int j=0; j<3; j++){
			temp[i] += R[i][j]*f[j];
		}
	}

	// Set output
	for (int i = 0; i<3; i++){
		f[i] = temp[i];
	}

}
// applyTransforms() - 
//
//   Convert pos from Omni frame to teleoperation frame.
//   This may require applying a transform to comply with the ITP protocol
//   This may require applying a transform to rectify the camera view with the user's frame
//
void applyTransforms(hduMatrix &xform , int devID)
{
	omni2ITPTransform(xform, devID);
	applyCameraAngle(xform);
}

void applyInverseTransforms(hduVector3Dd &f)
{
	convertToInverseITP(f);
	
}