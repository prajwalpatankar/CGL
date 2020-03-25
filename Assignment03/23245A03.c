/*
========================================================================================
Roll no. 		  :23245
Batch    		  :G10
Assignment no.	  :3
Problem Statement :Draw Polygons using mouse. Choose the colours by clicking on 
				   designed color panes,the window past to draw.
========================================================================================
*/
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include<stdlib.h>
#include <stdio.h>

typedef struct poly
{
     int x;
     int y;
}poly;	

int i=0,n,ch=1,count=1,e,f;             //pos=positive constant   neg=negative constant  s=sign     
poly p[10];
typedef struct pixel
{
     GLubyte r;
     GLubyte g;
     GLubyte b;

}pixel;
pixel b_clr,f_clr;
void dda(float X1,float Y1,float X2, float Y2)
{
	float dx=(X2-X1);
	float dy=(Y2-Y1);
	float step;
	float xInc,yInc,x=X1,y=Y1;
	step=(abs(dx)>abs(dy))?(abs(dx)):abs((dy));
	xInc=(float)dx/(float)step;
	yInc=(float)dy/(float)step;
     	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glColor3ub(0,0,0);
	int k;
	for(k=0;k<step;k++)
	{
		x+=xInc;
		y+=yInc;
		glVertex2d(round(x),round(y));
	}
	glEnd();
	glFlush();
}
void boundary_fill(int x,int y)
{
     pixel c;
     glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&c);
     if((c.r!=b_clr.r || c.g!=b_clr.g || c.b!=b_clr.b) && (c.r!=f_clr.r || c.g!=f_clr.g || c.b!=f_clr.b))
     {
         
          glBegin(GL_POINTS);
          glVertex2d(x,y);
          glColor3ub(f_clr.r,f_clr.g,f_clr.b);
          glEnd();
          glFlush();
          boundary_fill(x,y+1);
          boundary_fill(x-1,y);
          boundary_fill(x,y-1);
          boundary_fill(x+1,y);
     }
} 
void draw_axis()
{
    glBegin(GL_POINTS);                  //draw axis
	dda(50,50,50,100);
	for(int i=100;i<=450;i+=50)  //colour pallete
	{
	     dda(i,50,i,100);
	}
	dda(50,50,50,100);
	dda(50,50,450,50);
	dda(50,100,450,100);
	f_clr.r=255;
	f_clr.g=165;
	f_clr.b=0;
	boundary_fill(75,75);
	f_clr.r=255;
	f_clr.g=102;
	f_clr.b=255;
	boundary_fill(125,75);
	f_clr.r=0;
	f_clr.g=255;
	f_clr.b=0;
	boundary_fill(175,75);
	f_clr.r=0;
	f_clr.g=0;
	f_clr.b=255;
	boundary_fill(225,75);
	f_clr.r=255;
	f_clr.g=255;
	f_clr.b=0;
	boundary_fill(275,75);
	f_clr.r=255;
	f_clr.g=0;
	f_clr.b=255;
	boundary_fill(325,75);
	f_clr.r=0;
	f_clr.g=255;
	f_clr.b=255;
	boundary_fill(375,75);
	f_clr.r=255;
	f_clr.g=0;
	f_clr.b=0;
	boundary_fill(425,75);
	
	
	glEnd();
	glFlush();
	
} 
void draw()
{   
      glClear(GL_COLOR_BUFFER_BIT);
      draw_axis();
      glBegin(GL_POINTS);
      glColor3ub(0,0,0);
      glEnd();
      glFlush();
      
}

void mouse(int btn,int state,int x,int y)
{
     
      int k,X1,Y1,X2,Y2; 
      if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN && i<n)
      {
            p[i].x=x;
            p[i].y=500-y;
            i++;
      }
      else if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
      {
            
            switch(ch)
            {
            case 1: X1=x;
                    Y1=500-y;
                    for(k=0;k<n-1;k++)
                    {
                         dda(p[k].x,p[k].y,p[k+1].x,p[k+1].y);
                    }
                    dda(p[0].x,p[0].y,p[n-1].x,p[n-1].y);
                    ch=2;
                    break;
            case 2: e=x;
		        	f=500-y;
		        	++count;
		        	ch=3;
		        	break;
            case 3: X2=x;
	                Y2=500-y;
	                glReadPixels(X2,Y2,1,1,GL_RGB,GL_UNSIGNED_BYTE,&f_clr);
          	        boundary_fill(e,f);
                    ch=2;
                    break;
            }  
      }
      glFlush();
      glEnd();
}
      
void init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3i(0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,500,0,500);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	printf("Enter no of vertices ");
	scanf("%d",&n);
	b_clr.r=0;
    b_clr.g=0;
    b_clr.b=0;
    glutCreateWindow("POLYGON FILLING");
	init();
	glutDisplayFunc(draw);
	glutMouseFunc(mouse);
	glutMainLoop();
}
