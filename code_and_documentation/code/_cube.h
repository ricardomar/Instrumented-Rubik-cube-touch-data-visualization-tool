
#include <stdlib.h>


#ifndef __INC_CUBEPRIM_H
#define __INC_CUBEPRIM_H


/** Structures **/

struct COLOR
{
	float RGB[3];
 
} typedef COLOR;


struct CUBELET
{
  COLOR face[6];
} typedef CUBELET;


struct CUBE
{
  CUBELET cubelet[3][3][3];
  double Rot[3];
} typedef CUBE;


/** Functions **/

void Reset( CUBE *cube );

#define r_yx r_xy
#define r_zx r_xz
#define r_zy r_yz
#define r_yx_inv r_xy_inv
#define r_zx_inv r_xz_inv
#define r_zy_inv r_yz_inv

#endif //__INC_CUBEPRIM_H

/* END OF _cube.h */
