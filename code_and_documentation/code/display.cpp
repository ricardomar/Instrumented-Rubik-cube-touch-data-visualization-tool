
#include <GL/glut.h>
#include "_cube.h"
#include <stdio.h>


CUBE* pcube;
int Window;
double rx=0,ry=0,rz=0;	//Angles
double zoom=-18; //zoom

void display( CUBE *cube )
{
  pcube = (CUBE*) cube;
}



void drawcubelet( CUBELET *cubelet )
{
  glBegin(GL_QUADS);
  //face 0
  glColor3d(cubelet->face[0].RGB[0],cubelet->face[0].RGB[1],cubelet->face[0].RGB[2]);
  glVertex3i(1,1,1);
  glVertex3i(1,-1,1);
  glVertex3i(-1,-1,1);
  glVertex3i(-1,1,1);
  //face 1
  glColor3d(cubelet->face[1].RGB[0],cubelet->face[1].RGB[1],cubelet->face[1].RGB[2]);
  glVertex3i(-1,1,-1);
  glVertex3i(-1,1,1);
  glVertex3i(1,1,1);
  glVertex3i(1,1,-1);
  //face 2 
  glColor3d(cubelet->face[2].RGB[0],cubelet->face[2].RGB[1],cubelet->face[2].RGB[2]);
  glVertex3i(1,1,1);
  glVertex3i(1,-1,1);
  glVertex3i(1,-1,-1);
  glVertex3i(1,1,-1);
  //face 3
  glColor3d(cubelet->face[3].RGB[0],cubelet->face[3].RGB[1],cubelet->face[3].RGB[2]);
  glVertex3i(-1,-1,-1);
  glVertex3i(-1,-1,1);
  glVertex3i(1,-1,1);
  glVertex3i(1,-1,-1);
  //face 4
  glColor3d(cubelet->face[4].RGB[0],cubelet->face[4].RGB[1],cubelet->face[4].RGB[2]);
  glVertex3i(-1,1,1);
  glVertex3i(-1,-1,1);
  glVertex3i(-1,-1,-1);
  glVertex3i(-1,1,-1);
  //face 5
  glColor3d(cubelet->face[5].RGB[0],cubelet->face[5].RGB[1],cubelet->face[5].RGB[2]);
  glVertex3i(1,1,-1);
  glVertex3i(1,-1,-1);
  glVertex3i(-1,-1,-1);
  glVertex3i(-1,1,-1);
  glEnd();
}


void draw(void)
{
  //	a+=2;
  //	b+=1.6;
  
  //printf("ricardo\n");
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  glTranslated(0,0,zoom);// Equivaut exactement à gluLookAt(0,0,5,0,0,0,0,1,0);
  //glRotated(pcube->Rot[0],1,0,0);
  //glRotated(pcube->Rot[1],0,1,0);
  //glRotated(pcube->Rot[2],0,0,1);
  
  glRotated(rx,1,0,0);
  glRotated(ry,0,1,0);
  glRotated(rz,0,0,1);
  
  
  glColorMaterial(GL_FRONT_AND_BACK,GL_SPECULAR);
  //Ca marche aussi avec specular !
  
  glTranslated(-2.5,-2.5,-2.5);
  drawcubelet(&(pcube->cubelet[0][0][2]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][0][2]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[2][0][2]));
  glTranslated(0,2.5,0);
  drawcubelet(&(pcube->cubelet[2][1][2]));
  glTranslated(-2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][1][2]));
  glTranslated(-2.5,0,0);
  drawcubelet(&(pcube->cubelet[0][1][2]));
  glTranslated(0,2.5,0);
  drawcubelet(&(pcube->cubelet[0][2][2]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][2][2]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[2][2][2]));
  glTranslated(0,0,2.5);
  drawcubelet(&(pcube->cubelet[2][2][1]));
  glTranslated(-2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][2][1]));
  glTranslated(-2.5,0,0);
  drawcubelet(&(pcube->cubelet[0][2][1]));
  glTranslated(0,-2.5,0);
  drawcubelet(&(pcube->cubelet[0][1][1]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][1][1]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[2][1][1]));
  glTranslated(0,-2.5,0);
  drawcubelet(&(pcube->cubelet[2][0][1]));
  glTranslated(-2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][0][1]));
  glTranslated(-2.5,0,0);
  drawcubelet(&(pcube->cubelet[0][0][1]));
  glTranslated(0,0,2.5);
  drawcubelet(&(pcube->cubelet[0][0][0]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][0][0]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[2][0][0]));
  glTranslated(0,2.5,0);
  drawcubelet(&(pcube->cubelet[2][1][0]));
  glTranslated(-2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][1][0]));
  glTranslated(-2.5,0,0);
  drawcubelet(&(pcube->cubelet[0][1][0]));
  glTranslated(0,2.5,0);
  drawcubelet(&(pcube->cubelet[0][2][0]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[1][2][0]));
  glTranslated(2.5,0,0);
  drawcubelet(&(pcube->cubelet[2][2][0]));
	
  glutSwapBuffers();
  glutPostRedisplay();
}


void InitGL()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR);
}


void reshape(int width, int height)
{
  glViewport(0,0,width,height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.,(float)width/(float)height,0.01,100);
  glMatrixMode(GL_MODELVIEW);
}


void GestionClavier(unsigned char key, int x, int y)  
{
  switch(key) {
  case '2':
    rx--;
    return;
  case '8':
    rx++;
    return;
  case '4':
    ry--;
    return;
  case '6':
    ry++;
    return;
  case '9':
    rz--;
    return;
  case '7':
    rz++;
    return;
  case ' ':
    rx=0;
    ry=0;
    rz=0;
    return;
  case '+':
    zoom += 1.0;
    return;
  case '-':
    zoom -=1.0;
    return;
  case 27:
    exit(0);
  }
} 


void initdisplay( int argc, char *argv[] )
{
  glutInit(&argc,argv);
  glutInitWindowSize(640,480);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  
  Window = glutCreateWindow("Rubik's Cube");
  
  InitGL();
  glutReshapeFunc(reshape);
  glutDisplayFunc(draw);
  glutKeyboardFunc(GestionClavier);
  
  glutMainLoop();
}


void rundisplay( CUBE *cube, int argc, char *argv[] )
{
  display(cube);
  initdisplay( argc, argv );
}


/* END OF display.c */
