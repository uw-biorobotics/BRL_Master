/*

File: cameraAngle.h
Author: Hawkeye King
Written June-2008

This file implements rotation from the Omni frame to the camera view angle.

*/
void applyTransforms(hduMatrix &xform, int devID);
void omni2ITPTransform(hduMatrix &xform , int devID);

void applyInverseTransforms(hduVector3Dd &f);