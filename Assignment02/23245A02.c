/*
========================================================================================
Roll no. 		  :23245
Batch    		  :G10
Assignment no.	  :2
Problem Statement :DRAW INSCRIBED AND CIRCUMSCRIBED TRIANGLE USING CIRCLE AND LINE 
				   AND CIRCLE DRAWING ALGORITHMS.
========================================================================================
*/



#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void plot(int ,int);
void midpoint(int);
int sign(float x);
void bressenham(int);
void bla(float,float,float,float);
void display1();
void display2();

int main(int argc,char **argv)
{
	int choice;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    do
    {
       
    	printf("\n\n\tMENU::");
    	printf("\n(1)Draw the diagram using Midpoint Algorithm");
    	printf("\n(2)Draw the diagram using Bressenham's Algorithm");
    	printf("\n(3)EXIT");
    	printf("\nEnter Your choice : ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1://Midpoint Algorithm
    			glutCreateWindow("Diagram using ");
    			glutDisplayFunc(display1);
    			glutMainLoop();   
    			break;
    			
    		case 2://Bressenhams algorithm
    			glutCreateWindow("Diagram using ");
    			glutDisplayFunc(display2);
    			glutMainLoop();  
    			break;
    			
    		case 3://EXIT
    			return 0;
    			
    		default://INVALID
    			printf("\nINVALID CHOICE !!!");
    			break;
    	}    	
    }while(1);
     
    return 0;
}

void plot(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void display1()
{
	int r,r2;
	float x;
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000,1000,-1000,1000);
	
	printf("Enter Radius of Inner Circle : ");
	scanf("%d",&r);
	
	r2=2*r;
	x=sqrt(3*r*r);
		
	midpoint(r);									//Inner Circle
	
	midpoint(r2);									//Outer Circle
														
	bla(0,r2,x,-r);									//Triangle
	bla(x,-r,-x,-r);
	bla(-x,-r,0,r2);
	
	
}

int sign(float x)
{
	if(x<0)
		return -1;
	else if(x>0)
		return 1;
	return 0;
}

void bla(float x1,float y1,float x2,float y2)
{
	float x,y,dx,dy,temp,diff;
	int s1,s2,sw,n=1,p;
	
	x=x1;
	y=y1;
	
	dx=abs(x2-x1);													
	dy=abs(y2-y1);													
	
	s1=sign(x2-x1);
	s2=sign(y2-y1);	
	
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		sw=1;
	}
	else
	{
		sw=0;
	}	
	
	p=(2*dy)-dx;
	plot(round(x),round(y));
	
	while(n<=dx)
	{																
		if(p>=0)
		{
			x=x+s1;
			y=y+s2;
			p=p+(2*(dy-dx));
			plot(round(x),round(y));
		}
		else
		{
			if(sw==1)
			{
				y=y+s2;
			}
			else
			{			
				x=x+s1;
			}
			p=p+(2*dy);
			plot(round(x),round(y));
		}
		n++;
	}
}

void midpoint(int r)
{    		
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{									
		if (decision < 0)
		{										
			decision += 2*x+3;	
			x++;
		}
		else
		{
			decision += 2*(x-y)+5;
			y--;
			x++;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
}

void bressenham(int r)
{
	float x=0.0,y=r;
	float decision=3-2*r;
	plot(0,r);
	while(x<=y)
	{
		if(decision<0)
		{
			decision += 4*x + 6;
			x++;
		}
		else
		{
			decision += 4*(x-y) +10;
			x++;
			y--;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
}
			
			
void display2()
{
	int r,r2;
	float x;
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	
	printf("Enter Radius of Inner Circle : ");
	scanf("%d",&r);
	
	r2=2*r;
	x=sqrt(3*r*r);
		
	bressenham(r);									//Inner Circle
	
	bressenham(r2);									//Outer Circle
														
	bla(0,r2,x,-r);									//Triangle
	bla(x,-r,-x,-r);
	bla(-x,-r,0,r2);
	
	
} 
	
	
	
	
	
	
	
	
	
