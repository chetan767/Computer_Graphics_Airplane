// made by Chetan Khanna
// Program to Design and Render a scene to showcase a moving AEROPLANE. The Aeroplane should move up and down on Keyboard control events.
#include <iostream>
using namespace std;
#define GL_SILENCE_DEPRECATION
#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<stdio.h>
#include<iostream>
#endif

#include<math.h>



float xt=1.0,yt=1.0; // For interactive Keyboard
float x = 1.0,y = 1.0,z=1.0; // For Movement

void DrawCircle(float cirx, float ciry, float r, int num_segments) // to draw circle for clouds
{
    glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        
        glVertex2f(x + cirx, y + ciry);
        
    }
    glEnd();
}

void drawcloud() // to draw clouds
{
    
    glPushMatrix();
    glColor3f(1,1,1);
    glScalef(0.3, 0.3, 0);
    glTranslated(120, 0, 0);
    DrawCircle(600,900,60,1000);
    DrawCircle(530,900,40,1000);
    DrawCircle(670,900,40,1000);
    DrawCircle(200,900,45,1000);
    DrawCircle(150,900,30,1000);
    DrawCircle(250,900,30,1000);
    glPopMatrix();
    
    
}

void init() // for inialization
{
    glClearColor(0.5, 0.2, 1.0,0.0);
    
    glPointSize(5.0);
    glLineWidth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,400.0,0.0,400.0);
}

void draw_circle(float x, float y, float radius) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    double angle1=0.0;
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    glEnd();
    glPopMatrix();
}

void runway() // to make runway (road)
{
    
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);//black road
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,100.0);
    glVertex2f(500.0,100.0);
    glVertex2f(500.0,0.0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);//white strips on road
    glVertex2f(0.0,40.0);
    glVertex2f(8.0,60.0);
    glVertex2f(58.0,60.0);
    glVertex2f(50.0,40.0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(100.0,40.0);
    glVertex2f(108.0,60.0);
    glVertex2f(158.0,60.0);
    glVertex2f(150.0,40.0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(200.0,40.0);
    glVertex2f(208.0,60.0);
    glVertex2f(258.0,60.0);
    glVertex2f(250.0,40.0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(300.0,40.0);
    glVertex2f(308.0,60.0);
    glVertex2f(358.0,60.0);
    glVertex2f(350.0,40.0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(400.0,40.0);
    glVertex2f(408.0,60.0);
    glVertex2f(458.0,60.0);
    glVertex2f(450.0,40.0);
    glEnd();
    glPopMatrix();
}


void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,0.0f);
    
    glPushMatrix();
    glPushMatrix();
    
    runway();
    
    glTranslatef(50,80,0.0);
    glTranslatef(xt,yt,0.0);
    
    glBegin(GL_POLYGON); // draw rectangular body
    glColor3f(1.0,0.8,0.0);
    glVertex2f(0.0,30.0);
    glVertex2f(0.0,55.0);
    glVertex2f(135.0,55.0);
    glVertex2f(135.0,30.0);
    glEnd();
    glPushMatrix();
        
    
    glBegin(GL_POLYGON); //draw upper triangle construction plane
    glColor3f(1.0,0.3,0.0);
    glVertex2f(135.0,55.0);
    glVertex2f(150.0,50.0);
    glVertex2f(155.0,45.0);
    glVertex2f(160.0,40.0);
    glVertex2f(135.0,40.0);
    glEnd();
    
    
    glBegin(GL_LINE_LOOP);//draw outline of upper triangle plane
    glColor3f(0.0,0.0,0.0);
    glVertex2f(135.0,55.0);
    glVertex2f(150.0,50.0);
    glVertex2f(155.0,45.0);
    glVertex2f(160.0,40.0);
    glVertex2f(135.0,40.0);
    glEnd();
    
    glBegin(GL_POLYGON); // lower traingle
    glColor3f(1.0,0.3,0.0);
    glVertex2f(135.0,40.0);
    glVertex2f(160.0,40.0);
    glVertex2f(160.0,37.0);
    glVertex2f(145.0,30.0);
    glVertex2f(135.0,30.0);
    glEnd();
    
    
    glBegin(GL_POLYGON);//draw back wing
    glColor3f(1.0,0.3,0.0);
    glVertex2f(0.0,55.0);
    glVertex2f(0.0,80.0);
    glVertex2f(10.0,80.0);
    glVertex2f(40.0,55.0);
    glEnd();
    
    
    
    
    
    glBegin(GL_POLYGON); //draw rightside wing
    glColor3f(1.0,0.3,0.0);
    glVertex2f(65.0,55.0);
    glVertex2f(50.0,70.0);
    glVertex2f(75.0,70.0);
    glVertex2f(90.0,55.0);
    glEnd();
    
    
    
    glBegin(GL_POLYGON); //draw leftside wing
    glColor3f(1.0,0.3,0.0);
    
    glVertex2f(70.0,40.0);
    glVertex2f(100.0,40.0);
    glVertex2f(80.0,15.0);
    glVertex2f(50.0,15.0);
    glEnd();
    
    glPopMatrix();
    glPopMatrix();
    
    draw_circle(300, 360, 2.5);
    draw_circle(250, 340, 2.7);
    draw_circle(200, 350, 2.9);
    draw_circle(150, 330, 3.2);
    draw_circle(100, 350, 2);
    draw_circle(50, 330, 3.2);
    draw_circle(10, 310, 2.8);
    draw_circle(310, 360, 30);
    
    drawcloud();
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}
void keyboard(GLubyte key, int x, int y) // For keyboard interactive
{
    switch ( key )
    {
        case 'd':
            xt += 2.0;
            glColor3f(0.0,1.0,0.0);
            glutPostRedisplay();
            break;
            
        case 'a':
            xt -= 2.0;
            glColor3f(1.0,0.0,0.0);
            glutPostRedisplay();
            break;
            
        case 's':
            yt -= 2.0;
            glColor3f(0.0,0.0,0.0);
            glutPostRedisplay();
            break;
            
        case 'w':
            yt += 2.0;
            glColor3f(0.0,0.0,1.0);
            glutPostRedisplay();
            break;
            
        case 'e':
            xt += 2.0;
            yt += 2.0;
            glColor3f(1.0,0.0,1.0);
            glutPostRedisplay();
            break;
            
        case 'q':
            xt -= 2.0;
            yt += 2.0;
            glColor3f(0.0,1.0,1.0);
            glutPostRedisplay();
            break;
        case 'c':
            xt += 2.0;
            yt -= 2.0;
            glColor3f(1.0,0.0,1.0);
            glutPostRedisplay();
            break;
        case 'z':
            xt -= 2.0;
            yt -= 2.0;
            glColor3f(0.0,0.0,1.0);
            glutPostRedisplay();
            break;
            
        default:
            break;
    }
}
int main(int a,char ** b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(200,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("2018CSC1043");
    init();
    glutDisplayFunc(Display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
