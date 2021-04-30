## Computer Graphics End Term Practical Examination (Special Assignment)
<hr>

<B> Name - Chetan Khanna </b>  
<b>Roll no. - 2018CSC1043 </b>     
<b>Set - A</b>  
<b>Exam Roll no. - 18068570028</b>
<hr>

### Design and Render a scene to showcase a moving AEROPLANE. The Aeroplane should move up and down on Keyboard control events.  

<br>
<br>

The file <B>``` plane.cpp```</b> has the solution code for the above problem.

<B>```The size of the window is 500x500.```</B>


<br>

This draw_circle() is used to make moon and stars.

```cpp
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
```
The drawcloud() is used to make clouds.
    
```cpp
void drawcloud()
    {
    glPushMatrix();
    glColor3f(1,1,1);
    glScalef(0.3, 0.3, 0);
    glTranslated(120, 0, 0);
    DrawCircle(600,800,60,1000);
    DrawCircle(530,800,40,1000);
    DrawCircle(670,800,40,1000);
    DrawCircle(200,800,45,1000);
    DrawCircle(150,800,30,1000);
    DrawCircle(250,800,30,1000);
    glPopMatrix();
    }
```

This routine uses a helper sub-routine DrawCircle().

    
```cpp
void DrawCircle(float cirx, float ciry, float r, int num_segments)
    {
    glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)
    {
    float theta = 2.0f * 3.1415926f * float(ii) / float (num_segments);

    float x = r * cosf(theta);
    float y = r * sinf(theta);

    glVertex2f(x + cirx, y + ciry);

    }
    glEnd();
    }
```



>   

> We use function Display() to render items onto the screen. This funnction also contains the code to draw an airplane.
<br> 
We use runway() function to draw runway road.




### Press the following keys : 

* 'a' - move towards left
* 's' - move towards bottom
* 'd' - move towards right
* 'w' - move towards top
* 'q' - move towards top-left
* 'e' - move towards top-right
* 'c' - move towards bottom-right
* 'z' - move towards bottom-left


<br>


### Output screenshots -


<img src ="ss1.png" width=400/>
<br>
<img src ="ss2.png"  width=400/>
<br>
<img src ="ss3.png"  width=400/>
<img src ="ss4.png"  width=400/>
<br>
<br>

### <a href = 'https://drive.google.com/file/d/1VBteqdFyThrCQ0D7T3M-kG-KEt0xZ61X/view?usp=sharing' >Link to the video explaining the code</a>

<br>


### <a href = 'https://drive.google.com/file/d/1-Pscw-ezsfP8jwuVqILb_4IObFpX8JBa/view?usp=sharing'> Link to the Output GIF</a>

<div style="page-break-after: always;"></div>

<br>

## ```Final Code : ``` 

```cpp
// made by Chetan Khanna
// Program to Design and Render a scene to showcase a moving AEROPLANE. 
// The Aeroplane should move up and down on Keyboard control events.

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


```


### <a href = 'https://github.com/chetan767/Computer_Graphics_Airplane' >Link to the Github  Repository</a>
<br>

### Answer the following viva-based questions:
 a)	Why must you remove objects that are outside the view volume?

    Objects outside this volume will not be visible in the final image, so they are discarded. This surface is called the hidden surface. We remove these parts to create a more realistic image.

b)	Suppose that you have 100 triangles that can be arranged into a triangle strip. How many vertices would you have to specify to OpenGL if you use the fact that they can be arranged into a triangle strip? 


	The number of vertices stored in memory is reduced from 3N to N+2 in case of a triangle strip, where N is the number of triangles to be drawn. Here, N is 100. Hence, we would have to specify 102 vertices.

 c)	Why do we consider colour to have three dimensions, such as RGB? There are an infinite number of visible wavelengths.

    Red, Blue and Green are the primary colours of light and they correspond to the peak sensitivities of the colour receptor cells in the retina of our eyes. Light itself has no colour - it only has a wavelength. Different wavelengths trigger different responses in the eye’s colour receptors, and the brain processes the responses and perceives it as colour.

<div style="page-break-after: always;"></div>

  d) Processing objects 1-by-1 with a graphics pipeline has a major advantage and also a major disadvantage. Name them. 
  

    Advantage – Objects can be processed parallelly which enhances the speed drastically.
       
    Disadvantage – Objects in graphics pipeline who can’t interact with each other.

 e)	What is the event loop?

    In the system, the event loop waits for an event, such as user input or a graphics state change (like window resize), then calls a user-defined callback function (if provided), which returns to the event loop to wait for the next event.