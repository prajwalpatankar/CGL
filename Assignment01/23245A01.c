/*
========================================================================================
Roll no. 		  :23245
Batch    		  :G10
Assignment no.	  :1
Problem Statement :LINE DRAWING ALGORITHMS.
========================================================================================
*/


#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void dda(float, float, float, float);
void bla(float,float,float,float);
void plot(int ,int);
void displayDDA();
void displayBLA();
int sign(float x);


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
    	printf("\n(1)Draw the diagram using DDA");
    	printf("\n(2)Draw the diagram using Bressenham's Line Generation");
    	printf("\n(3)EXIT");
    	printf("\nEnter Your choice : ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1://DDA
    			glutCreateWindow("Diagram using DDA");
    			glutDisplayFunc(displayDDA);
    			glutMainLoop();   
    			break;
    			
    		case 2://Bressenham
    			glutCreateWindow("Diagram using BLA");
    			glutDisplayFunc(displayBLA);
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


void dda(float x1,float y1,float x2,float y2)
{
    float dx,dy,xinc,yinc,diff,x,y;
    int i;
    
    dx=x2-x1;
    dy=y2-y1;
    
    if( abs(dx) > abs(dy) )
    {
        diff=abs(dx);
    }
    else
    {
        diff=abs(dy);
    }
       
    xinc = dx/diff;
    yinc = dy/diff;
    x=x1;
    y=y1;
    
    plot(round(x),round(y));
    
    for (i=1;i<=diff;i++)
	{
		x=x+xinc;
		y=y+yinc;
		plot(round(x),round(y));
	}	
	 
	glFlush();    
}

    
void plot(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void displayDDA()
{
	float x1,x2,x3,x4,x5,y1,y2,y3,y4,y5,temp;
	printf("Enter End Points of diagonal of outer square :");
	printf("\nx1: ");
	scanf("%f",&x1);
    printf("\ny1: ");
    scanf("%f",&y1);
    printf("\nx2: ");
    scanf("%f",&x2);
    printf("\ny2: ");
    scanf("%f",&y2);
    
	glClearColor(0.2, 0.2, 0.2, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	
	if(x1>x2)
	{
		temp=x1;
		x1=x2;
		x2=temp;
	}
	else if(y1>y2)
	{
		temp=y1;
		y1=y2;
		y2=temp;
	}
	
	glColor3f(0.0, 0.0, 1.0);
	//outer squarea
	dda(x1,y1,x1,y2);
	dda(x1,y2,x2,y2);
	dda(x2,y2,x2,y1);
	dda(x2,y1,x1,y1);	
	
	x3=(x1+x2)/2;		//midpoint calculations
	y3=(y1+y2)/2;
		
	glColor3f(0.0, 1.0, 0.0);	
	//diamond
	dda(x1,y3,x3,y2);
	dda(x3,y2,x2,y3);
	dda(x2,y3,x3,y1);
	dda(x3,y1,x1,y3);	
	
	x4=(x1+x3)/2;		//midpoint calculations
	x5=(x3+x2)/2;
	y4=(y1+y3)/2;
	y5=(y2+y3)/2;

	glColor3f(1.0, 0.0, 0.0);	
	//inner square
	dda(x4,y4,x4,y5);
	dda(x4,y5,x5,y5);
	dda(x5,y5,x5,y4);
	dda(x5,y4,x4,y4);		

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

void displayBLA()
{
	float x1,x2,x3,x4,x5,y1,y2,y3,y4,y5,temp;
	printf("Enter End Points of diagonal of outer square :");
	printf("\nx1: ");
	scanf("%f",&x1);
    printf("\ny1: ");
    scanf("%f",&y1);
    printf("\nx2: ");
    scanf("%f",&x2);
    printf("\ny2: ");
    scanf("%f",&y2);
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
		
    //outer squarea
	bla(x1,y1,x1,y2);
	bla(x1,y2,x2,y2);
	bla(x2,y2,x2,y1);
	bla(x2,y1,x1,y1);	
	
	x3=(x1+x2)/2;		//midpoint calculations
	y3=(y1+y2)/2;
		
	//diamond
	bla(x1,y3,x3,y2);
	bla(x3,y2,x2,y3);
	bla(x2,y3,x3,y1);
	bla(x3,y1,x1,y3);	
	
	x4=(x1+x3)/2;		//midpoint calculations
	x5=(x3+x2)/2;
	y4=(y1+y3)/2;
	y5=(y2+y3)/2;
	
	//inner square
	bla(x4,y4,x4,y5);
	bla(x4,y5,x5,y5);
	bla(x5,y5,x5,y4);
	bla(x5,y4,x4,y4);		
   

} 

