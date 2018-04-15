
//vizualização
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "_cube.h"
#include "display.h"
#include <GL/glut.h>

//thread
#include <iostream>
#include <pthread.h>
#include <assert.h>
#include <semaphore.h>

#include <unistd.h>

//comunicação Cubo de Rubik
#include <errno.h>
#include <error.h>
#include <libpcan.h>
#include <stdio.h>
#include <fcntl.h>
#include <ncurses.h>
#include <pcan.h>
#include <iostream>
#include <fstream>

using namespace std;

#define FACE_DATA_SIZE 12

HANDLE h;
const char* port="/dev/pcan32";
int messages_seen[0x800];

struct face
{
	int data[12];
	unsigned int base;
	const char* name;	
};

face object[6]={
	{{},0x7f4,"green"},
	{{},0x7a0,"white"},
	{{},0x7df,"orange"},
	{{},0x7b5,"blue"},
	{{},0x7ca,"red"},
	{{},0x78b,"yellow"}		
};

void print_object(void)
{

	int i,j;
	for(i=0;i<6;i++)
	{
		mvprintw(i+1,0,"%d: %s",i,object[i].name);
		
		/*the force sensors */
		mvprintw(i+1,12,"");
		for(j=0;j<9;j++)
		{
			printw(" %04d", object[i].data[j]);
		};
		printw(":");
		
		/*the acceleration sensors*/
		for(j=0;j<3;j++)
		{
			printw("%04d ",object[i].data[j+9]);
		};
		clrtoeol();
	};
	clrtoeol();
}


void write_object(FILE* file)
{
	int i,j;
	for(i=0;i<6;i++)
	{
		fprintf(file,"%d: %8s ",i,object[i].name);
		
		for(j=0;j<9;j++)
		{
			fprintf(file," %04d", object[i].data[j]);
		};
		fprintf(file,":");
		
		/*the acceleration sensors*/
		for(j=0;j<3;j++)
		{
			fprintf(file,"%04d ",object[i].data[j+9]);
		};
		fprintf(file,"\n");
	};	
}

void process_message(TPCANMsg *m)
{
	int i,j;
	mvprintw(9,1,"ID=%x", m->ID); clrtoeol();
	messages_seen[m->ID]++;
	for (i=0; i<6; i++) 
	{
		/* Search the faces until we find the one that matches this message */
		if ((object[i].base <= m->ID) && ((object[i].base+FACE_DATA_SIZE)>m->ID)) 
		{
			/* The message contains LEN/2 16-bit data items. Unpack them and store them */
			for (j=0;j<m->LEN/2;j++) 
			{
    			unsigned int v;
    			/* Convert the two bytes into an integer */
        		v = m->DATA[j*2];
        		v |= m->DATA[(j*2)+1]<<8;
        		object[i].data[ m->ID - object[i].base + j] =v;
			};
		};
	};
}

int list_messages(void) 
{
	int i;
	int count=0;
	for (i=0;i<0x800;i++) 
	{
   		if (messages_seen[i]) 
   		{
     		count++;
     		printf("%04x: %12d ", i, messages_seen[i]);
     		if ((count%8)==0)
           	printf("\n");
   		};
  	};
	return 0;
}


void *Thread01(void* threadarg)
{
	CUBE* cube=((CUBE*)(threadarg));
	
	rundisplay(cube,NULL,NULL);
	
	return 0;
}


int main( int argc, char *argv[])
{	
	pthread_t threads;
	pthread_attr_t attr;
	
	//thread creation
	pthread_attr_init(&attr);
	CUBE cube;
	Reset(&cube);
	
	pthread_create (&threads,&attr,Thread01, &cube);
	
	
	//leitura de dados
	__u32 status;
	
	FILE* teste123;
	teste123=fopen("trial01.txt","a+");
	
	/* Open the CAN poer. */
	h = LINUX_CAN_Open(port, O_RDWR);
	if (!h) error(1,errno, "can't open %s", port);
	
	/* clear status */
	CAN_Status(h);
	
	/* Set it up for 1MBit */
	errno = CAN_Init(h, 0x14, 0);
	if (errno) error(1,errno, "CAN_Init");
	
	
	
	//atexit(list_messages);
	
	initscr();
 	cbreak();
 	noecho();
 	nodelay(stdscr, 1);
  	clear();
	
//	OLD node IDs
//  int msg1Data[6]={0xff,0x02,0x03,0x04,0x05,0x06};
//	int msg2Data[6]={0x00,0x20,0x40,0x60,0x80,0xa0};
//	int msg3Data[6]={0x0c,0x2c,0x4c,0x6c,0x8c,0xac};
//	int msg4Data[6]={0xff,0x02,0x03,0x04,0x05,0x06};
//	

// 	for (int i=0;i<=5;i++)
// 	{	
// 		usleep(500);
//  		TPCANMsg msg1={(__u32)0x014,(__u8)MSGTYPE_STATUS,(__u8) 8,{(__u8)0x10,(__u8)0x02,(__u8)msg1Data[i],(__u8)0xC2,(__u8)0x00,(__u8)0x00,(__u8)0x00,(__u8)0x00}};
//		errno=CAN_Write(h,&msg1);  	
//  		if (errno) error(0,errno, "on CAN_Write, continuing...");
//		usleep(500);
//
//  		TPCANMsg msg2={(__u32)0x016,(__u8)MSGTYPE_STATUS,(__u8) 4,{(__u8)0x01,(__u8)0x00,(__u8)msg2Data[i],(__u8)0x05}};
//		errno=CAN_Write(h,&msg2);  	
//  		if (errno) error(0,errno, "on CAN_Write, continuing...");
//		usleep(500);
// 	
//  		TPCANMsg msg3={(__u32)0x016,(__u8)MSGTYPE_STATUS,(__u8) 4,{(__u8)0x02,(__u8)0x00,(__u8)msg3Data[i],(__u8)0x05}};
//		errno=CAN_Write(h,&msg3);  	
//  		if (errno) error(0,errno, "on CAN_Write, continuing...");
// 		usleep(500);
// 	
//  		TPCANMsg msg4={(__u32) 0x013,(__u8)MSGTYPE_STATUS,(__u8) 8,{(__u8)0x10,(__u8)0x02,(__u8)msg4Data[i],(__u8)0xC2,(__u8)0x00,(__u8)0x00,(__u8)0x00,(__u8)0x00}};
//		errno=CAN_Write(h,&msg4);  	
//  		if (errno) error(0,errno, "on CAN_Write, continuing...");
//  		
// 	};
// 	
 	

// NEW NODE IDS
//
//	int msg1Data[6][8]={{0x10,0x02,0xff,0xc2,0x00,0x00,0x00,0x00},{0x10,0x02,0x02,0xc2,0x00,0x00,0x00,0x00},{0x10,0x02,0x03,0xc2,0x00,0x00,0x00,0x00},{0x10,0x02,0x04,0xc2,0x00,0x00,0x00,0x00},{0x10,0x02,0x05,0xc2,0x03,0x00,0x01,0x08},{0x10,0x02,0x06,0xff,0x22,0x56,0xc9,0x24}};
//	int msg2Data[6][8]={{0x01,0x00,0x00,0x05,0x00,0x00,0x00,0x00},{0x01,0x00,0x20,0x05,0x00,0x00,0x00,0x00},{0x01,0x00,0x40,0x05,0x00,0x00,0x00,0x00},{0x01,0x00,0x60,0x05,0x00,0x00,0x00,0x00},{0x01,0x00,0x80,0x05,0x00,0x00,0x00,0x00},{0x01,0x00,0xa0,0x05,0x00,0x00,0x00,0x00}};
//	int msg3Data[6][8]={{0x02,0x00,0x0C,0x05,0x00,0x00,0x00,0x00},{0x02,0x00,0x2C,0x05,0x00,0x00,0x00,0x00},{0x02,0x00,0x4C,0x05,0x00,0x00,0x00,0x00},{0x02,0x00,0x6C,0x05,0x00,0x00,0x00,0x00},{0x02,0x00,0x8C,0x05,0x00,0x00,0x00,0x00},{0x02,0x00,0xaC,0x05,0x00,0x00,0x00,0x00}};
//	int msg4Data[6][8]={{0x10,0x02,0xff,0xc2,0x00,0x00,0x00,0x00},{0x10,0x02,0x02,0xc2,0x00,0x00,0x00,0x00},{0x10,0x02,0x03,0xc2,0x00,0x00,0x00,0x00},{0x10,0x02,0x04,0xc2,0x00,0x00,0x00,0x00},{0x10,0x02,0x05,0xc2,0x03,0x00,0x01,0x08},{0x10,0x02,0x06,0xff,0x22,0x56,0xc9,0x24}};
//	
//	for (int k =0; k<=3;k++)
//	{	
// 		for (int i=0;i<=5;i++)
// 		{	
// 			usleep(20000);
//  			TPCANMsg msg1={(__u32)0x014,(__u8)MSGTYPE_STATUS,(__u8) 8,{(__u8)msg1Data[i][0],(__u8)msg1Data[i][1],(__u8)msg1Data[i][2],(__u8)msg1Data[i][3],(__u8)msg1Data[i][4],(__u8)msg1Data[i][5],(__u8)msg1Data[i][6],(__u8)msg1Data[i][7]}};
//			errno=CAN_Write(h,&msg1);  	
//  			if (errno) error(0,errno, "on CAN_Write, continuing...");
//			usleep(20000);
//
//  			TPCANMsg msg2={(__u32)0x016,(__u8)MSGTYPE_STATUS,(__u8) 4,{(__u8)msg2Data[i][0],(__u8)msg2Data[i][1],(__u8)msg2Data[i][2],(__u8)msg2Data[i][3]}};
//			errno=CAN_Write(h,&msg2);  	
//  			if (errno) error(0,errno, "on CAN_Write, continuing...");
//			usleep(20000);
// 	
//  			TPCANMsg msg3={(__u32)0x016,(__u8)MSGTYPE_STATUS,(__u8) 4,{(__u8)msg3Data[i][0],(__u8)msg3Data[i][1],(__u8)msg3Data[i][2],(__u8)msg3Data[i][3]}};
//			errno=CAN_Write(h,&msg3);  	
//  			if (errno) error(0,errno, "on CAN_Write, continuing...");
// 			usleep(20000);
// 	
//  			TPCANMsg msg4={(__u32)0x013,(__u8)MSGTYPE_STATUS,(__u8) 8,{(__u8)msg4Data[i][0],(__u8)msg4Data[i][1],(__u8)msg4Data[i][2],(__u8)msg4Data[i][3],(__u8)msg4Data[i][4],(__u8)msg4Data[i][5],(__u8)msg4Data[i][6],(__u8)msg4Data[i][7]}};
//			errno=CAN_Write(h,&msg4);  	
//  			if (errno) error(0,errno, "on CAN_Write, continuing...");
//  		
// 		};
//
//	};

  	  	
   	while (getch()!='q')
   	{
    	TPCANMsg m;
    	/* Get a message */
     	errno=CAN_Read(h, &m);
     	if (errno) error(0,errno, "on CAN_read, continuing");
     	else process_message(&m);
     	
     	/* Clear any status info */
     	status = CAN_Status(h);
    	if ((int)status < 0) 
    	{
      		errno = nGetLastError();
      		error(0,errno," CAN_Status()");
    	}else mvprintw(10,0,"pending CAN status 0x%04x read.\n", (__u16)status); clrtoeol();
    	
    	print_object();
    	
    	//white
		cube.cubelet[0][0][0].face[0].RGB[0]=(float)(1-(object[1].data[8]/4096.0));
		cube.cubelet[0][0][0].face[0].RGB[1]=(float)(1-(object[1].data[8]/4096.0));
		cube.cubelet[0][0][0].face[0].RGB[2]=(float)(1-(object[1].data[8]/4096.0));
  		
		cube.cubelet[1][0][0].face[0].RGB[0]=(float)(1-(object[1].data[7]/4096.0));
  		cube.cubelet[1][0][0].face[0].RGB[1]=(float)(1-(object[1].data[7]/4096.0));
  		cube.cubelet[1][0][0].face[0].RGB[2]=(float)(1-(object[1].data[7]/4096.0));	

  		cube.cubelet[2][0][0].face[0].RGB[0]=(float)(1-(object[1].data[6]/4096.0));
  		cube.cubelet[2][0][0].face[0].RGB[1]=(float)(1-(object[1].data[6]/4096.0));
  		cube.cubelet[2][0][0].face[0].RGB[2]=(float)(1-(object[1].data[6]/4096.0));	

  		cube.cubelet[0][1][0].face[0].RGB[0]=(float)(1-(object[1].data[5]/4096.0));
  		cube.cubelet[0][1][0].face[0].RGB[1]=(float)(1-(object[1].data[5]/4096.0));
  		cube.cubelet[0][1][0].face[0].RGB[2]=(float)(1-(object[1].data[5]/4096.0));	

  		cube.cubelet[1][1][0].face[0].RGB[0]=(float)(1-(object[1].data[1]/4096.0));
  		cube.cubelet[1][1][0].face[0].RGB[1]=(float)(1-(object[1].data[1]/4096.0));
  		cube.cubelet[1][1][0].face[0].RGB[2]=(float)(1-(object[1].data[1]/4096.0));	

  		cube.cubelet[2][1][0].face[0].RGB[0]=(float)(1-(object[1].data[0]/4096.0));
  		cube.cubelet[2][1][0].face[0].RGB[1]=(float)(1-(object[1].data[0]/4096.0));
  		cube.cubelet[2][1][0].face[0].RGB[2]=(float)(1-(object[1].data[0]/4096.0));	

  		cube.cubelet[0][2][0].face[0].RGB[0]=(float)(1-(object[1].data[2]/4096.0));
  		cube.cubelet[0][2][0].face[0].RGB[1]=(float)(1-(object[1].data[2]/4096.0));
  		cube.cubelet[0][2][0].face[0].RGB[2]=(float)(1-(object[1].data[2]/4096.0));	
    	
  		cube.cubelet[1][2][0].face[0].RGB[0]=(float)(1-(object[1].data[3]/4096.0));
  		cube.cubelet[1][2][0].face[0].RGB[1]=(float)(1-(object[1].data[3]/4096.0));
  		cube.cubelet[1][2][0].face[0].RGB[2]=(float)(1-(object[1].data[3]/4096.0));    	

  		cube.cubelet[2][2][0].face[0].RGB[0]=(float)(1-(object[1].data[4]/4096.0));
  		cube.cubelet[2][2][0].face[0].RGB[1]=(float)(1-(object[1].data[4]/4096.0));
  		cube.cubelet[2][2][0].face[0].RGB[2]=(float)(1-(object[1].data[4]/4096.0));    	
    	
    	
    	//blue
		cube.cubelet[0][2][0].face[1].RGB[0]=0;
  		cube.cubelet[0][2][0].face[1].RGB[1]=0;
  		cube.cubelet[0][2][0].face[1].RGB[2]=(float)(1-(object[3].data[6]/4096.0));
		
		cube.cubelet[1][2][0].face[1].RGB[0]=0;
  		cube.cubelet[1][2][0].face[1].RGB[1]=0;
  		cube.cubelet[1][2][0].face[1].RGB[2]=(float)(1-(object[3].data[0]/4096.0));  		
 
		cube.cubelet[2][2][0].face[1].RGB[0]=0;
  		cube.cubelet[2][2][0].face[1].RGB[1]=0;
  		cube.cubelet[2][2][0].face[1].RGB[2]=(float)(1-(object[3].data[4]/4096.0));
  		
		cube.cubelet[0][2][1].face[1].RGB[0]=0;
  		cube.cubelet[0][2][1].face[1].RGB[1]=0;
  		cube.cubelet[0][2][1].face[1].RGB[2]=(float)(1-(object[3].data[7]/4096.0));

		cube.cubelet[1][2][1].face[1].RGB[0]=0;
  		cube.cubelet[1][2][1].face[1].RGB[1]=0;
  		cube.cubelet[1][2][1].face[1].RGB[2]=(float)(1-(object[3].data[1]/4096.0));

		cube.cubelet[2][2][1].face[1].RGB[0]=0;
  		cube.cubelet[2][2][1].face[1].RGB[1]=0;
  		cube.cubelet[2][2][1].face[1].RGB[2]=(float)(1-(object[3].data[3]/4096.0));
  		
		cube.cubelet[0][2][2].face[1].RGB[0]=0;
  		cube.cubelet[0][2][2].face[1].RGB[1]=0;
  		cube.cubelet[0][2][2].face[1].RGB[2]=(float)(1-(object[3].data[8]/4096.0));

		cube.cubelet[1][2][2].face[1].RGB[0]=0;
  		cube.cubelet[1][2][2].face[1].RGB[1]=0;
  		cube.cubelet[1][2][2].face[1].RGB[2]=(float)(1-(object[3].data[5]/4096.0));

		cube.cubelet[2][2][2].face[1].RGB[0]=0;
  		cube.cubelet[2][2][2].face[1].RGB[1]=0;
  		cube.cubelet[2][2][2].face[1].RGB[2]=(float)(1-(object[3].data[2]/4096.0));  	  		  		  		   		    	

    	//yellow
		cube.cubelet[0][0][2].face[5].RGB[0]=(float)(1-(object[5].data[2]/4096.0));
  		cube.cubelet[0][0][2].face[5].RGB[1]=(float)(1-(object[5].data[2]/4096.0));
  		cube.cubelet[0][0][2].face[5].RGB[2]=0;

		cube.cubelet[1][0][2].face[5].RGB[0]=(float)(1-(object[5].data[3]/4096.0));
  		cube.cubelet[1][0][2].face[5].RGB[1]=(float)(1-(object[5].data[3]/4096.0));
  		cube.cubelet[1][0][2].face[5].RGB[2]=0;
  		  		
		cube.cubelet[2][0][2].face[5].RGB[0]=(float)(1-(object[5].data[4]/4096.0));
  		cube.cubelet[2][0][2].face[5].RGB[1]=(float)(1-(object[5].data[4]/4096.0));
  		cube.cubelet[2][0][2].face[5].RGB[2]=0;
  		
  		cube.cubelet[0][1][2].face[5].RGB[0]=(float)(1-(object[5].data[5]/4096.0));
  		cube.cubelet[0][1][2].face[5].RGB[1]=(float)(1-(object[5].data[5]/4096.0));
  		cube.cubelet[0][1][2].face[5].RGB[2]=0;  
  		
  		cube.cubelet[1][1][2].face[5].RGB[0]=(float)(1-(object[5].data[1]/4096.0));
  		cube.cubelet[1][1][2].face[5].RGB[1]=(float)(1-(object[5].data[1]/4096.0));
  		cube.cubelet[1][1][2].face[5].RGB[2]=0;  
    	
		cube.cubelet[2][1][2].face[5].RGB[0]=(float)(1-(object[5].data[0]/4096.0));
  		cube.cubelet[2][1][2].face[5].RGB[1]=(float)(1-(object[5].data[0]/4096.0));
  		cube.cubelet[2][1][2].face[5].RGB[2]=0;
 
  		cube.cubelet[0][2][2].face[5].RGB[0]=(float)(1-(object[5].data[8]/4096.0));
  		cube.cubelet[0][2][2].face[5].RGB[1]=(float)(1-(object[5].data[8]/4096.0));
  		cube.cubelet[0][2][2].face[5].RGB[2]=0;  
  		
  		cube.cubelet[1][2][2].face[5].RGB[0]=(float)(1-(object[5].data[7]/4096.0));
  		cube.cubelet[1][2][2].face[5].RGB[1]=(float)(1-(object[5].data[7]/4096.0));
  		cube.cubelet[1][2][2].face[5].RGB[2]=0;  
    	
		cube.cubelet[2][2][2].face[5].RGB[0]=(float)(1-(object[5].data[6]/4096.0));
  		cube.cubelet[2][2][2].face[5].RGB[1]=(float)(1-(object[5].data[6]/4096.0));
  		cube.cubelet[2][2][2].face[5].RGB[2]=0;
  		

  		//orange
		cube.cubelet[0][0][0].face[4].RGB[0]=(float)(1-(object[2].data[8]/4096.0));
  		cube.cubelet[0][0][0].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[8]/4096.0));
  		cube.cubelet[0][0][0].face[4].RGB[2]=0;

		cube.cubelet[0][0][1].face[4].RGB[0]=(float)(1-(object[2].data[5]/4096.0));
  		cube.cubelet[0][0][1].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[5]/4096.0));
  		cube.cubelet[0][0][1].face[4].RGB[2]=0;   	

		cube.cubelet[0][0][2].face[4].RGB[0]=(float)(1-(object[2].data[2]/4096.0));
  		cube.cubelet[0][0][2].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[2]/4096.0));
  		cube.cubelet[0][0][2].face[4].RGB[2]=0;

		cube.cubelet[0][1][0].face[4].RGB[0]=(float)(1-(object[2].data[7]/4096.0));
  		cube.cubelet[0][1][0].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[7]/4096.0));
  		cube.cubelet[0][1][0].face[4].RGB[2]=0;

		cube.cubelet[0][1][1].face[4].RGB[0]=(float)(1-(object[2].data[1]/4096.0));
  		cube.cubelet[0][1][1].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[1]/4096.0));
  		cube.cubelet[0][1][1].face[4].RGB[2]=0;   	

		cube.cubelet[0][1][2].face[4].RGB[0]=(float)(1-(object[2].data[3]/4096.0));
  		cube.cubelet[0][1][2].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[3]/4096.0));
  		cube.cubelet[0][1][2].face[4].RGB[2]=0;
  		
		cube.cubelet[0][2][0].face[4].RGB[0]=(float)(1-(object[2].data[6]/4096.0));
  		cube.cubelet[0][2][0].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[6]/4096.0));
  		cube.cubelet[0][2][0].face[4].RGB[2]=0;

		cube.cubelet[0][2][1].face[4].RGB[0]=(float)(1-(object[2].data[0]/4096.0));
  		cube.cubelet[0][2][1].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[0]/4096.0));
  		cube.cubelet[0][2][1].face[4].RGB[2]=0;   	

		cube.cubelet[0][2][2].face[4].RGB[0]=(float)(1-(object[2].data[4]/4096.0));
  		cube.cubelet[0][2][2].face[4].RGB[1]=(float)(0.5-0.5*(object[2].data[4]/4096.0));
  		cube.cubelet[0][2][2].face[4].RGB[2]=0;
  		
  		//red
		cube.cubelet[2][0][0].face[2].RGB[0]=(float)(1-(object[4].data[6]/4096.0));
  		cube.cubelet[2][0][0].face[2].RGB[1]=0;
  		cube.cubelet[2][0][0].face[2].RGB[2]=0;
  		
		cube.cubelet[2][0][1].face[2].RGB[0]=(float)(1-(object[4].data[0]/4096.0));
  		cube.cubelet[2][0][1].face[2].RGB[1]=0;
  		cube.cubelet[2][0][1].face[2].RGB[2]=0;

		cube.cubelet[2][0][2].face[2].RGB[0]=(float)(1-(object[4].data[4]/4096.0));
  		cube.cubelet[2][0][2].face[2].RGB[1]=0;
  		cube.cubelet[2][0][2].face[2].RGB[2]=0;

		cube.cubelet[2][1][0].face[2].RGB[0]=(float)(1-(object[4].data[7]/4096.0));
  		cube.cubelet[2][1][0].face[2].RGB[1]=0;
  		cube.cubelet[2][1][0].face[2].RGB[2]=0;
  		
		cube.cubelet[2][1][1].face[2].RGB[0]=(float)(1-(object[4].data[1]/4096.0));
  		cube.cubelet[2][1][1].face[2].RGB[1]=0;
  		cube.cubelet[2][1][1].face[2].RGB[2]=0;

		cube.cubelet[2][1][2].face[2].RGB[0]=(float)(1-(object[4].data[3]/4096.0));
  		cube.cubelet[2][1][2].face[2].RGB[1]=0;
  		cube.cubelet[2][1][2].face[2].RGB[2]=0;
  		
		cube.cubelet[2][2][0].face[2].RGB[0]=(float)(1-(object[4].data[8]/4096.0));
  		cube.cubelet[2][2][0].face[2].RGB[1]=0;
  		cube.cubelet[2][2][0].face[2].RGB[2]=0;
  		
		cube.cubelet[2][2][1].face[2].RGB[0]=(float)(1-(object[4].data[5]/4096.0));
  		cube.cubelet[2][2][1].face[2].RGB[1]=0;
  		cube.cubelet[2][2][1].face[2].RGB[2]=0;

		cube.cubelet[2][2][2].face[2].RGB[0]=(float)(1-(object[4].data[2]/4096.0));
  		cube.cubelet[2][2][2].face[2].RGB[1]=0;
  		cube.cubelet[2][2][2].face[2].RGB[2]=0;     		    		    		  		  		    		  		   	  		   		
  		
   		//green
		cube.cubelet[0][0][0].face[3].RGB[0]=0;
  		cube.cubelet[0][0][0].face[3].RGB[1]=(float)(1-(object[0].data[8]/4096.0));
  		cube.cubelet[0][0][0].face[3].RGB[2]=0;
  		
		cube.cubelet[1][0][0].face[3].RGB[0]=0;
  		cube.cubelet[1][0][0].face[3].RGB[1]=(float)(1-(object[0].data[5]/4096.0));
  		cube.cubelet[1][0][0].face[3].RGB[2]=0; 	

		cube.cubelet[2][0][0].face[3].RGB[0]=0;
  		cube.cubelet[2][0][0].face[3].RGB[1]=(float)(1-(object[0].data[2]/4096.0));
  		cube.cubelet[2][0][0].face[3].RGB[2]=0;
  		
		cube.cubelet[0][0][1].face[3].RGB[0]=0;
  		cube.cubelet[0][0][1].face[3].RGB[1]=(float)(1-(object[0].data[7]/4096.0));
  		cube.cubelet[0][0][1].face[3].RGB[2]=0;
  		
		cube.cubelet[1][0][1].face[3].RGB[0]=0;
  		cube.cubelet[1][0][1].face[3].RGB[1]=(float)(1-(object[0].data[1]/4096.0));
  		cube.cubelet[1][0][1].face[3].RGB[2]=0; 	

		cube.cubelet[2][0][1].face[3].RGB[0]=0;
  		cube.cubelet[2][0][1].face[3].RGB[1]=(float)(1-(object[0].data[3]/4096.0));
  		cube.cubelet[2][0][1].face[3].RGB[2]=0;
  		
		cube.cubelet[0][0][2].face[3].RGB[0]=0;
  		cube.cubelet[0][0][2].face[3].RGB[1]=(float)(1-(object[0].data[6]/4096.0));
  		cube.cubelet[0][0][2].face[3].RGB[2]=0;
  		
		cube.cubelet[1][0][2].face[3].RGB[0]=0;
  		cube.cubelet[1][0][2].face[3].RGB[1]=(float)(1-(object[0].data[0]/4096.0));
  		cube.cubelet[1][0][2].face[3].RGB[2]=0; 	

		cube.cubelet[2][0][2].face[3].RGB[0]=0;
  		cube.cubelet[2][0][2].face[3].RGB[1]=(float)(1-(object[0].data[4]/4096.0));
  		cube.cubelet[2][0][2].face[3].RGB[2]=0;
  		
  		
 
  		//usleep(1000);
  		   		  			  		  		 		           	
    	//write_object(teste123);
    	refresh();
  	};
	
 	pthread_join(threads,NULL);
 	pthread_attr_destroy(&attr);
 
	return 0;
}


