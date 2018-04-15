

#include "_cube.h"
#include <stdlib.h>



void Reset( CUBE *cube )
{
  cube->cubelet[0][0][0].face[0].RGB[0]=1;
  cube->cubelet[0][0][0].face[0].RGB[1]=1;  
  cube->cubelet[0][0][0].face[0].RGB[2]=1;  
  //
  cube->cubelet[0][0][0].face[1].RGB[0]=0.2;
  cube->cubelet[0][0][0].face[1].RGB[1]=0.2;  
  cube->cubelet[0][0][0].face[1].RGB[2]=0.2;  
  //
  cube->cubelet[0][0][0].face[2].RGB[0]=0.2;
  cube->cubelet[0][0][0].face[2].RGB[1]=0.2;  
  cube->cubelet[0][0][0].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][0][0].face[3].RGB[0]=0;
  cube->cubelet[0][0][0].face[3].RGB[1]=1;  
  cube->cubelet[0][0][0].face[3].RGB[2]=0;
  //
  cube->cubelet[0][0][0].face[4].RGB[0]=1;
  cube->cubelet[0][0][0].face[4].RGB[1]=0.5;  
  cube->cubelet[0][0][0].face[4].RGB[2]=0;
  //
  cube->cubelet[0][0][0].face[5].RGB[0]=0.2;
  cube->cubelet[0][0][0].face[5].RGB[1]=0.2;  
  cube->cubelet[0][0][0].face[5].RGB[2]=0.2;



  cube->cubelet[1][0][0].face[0].RGB[0]=1;
  cube->cubelet[1][0][0].face[0].RGB[1]=1;  
  cube->cubelet[1][0][0].face[0].RGB[2]=1;
  //
  cube->cubelet[1][0][0].face[1].RGB[0]=0.2;
  cube->cubelet[1][0][0].face[1].RGB[1]=0.2;  
  cube->cubelet[1][0][0].face[1].RGB[2]=0.2;
  //
  cube->cubelet[1][0][0].face[2].RGB[0]=0.2;
  cube->cubelet[1][0][0].face[2].RGB[1]=0.2;  
  cube->cubelet[1][0][0].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][0][0].face[3].RGB[0]=0;
  cube->cubelet[1][0][0].face[3].RGB[1]=1;  
  cube->cubelet[1][0][0].face[3].RGB[2]=0;

  cube->cubelet[1][0][0].face[4].RGB[0]=0.2;
  cube->cubelet[1][0][0].face[4].RGB[1]=0.2;  
  cube->cubelet[1][0][0].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][0][0].face[5].RGB[0]=0.2;
  cube->cubelet[1][0][0].face[5].RGB[1]=0.2;  
  cube->cubelet[1][0][0].face[5].RGB[2]=0.2;


	
  cube->cubelet[2][0][0].face[0].RGB[0]=1;
  cube->cubelet[2][0][0].face[0].RGB[1]=1;  
  cube->cubelet[2][0][0].face[0].RGB[2]=1;
  //
  cube->cubelet[2][0][0].face[1].RGB[0]=0.2;
  cube->cubelet[2][0][0].face[1].RGB[1]=0.2;  
  cube->cubelet[2][0][0].face[1].RGB[2]=0.2;
  //
  cube->cubelet[2][0][0].face[2].RGB[0]=1;
  cube->cubelet[2][0][0].face[2].RGB[1]=0;  
  cube->cubelet[2][0][0].face[2].RGB[2]=0;
  //
  cube->cubelet[2][0][0].face[3].RGB[0]=0;
  cube->cubelet[2][0][0].face[3].RGB[1]=1;  
  cube->cubelet[2][0][0].face[3].RGB[2]=0;
  //
  cube->cubelet[2][0][0].face[4].RGB[0]=0.2;
  cube->cubelet[2][0][0].face[4].RGB[1]=0.2;  
  cube->cubelet[2][0][0].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][0][0].face[5].RGB[0]=0.2;
  cube->cubelet[2][0][0].face[5].RGB[1]=0.2;  
  cube->cubelet[2][0][0].face[5].RGB[2]=0.2;
	
	
	
  cube->cubelet[0][1][0].face[0].RGB[0]=1;
  cube->cubelet[0][1][0].face[0].RGB[1]=1;  
  cube->cubelet[0][1][0].face[0].RGB[2]=1;
  //
  cube->cubelet[0][1][0].face[1].RGB[0]=0.2;
  cube->cubelet[0][1][0].face[1].RGB[1]=0.2;  
  cube->cubelet[0][1][0].face[1].RGB[2]=0.2;
  //
  cube->cubelet[0][1][0].face[2].RGB[0]=0.2;
  cube->cubelet[0][1][0].face[2].RGB[1]=0.2;  
  cube->cubelet[0][1][0].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][1][0].face[3].RGB[0]=0.2;
  cube->cubelet[0][1][0].face[3].RGB[1]=0.2;  
  cube->cubelet[0][1][0].face[3].RGB[2]=0.2;
  //
  cube->cubelet[0][1][0].face[4].RGB[0]=1;
  cube->cubelet[0][1][0].face[4].RGB[1]=0.5;  
  cube->cubelet[0][1][0].face[4].RGB[2]=0;
  //
  cube->cubelet[0][1][0].face[5].RGB[0]=0.2;
  cube->cubelet[0][1][0].face[5].RGB[1]=0.2;  
  cube->cubelet[0][1][0].face[5].RGB[2]=0.2;



  cube->cubelet[1][1][0].face[0].RGB[0]=1;
  cube->cubelet[1][1][0].face[0].RGB[1]=1;  
  cube->cubelet[1][1][0].face[0].RGB[2]=1;
  //
  cube->cubelet[1][1][0].face[1].RGB[0]=0.2;
  cube->cubelet[1][1][0].face[1].RGB[1]=0.2;  
  cube->cubelet[1][1][0].face[1].RGB[2]=0.2;
  //
  cube->cubelet[1][1][0].face[2].RGB[0]=0.2;
  cube->cubelet[1][1][0].face[2].RGB[1]=0.2;  
  cube->cubelet[1][1][0].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][1][0].face[3].RGB[0]=0.2;
  cube->cubelet[1][1][0].face[3].RGB[1]=0.2;  
  cube->cubelet[1][1][0].face[3].RGB[2]=0.2;
  //
  cube->cubelet[1][1][0].face[4].RGB[0]=0.2;
  cube->cubelet[1][1][0].face[4].RGB[1]=0.2;  
  cube->cubelet[1][1][0].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][1][0].face[5].RGB[0]=0.2;
  cube->cubelet[1][1][0].face[5].RGB[1]=0.2;  
  cube->cubelet[1][1][0].face[5].RGB[2]=0.2;;
	
	
	
  cube->cubelet[2][1][0].face[0].RGB[0]=1;
  cube->cubelet[2][1][0].face[0].RGB[1]=1;  
  cube->cubelet[2][1][0].face[0].RGB[2]=1;
  //
  cube->cubelet[2][1][0].face[1].RGB[0]=0.2;
  cube->cubelet[2][1][0].face[1].RGB[1]=0.2;  
  cube->cubelet[2][1][0].face[1].RGB[2]=0.2;
  //
  cube->cubelet[2][1][0].face[2].RGB[0]=1;
  cube->cubelet[2][1][0].face[2].RGB[1]=0;  
  cube->cubelet[2][1][0].face[2].RGB[2]=0;
  //
  cube->cubelet[2][1][0].face[3].RGB[0]=0.2;
  cube->cubelet[2][1][0].face[3].RGB[1]=0.2;  
  cube->cubelet[2][1][0].face[3].RGB[2]=0.2;
  //
  cube->cubelet[2][1][0].face[4].RGB[0]=0.2;
  cube->cubelet[2][1][0].face[4].RGB[1]=0.2;  
  cube->cubelet[2][1][0].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][1][0].face[5].RGB[0]=0.2;
  cube->cubelet[2][1][0].face[5].RGB[1]=0.2;  
  cube->cubelet[2][1][0].face[5].RGB[2]=0.2;
	
	
	
	
  cube->cubelet[0][2][0].face[0].RGB[0]=1;
  cube->cubelet[0][2][0].face[0].RGB[1]=1;  
  cube->cubelet[0][2][0].face[0].RGB[2]=1;
  //
  cube->cubelet[0][2][0].face[1].RGB[0]=0;
  cube->cubelet[0][2][0].face[1].RGB[1]=0;  
  cube->cubelet[0][2][0].face[1].RGB[2]=1;
  //
  cube->cubelet[0][2][0].face[2].RGB[0]=0.2;
  cube->cubelet[0][2][0].face[2].RGB[1]=0.2;  
  cube->cubelet[0][2][0].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][2][0].face[3].RGB[0]=0.2;
  cube->cubelet[0][2][0].face[3].RGB[1]=0.2;  
  cube->cubelet[0][2][0].face[3].RGB[2]=0.2;
  //
  cube->cubelet[0][2][0].face[4].RGB[0]=1;
  cube->cubelet[0][2][0].face[4].RGB[1]=0.5;  
  cube->cubelet[0][2][0].face[4].RGB[2]=0;
  //
  cube->cubelet[0][2][0].face[5].RGB[0]=0.2;
  cube->cubelet[0][2][0].face[5].RGB[1]=0.2;  
  cube->cubelet[0][2][0].face[5].RGB[2]=0.2;



  cube->cubelet[1][2][0].face[0].RGB[0]=1;
  cube->cubelet[1][2][0].face[0].RGB[1]=1;  
  cube->cubelet[1][2][0].face[0].RGB[2]=1;
  //
  cube->cubelet[1][2][0].face[1].RGB[0]=0;
  cube->cubelet[1][2][0].face[1].RGB[1]=0;  
  cube->cubelet[1][2][0].face[1].RGB[2]=1;
  //
  cube->cubelet[1][2][0].face[2].RGB[0]=0.2;
  cube->cubelet[1][2][0].face[2].RGB[1]=0.2;  
  cube->cubelet[1][2][0].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][2][0].face[3].RGB[0]=0.2;
  cube->cubelet[1][2][0].face[3].RGB[1]=0.2;  
  cube->cubelet[1][2][0].face[3].RGB[2]=0.2;
  //
  cube->cubelet[1][2][0].face[4].RGB[0]=0.2;
  cube->cubelet[1][2][0].face[4].RGB[1]=0.2;  
  cube->cubelet[1][2][0].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][2][0].face[5].RGB[0]=0.2;
  cube->cubelet[1][2][0].face[5].RGB[1]=0.2;  
  cube->cubelet[1][2][0].face[5].RGB[2]=0.2;



  cube->cubelet[2][2][0].face[0].RGB[0]=1;
  cube->cubelet[2][2][0].face[0].RGB[1]=1;  
  cube->cubelet[2][2][0].face[0].RGB[2]=1;
  //
  cube->cubelet[2][2][0].face[1].RGB[0]=0;
  cube->cubelet[2][2][0].face[1].RGB[1]=0;  
  cube->cubelet[2][2][0].face[1].RGB[2]=1;
  //
  cube->cubelet[2][2][0].face[2].RGB[0]=1;
  cube->cubelet[2][2][0].face[2].RGB[1]=0;  
  cube->cubelet[2][2][0].face[2].RGB[2]=0;
  //
  cube->cubelet[2][2][0].face[3].RGB[0]=0.2;
  cube->cubelet[2][2][0].face[3].RGB[1]=0.2;  
  cube->cubelet[2][2][0].face[3].RGB[2]=0.2;
  //
  cube->cubelet[2][2][0].face[4].RGB[0]=0.2;
  cube->cubelet[2][2][0].face[4].RGB[1]=0.2;  
  cube->cubelet[2][2][0].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][2][0].face[5].RGB[0]=0.2;
  cube->cubelet[2][2][0].face[5].RGB[1]=0.2;  
  cube->cubelet[2][2][0].face[5].RGB[2]=0.2;
  
  
	
  cube->cubelet[0][0][1].face[0].RGB[0]=0.2;
  cube->cubelet[0][0][1].face[0].RGB[1]=0.2;  
  cube->cubelet[0][0][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[0][0][1].face[1].RGB[0]=0.2;
  cube->cubelet[0][0][1].face[1].RGB[1]=0.2;  
  cube->cubelet[0][0][1].face[1].RGB[2]=0.2;
  //
  cube->cubelet[0][0][1].face[2].RGB[0]=0.2;
  cube->cubelet[0][0][1].face[2].RGB[1]=0.2;  
  cube->cubelet[0][0][1].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][0][1].face[3].RGB[0]=0;
  cube->cubelet[0][0][1].face[3].RGB[1]=1;  
  cube->cubelet[0][0][1].face[3].RGB[2]=0;
  //
  cube->cubelet[0][0][1].face[4].RGB[0]=1;
  cube->cubelet[0][0][1].face[4].RGB[1]=0.5;  
  cube->cubelet[0][0][1].face[4].RGB[2]=0;
  //
  cube->cubelet[0][0][1].face[5].RGB[0]=0.2;
  cube->cubelet[0][0][1].face[5].RGB[1]=0.2;  
  cube->cubelet[0][0][1].face[5].RGB[2]=0.2;
  
  
	
  cube->cubelet[1][0][1].face[0].RGB[0]=0.2;
  cube->cubelet[1][0][1].face[0].RGB[1]=0.2;  
  cube->cubelet[1][0][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[1][0][1].face[1].RGB[0]=0.2;
  cube->cubelet[1][0][1].face[1].RGB[1]=0.2;  
  cube->cubelet[1][0][1].face[1].RGB[2]=0.2;
  //
  cube->cubelet[1][0][1].face[2].RGB[0]=0.2;
  cube->cubelet[1][0][1].face[2].RGB[1]=0.2;  
  cube->cubelet[1][0][1].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][0][1].face[3].RGB[0]=0;
  cube->cubelet[1][0][1].face[3].RGB[1]=1;  
  cube->cubelet[1][0][1].face[3].RGB[2]=0;
  //
  cube->cubelet[1][0][1].face[4].RGB[0]=0.2;
  cube->cubelet[1][0][1].face[4].RGB[1]=0.2;  
  cube->cubelet[1][0][1].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][0][1].face[5].RGB[0]=0.2;
  cube->cubelet[1][0][1].face[5].RGB[1]=0.2;  
  cube->cubelet[1][0][1].face[5].RGB[2]=0.2;
  
  
	
  cube->cubelet[2][0][1].face[0].RGB[0]=0.2;
  cube->cubelet[2][0][1].face[0].RGB[1]=0.2;  
  cube->cubelet[2][0][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[2][0][1].face[1].RGB[0]=0.2;
  cube->cubelet[2][0][1].face[1].RGB[1]=0.2;  
  cube->cubelet[2][0][1].face[1].RGB[2]=0.2;
  //
  cube->cubelet[2][0][1].face[2].RGB[0]=1;
  cube->cubelet[2][0][1].face[2].RGB[1]=0;  
  cube->cubelet[2][0][1].face[2].RGB[2]=0;
  //
  cube->cubelet[2][0][1].face[3].RGB[0]=0;
  cube->cubelet[2][0][1].face[3].RGB[1]=1;  
  cube->cubelet[2][0][1].face[3].RGB[2]=0;
  //
  cube->cubelet[2][0][1].face[4].RGB[0]=0.2;
  cube->cubelet[2][0][1].face[4].RGB[1]=0.2;  
  cube->cubelet[2][0][1].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][0][1].face[5].RGB[0]=0.2;
  cube->cubelet[2][0][1].face[5].RGB[1]=0.2;  
  cube->cubelet[2][0][1].face[5].RGB[2]=0.2;
  
  
	
  cube->cubelet[0][1][1].face[0].RGB[0]=0.2;
  cube->cubelet[0][1][1].face[0].RGB[1]=0.2;  
  cube->cubelet[0][1][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[0][1][1].face[1].RGB[0]=0.2;
  cube->cubelet[0][1][1].face[1].RGB[1]=0.2;  
  cube->cubelet[0][1][1].face[1].RGB[2]=0.2;
  //
  cube->cubelet[0][1][1].face[2].RGB[0]=0.2;
  cube->cubelet[0][1][1].face[2].RGB[1]=0.2;  
  cube->cubelet[0][1][1].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][1][1].face[3].RGB[0]=0.2;
  cube->cubelet[0][1][1].face[3].RGB[1]=0.2;  
  cube->cubelet[0][1][1].face[3].RGB[2]=0.2;
  //
  cube->cubelet[0][1][1].face[4].RGB[0]=1;
  cube->cubelet[0][1][1].face[4].RGB[1]=0.5;  
  cube->cubelet[0][1][1].face[4].RGB[2]=0;
  //
  cube->cubelet[0][1][1].face[5].RGB[0]=0.2;
  cube->cubelet[0][1][1].face[5].RGB[1]=0.2;  
  cube->cubelet[0][1][1].face[5].RGB[2]=0.2;
 
 
	
  cube->cubelet[1][1][1].face[0].RGB[0]=0.2;
  cube->cubelet[1][1][1].face[0].RGB[1]=0.2;  
  cube->cubelet[1][1][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[1][1][1].face[1].RGB[0]=0.2;
  cube->cubelet[1][1][1].face[1].RGB[1]=0.2;  
  cube->cubelet[1][1][1].face[1].RGB[2]=0.2;
  //
  cube->cubelet[1][1][1].face[2].RGB[0]=0.2;
  cube->cubelet[1][1][1].face[2].RGB[1]=0.2;  
  cube->cubelet[1][1][1].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][1][1].face[3].RGB[0]=0.2;
  cube->cubelet[1][1][1].face[3].RGB[1]=0.2;  
  cube->cubelet[1][1][1].face[3].RGB[2]=0.2;
  //
  cube->cubelet[1][1][1].face[4].RGB[0]=0.2;
  cube->cubelet[1][1][1].face[4].RGB[1]=0.2;  
  cube->cubelet[1][1][1].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][1][1].face[5].RGB[0]=0.2;
  cube->cubelet[1][1][1].face[5].RGB[1]=0.2;  
  cube->cubelet[1][1][1].face[5].RGB[2]=0.2;
  
  
	
  cube->cubelet[2][1][1].face[0].RGB[0]=0.2;
  cube->cubelet[2][1][1].face[0].RGB[1]=0.2;  
  cube->cubelet[2][1][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[2][1][1].face[1].RGB[0]=0.2;
  cube->cubelet[2][1][1].face[1].RGB[1]=0.2;  
  cube->cubelet[2][1][1].face[1].RGB[2]=0.2;
  //
  cube->cubelet[2][1][1].face[2].RGB[0]=1;
  cube->cubelet[2][1][1].face[2].RGB[1]=0;  
  cube->cubelet[2][1][1].face[2].RGB[2]=0;
  //
  cube->cubelet[2][1][1].face[3].RGB[0]=0.2;
  cube->cubelet[2][1][1].face[3].RGB[1]=0.2;  
  cube->cubelet[2][1][1].face[3].RGB[2]=0.2;
  //
  cube->cubelet[2][1][1].face[4].RGB[0]=0.2;
  cube->cubelet[2][1][1].face[4].RGB[1]=0.2;  
  cube->cubelet[2][1][1].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][1][1].face[5].RGB[0]=0.2;
  cube->cubelet[2][1][1].face[5].RGB[1]=0.2;  
  cube->cubelet[2][1][1].face[5].RGB[2]=0.2;
 
 
	
  cube->cubelet[0][2][1].face[0].RGB[0]=0.2;
  cube->cubelet[0][2][1].face[0].RGB[1]=0.2;  
  cube->cubelet[0][2][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[0][2][1].face[1].RGB[0]=0;
  cube->cubelet[0][2][1].face[1].RGB[1]=0;  
  cube->cubelet[0][2][1].face[1].RGB[2]=1;
  //
  cube->cubelet[0][2][1].face[2].RGB[0]=0.2;
  cube->cubelet[0][2][1].face[2].RGB[1]=0.2;  
  cube->cubelet[0][2][1].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][2][1].face[3].RGB[0]=0.2;
  cube->cubelet[0][2][1].face[3].RGB[1]=0.2;  
  cube->cubelet[0][2][1].face[3].RGB[2]=0.2;
  //
  cube->cubelet[0][2][1].face[4].RGB[0]=1;
  cube->cubelet[0][2][1].face[4].RGB[1]=0.5;  
  cube->cubelet[0][2][1].face[4].RGB[2]=0;
  //
  cube->cubelet[0][2][1].face[5].RGB[0]=0.2;
  cube->cubelet[0][2][1].face[5].RGB[1]=0.2;  
  cube->cubelet[0][2][1].face[5].RGB[2]=0.2;
  
	
  
  cube->cubelet[1][2][1].face[0].RGB[0]=0.2;
  cube->cubelet[1][2][1].face[0].RGB[1]=0.2;  
  cube->cubelet[1][2][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[1][2][1].face[1].RGB[0]=0;
  cube->cubelet[1][2][1].face[1].RGB[1]=0;  
  cube->cubelet[1][2][1].face[1].RGB[2]=1;
  //
  cube->cubelet[1][2][1].face[2].RGB[0]=0.2;
  cube->cubelet[1][2][1].face[2].RGB[1]=0.2;  
  cube->cubelet[1][2][1].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][2][1].face[3].RGB[0]=0.2;
  cube->cubelet[1][2][1].face[3].RGB[1]=0.2;  
  cube->cubelet[1][2][1].face[3].RGB[2]=0.2;
  //
  cube->cubelet[1][2][1].face[4].RGB[0]=0.2;
  cube->cubelet[1][2][1].face[4].RGB[1]=0.2;  
  cube->cubelet[1][2][1].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][2][1].face[5].RGB[0]=0.2;
  cube->cubelet[1][2][1].face[5].RGB[1]=0.2;  
  cube->cubelet[1][2][1].face[5].RGB[2]=0.2;
  //
	
	
	
  cube->cubelet[2][2][1].face[0].RGB[0]=0.2;
  cube->cubelet[2][2][1].face[0].RGB[1]=0.2;  
  cube->cubelet[2][2][1].face[0].RGB[2]=0.2;
  //
  cube->cubelet[2][2][1].face[1].RGB[0]=0;
  cube->cubelet[2][2][1].face[1].RGB[1]=0;  
  cube->cubelet[2][2][1].face[1].RGB[2]=1;
  //
  cube->cubelet[2][2][1].face[2].RGB[0]=1;
  cube->cubelet[2][2][1].face[2].RGB[1]=0;  
  cube->cubelet[2][2][1].face[2].RGB[2]=0;
  //
  cube->cubelet[2][2][1].face[3].RGB[0]=0.2;
  cube->cubelet[2][2][1].face[3].RGB[1]=0.2;  
  cube->cubelet[2][2][1].face[3].RGB[2]=0.2;
  //
  cube->cubelet[2][2][1].face[4].RGB[0]=0.2;
  cube->cubelet[2][2][1].face[4].RGB[1]=0.2;  
  cube->cubelet[2][2][1].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][2][1].face[5].RGB[0]=0.2;
  cube->cubelet[2][2][1].face[5].RGB[1]=0.2;  
  cube->cubelet[2][2][1].face[5].RGB[2]=0.2;
  
  
	
  cube->cubelet[0][0][2].face[0].RGB[0]=0.2;
  cube->cubelet[0][0][2].face[0].RGB[1]=0.2;  
  cube->cubelet[0][0][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[0][0][2].face[1].RGB[0]=0.2;
  cube->cubelet[0][0][2].face[1].RGB[1]=0.2;  
  cube->cubelet[0][0][2].face[1].RGB[2]=0.2;
  //
  cube->cubelet[0][0][2].face[2].RGB[0]=0.2;
  cube->cubelet[0][0][2].face[2].RGB[1]=0.2;  
  cube->cubelet[0][0][2].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][0][2].face[3].RGB[0]=0;
  cube->cubelet[0][0][2].face[3].RGB[1]=1;  
  cube->cubelet[0][0][2].face[3].RGB[2]=0;
  //
  cube->cubelet[0][0][2].face[4].RGB[0]=1;
  cube->cubelet[0][0][2].face[4].RGB[1]=0.5;  
  cube->cubelet[0][0][2].face[4].RGB[2]=0;
  //
  cube->cubelet[0][0][2].face[5].RGB[0]=1;
  cube->cubelet[0][0][2].face[5].RGB[1]=1;  
  cube->cubelet[0][0][2].face[5].RGB[2]=0;
  
  
	
  cube->cubelet[1][0][2].face[0].RGB[0]=0.2;
  cube->cubelet[1][0][2].face[0].RGB[1]=0.2;  
  cube->cubelet[1][0][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[1][0][2].face[1].RGB[0]=0.2;
  cube->cubelet[1][0][2].face[1].RGB[1]=0.2;  
  cube->cubelet[1][0][2].face[1].RGB[2]=0.2;
  //
  cube->cubelet[1][0][2].face[2].RGB[0]=0.2;
  cube->cubelet[1][0][2].face[2].RGB[1]=0.2;  
  cube->cubelet[1][0][2].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][0][2].face[3].RGB[0]=0;
  cube->cubelet[1][0][2].face[3].RGB[1]=1;  
  cube->cubelet[1][0][2].face[3].RGB[2]=0;
  //
  cube->cubelet[1][0][2].face[4].RGB[0]=0.2;
  cube->cubelet[1][0][2].face[4].RGB[1]=0.2;  
  cube->cubelet[1][0][2].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][0][2].face[5].RGB[0]=1;
  cube->cubelet[1][0][2].face[5].RGB[1]=1;  
  cube->cubelet[1][0][2].face[5].RGB[2]=0;
  
  
	
  cube->cubelet[2][0][2].face[0].RGB[0]=0.2;
  cube->cubelet[2][0][2].face[0].RGB[1]=0.2;  
  cube->cubelet[2][0][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[2][0][2].face[1].RGB[0]=0.2;
  cube->cubelet[2][0][2].face[1].RGB[1]=0.2;  
  cube->cubelet[2][0][2].face[1].RGB[2]=0.2;
  //
  cube->cubelet[2][0][2].face[2].RGB[0]=1;
  cube->cubelet[2][0][2].face[2].RGB[1]=0;  
  cube->cubelet[2][0][2].face[2].RGB[2]=0;
  //
  cube->cubelet[2][0][2].face[3].RGB[0]=0;
  cube->cubelet[2][0][2].face[3].RGB[1]=1;  
  cube->cubelet[2][0][2].face[3].RGB[2]=0;
  //
  cube->cubelet[2][0][2].face[4].RGB[0]=0.2;
  cube->cubelet[2][0][2].face[4].RGB[1]=0.2;  
  cube->cubelet[2][0][2].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][0][2].face[5].RGB[0]=1;
  cube->cubelet[2][0][2].face[5].RGB[1]=1;  
  cube->cubelet[2][0][2].face[5].RGB[2]=0;
  
  
	
  cube->cubelet[0][1][2].face[0].RGB[0]=0.2;
  cube->cubelet[0][1][2].face[0].RGB[1]=0.2;  
  cube->cubelet[0][1][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[0][1][2].face[1].RGB[0]=0.2;
  cube->cubelet[0][1][2].face[1].RGB[1]=0.2;  
  cube->cubelet[0][1][2].face[1].RGB[2]=0.2;
  //
  cube->cubelet[0][1][2].face[2].RGB[0]=0.2;
  cube->cubelet[0][1][2].face[2].RGB[1]=0.2;  
  cube->cubelet[0][1][2].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][1][2].face[3].RGB[0]=0.2;
  cube->cubelet[0][1][2].face[3].RGB[1]=0.2;  
  cube->cubelet[0][1][2].face[3].RGB[2]=0.2;
  //
  cube->cubelet[0][1][2].face[4].RGB[0]=1;
  cube->cubelet[0][1][2].face[4].RGB[1]=0.5;  
  cube->cubelet[0][1][2].face[4].RGB[2]=0;
  //
  cube->cubelet[0][1][2].face[5].RGB[0]=1;
  cube->cubelet[0][1][2].face[5].RGB[1]=1;  
  cube->cubelet[0][1][2].face[5].RGB[2]=0;
 
	
  cube->cubelet[1][1][2].face[0].RGB[0]=0.2;
  cube->cubelet[1][1][2].face[0].RGB[1]=0.2;  
  cube->cubelet[1][1][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[1][1][2].face[1].RGB[0]=0.2;
  cube->cubelet[1][1][2].face[1].RGB[1]=0.2;  
  cube->cubelet[1][1][2].face[1].RGB[2]=0.2;
  //
  cube->cubelet[1][1][2].face[2].RGB[0]=0.2;
  cube->cubelet[1][1][2].face[2].RGB[1]=0.2;  
  cube->cubelet[1][1][2].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][1][2].face[3].RGB[0]=0.2;
  cube->cubelet[1][1][2].face[3].RGB[1]=0.2;  
  cube->cubelet[1][1][2].face[3].RGB[2]=0.2;
  //
  cube->cubelet[1][1][2].face[4].RGB[0]=0.2;
  cube->cubelet[1][1][2].face[4].RGB[1]=0.2;  
  cube->cubelet[1][1][2].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][1][2].face[5].RGB[0]=1;
  cube->cubelet[1][1][2].face[5].RGB[1]=1;  
  cube->cubelet[1][1][2].face[5].RGB[2]=0;
  
  
	
  cube->cubelet[2][1][2].face[0].RGB[0]=0.2;
  cube->cubelet[2][1][2].face[0].RGB[1]=0.2;  
  cube->cubelet[2][1][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[2][1][2].face[1].RGB[0]=0.2;
  cube->cubelet[2][1][2].face[1].RGB[1]=0.2;  
  cube->cubelet[2][1][2].face[1].RGB[2]=0.2;
  //
  cube->cubelet[2][1][2].face[2].RGB[0]=1;
  cube->cubelet[2][1][2].face[2].RGB[1]=0;  
  cube->cubelet[2][1][2].face[2].RGB[2]=0;
  //
  cube->cubelet[2][1][2].face[3].RGB[0]=0.2;
  cube->cubelet[2][1][2].face[3].RGB[1]=0.2;  
  cube->cubelet[2][1][2].face[3].RGB[2]=0.2;
  //
  cube->cubelet[2][1][2].face[4].RGB[0]=0.2;
  cube->cubelet[2][1][2].face[4].RGB[1]=0.2;  
  cube->cubelet[2][1][2].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][1][2].face[5].RGB[0]=1;
  cube->cubelet[2][1][2].face[5].RGB[1]=1;  
  cube->cubelet[2][1][2].face[5].RGB[2]=0;

	
  cube->cubelet[0][2][2].face[0].RGB[0]=0.2;
  cube->cubelet[0][2][2].face[0].RGB[1]=0.2;  
  cube->cubelet[0][2][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[0][2][2].face[1].RGB[0]=0;
  cube->cubelet[0][2][2].face[1].RGB[1]=0;  
  cube->cubelet[0][2][2].face[1].RGB[2]=1;
  //
  cube->cubelet[0][2][2].face[2].RGB[0]=0.2;
  cube->cubelet[0][2][2].face[2].RGB[1]=0.2;  
  cube->cubelet[0][2][2].face[2].RGB[2]=0.2;
  //
  cube->cubelet[0][2][2].face[3].RGB[0]=0.2;
  cube->cubelet[0][2][2].face[3].RGB[1]=0.2;  
  cube->cubelet[0][2][2].face[3].RGB[2]=0.2;
  //
  cube->cubelet[0][2][2].face[4].RGB[0]=1;
  cube->cubelet[0][2][2].face[4].RGB[1]=0.5;  
  cube->cubelet[0][2][2].face[4].RGB[2]=0;
  //
  cube->cubelet[0][2][2].face[5].RGB[0]=1;
  cube->cubelet[0][2][2].face[5].RGB[1]=1;  
  cube->cubelet[0][2][2].face[5].RGB[2]=0;

	
	
	
  cube->cubelet[1][2][2].face[0].RGB[0]=0.2;
  cube->cubelet[1][2][2].face[0].RGB[1]=0.2;  
  cube->cubelet[1][2][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[1][2][2].face[1].RGB[0]=0;
  cube->cubelet[1][2][2].face[1].RGB[1]=0;  
  cube->cubelet[1][2][2].face[1].RGB[2]=1;
  //
  cube->cubelet[1][2][2].face[2].RGB[0]=0.2;
  cube->cubelet[1][2][2].face[2].RGB[1]=0.2;  
  cube->cubelet[1][2][2].face[2].RGB[2]=0.2;
  //
  cube->cubelet[1][2][2].face[3].RGB[0]=0.2;
  cube->cubelet[1][2][2].face[3].RGB[1]=0.2;  
  cube->cubelet[1][2][2].face[3].RGB[2]=0.2;
  //
  cube->cubelet[1][2][2].face[4].RGB[0]=0.2;
  cube->cubelet[1][2][2].face[4].RGB[1]=0.2;  
  cube->cubelet[1][2][2].face[4].RGB[2]=0.2;
  //
  cube->cubelet[1][2][2].face[5].RGB[0]=1;
  cube->cubelet[1][2][2].face[5].RGB[1]=1;  
  cube->cubelet[1][2][2].face[5].RGB[2]=0;
	
	
	
  cube->cubelet[2][2][2].face[0].RGB[0]=0.2;
  cube->cubelet[2][2][2].face[0].RGB[1]=0.2;  
  cube->cubelet[2][2][2].face[0].RGB[2]=0.2;
  //
  cube->cubelet[2][2][2].face[1].RGB[0]=0;
  cube->cubelet[2][2][2].face[1].RGB[1]=0;  
  cube->cubelet[2][2][2].face[1].RGB[2]=1;
  //
  cube->cubelet[2][2][2].face[2].RGB[0]=1;
  cube->cubelet[2][2][2].face[2].RGB[1]=0;  
  cube->cubelet[2][2][2].face[2].RGB[2]=0;
  //
  cube->cubelet[2][2][2].face[3].RGB[0]=0.2;
  cube->cubelet[2][2][2].face[3].RGB[1]=0.2;  
  cube->cubelet[2][2][2].face[3].RGB[2]=0.2;
  //
  cube->cubelet[2][2][2].face[4].RGB[0]=0.2;
  cube->cubelet[2][2][2].face[4].RGB[1]=0.2;  
  cube->cubelet[2][2][2].face[4].RGB[2]=0.2;
  //
  cube->cubelet[2][2][2].face[5].RGB[0]=1;
  cube->cubelet[2][2][2].face[5].RGB[1]=1;  
  cube->cubelet[2][2][2].face[5].RGB[2]=0;

}






/* END OF _cube.c */
