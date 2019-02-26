#include <stdio.h>
#include <windows.h>
/*
ALAM,MD.RUBAYET 15-30024-2
ASADUZZAMAN, MD. 14-28097-3
CHOWDHURY,MD.REAZ UDDIN 14-28033-3
ISLAM MD.RAKIBUL 14-28045-3
*/
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <iostream>
#include <string.h>
using namespace std;

//bool* keyStates = new bool[256];

int height, width;
int window_width = 1350, window_height = 690;
int mx = window_width / 2 - width / 2, my = 10;
int r1x = rand() % window_width + 1, r1y = window_height;
int r2x = rand() % window_width + 1, r2y = window_height;
int r3x  = rand() % window_width + 1, r3y = window_height;
int r4x  = rand() % window_width + 1, r4y = window_height;

int mY, mminX, mmaxX, oY[4], ominX[4], omaxX[4];
int score = 0;

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1350, 0.0, 690.0);

}


void keyboard(unsigned char key, int x, int y)
{
    //GO LEFT
   // cout << my << endl;
    if(key == 'a')
    {

        mx -= 10;

    }
    else if(key == 'A')
    {
        mx -= 10;


    }

    //GO RIGHT
    else if(key == 'd')
    {
        mx += 10;

    }
    else if(key == 'D')
    {
        mx += 10;


    }
    //GO UP
    else if(key == 'w')
    {
        my += 10;

    }
    else if(key == 'w')
    {
        my += 10;

    }
    //GO DOWN
    else if(key == 's')
    {
        my -= 10;

    }
    else if(key == 'S')
    {
        my -= 10;

    }
    else if(key==27)
    {
        exit(0);
    }

    //plane staying in window

    if (mx < 65){

        mx = 65;
    }

    else if (mx > 1245){

        mx = 1245;
    }

    else if (my < 0){

        my = 0;

    }

    else if (my > 500){

        my = 500;
    }

    glutPostRedisplay();

}

void collision()
{
    for(int i = 0; i < 4; i++)
    {
        if(oY[i] <= mY)
        {
            if((mminX >= ominX[i] && mminX <= omaxX[i]) || (mmaxX >= ominX[i] && mmaxX <= omaxX[i]))

            {
                cout << "Your Score: " << score << endl;
                exit(0);

            }
        }
    }
//        game_over = 1;
}

void translate()
{
    r1y -= 5;
    r2y -= 6;
    r3y -= 8;
    r4y -= 4;
    if(r1y <= 0)
    {
        r1x = rand() % (window_width + 1);
        r1y = rand() % (window_height * 2) + window_height;
        score += 10;
    }
    if(r2y <= 0)
    {
        r2x = rand() % (window_width + 1);
        r2y = rand() % (window_height * 2) + window_height;
        score += 10;
    }
    if(r3y <= 0)
    {
        r3x = rand() % (window_width + 1);
        r3y = rand() % (window_height * 2) + window_height;
        score += 10;
    }
    if(r4y <= 0)
    {
        r4x = rand() % (window_width + 1);
        r4y = rand() % (window_height * 2) + window_height;
        score += 10;
    }
    collision();
    glutPostRedisplay();
    Sleep(40);
}
void backview()
{
    //background color
      glColor3ub(16,162,240);
      glBegin(GL_QUADS);
      glVertex2i(0,0);
      glVertex2i(0,690);
      glVertex2i(1350,690);
      glVertex2i(1350,0);
      glEnd();

      glFlush();
}
void myPlane()
{


///my plane///
    glColor3ub(0, 255, 0);//plane main body part
    glBegin(GL_QUADS);
    glVertex2i(mx, my+40);
    glVertex2i(mx + 40, my+40);
    glVertex2i(mx + 40, my + 140);
    glVertex2i(mx, my +140);
    glEnd();

    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS); //plane window part
    glVertex2i(mx+10, my+80);
    glVertex2i(mx + 30, my+80);
    glVertex2i(mx + 30, my + 120);
    glVertex2i(mx+10, my +120);
    glEnd();

    glColor3ub(225, 225, 225);
    glBegin(GL_QUADS); //plane left part
    glVertex2i(mx+40, my+80);
    glVertex2i(mx + 100, my+100);
    glVertex2i(mx + 100, my + 120);
    glVertex2i(mx+40, my +120);
    glEnd();

    glColor3ub(225, 225, 225);
    glBegin(GL_QUADS); //plane right part
    glVertex2i(mx+0, my+80);
    glVertex2i(mx - 60, my+100);
    glVertex2i(mx - 60, my + 120);
    glVertex2i(mx+0, my +120);
    glEnd();

    glColor3ub(0, 255, 0);
    glBegin(GL_TRIANGLES);//plane body uppuer part
    glVertex2i(mx, my+140);
    glVertex2i(mx + 40, my+140);
    glVertex2i(mx + 20, my + 170);
    glEnd();

    glColor3ub(43,85,108);
    glBegin(GL_QUADS);//plane front fan part
    glVertex2i(mx, my+168);
    glVertex2i(mx + 40, my+168);
    glVertex2i(mx + 40, my + 175);
    glVertex2i(mx , my + 175);
    glEnd();


    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);//plane body lower part
    glVertex2i(mx, my+40);
    glVertex2i(mx + 40, my+40);
    glVertex2i(mx + 25, my + 0);
    glVertex2i(mx +15, my + 0);
    glEnd();

    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);//plane body lower left part
    glVertex2i(mx, my+8);
    glVertex2i(mx + 12, my+10);
    glVertex2i(mx + 15, my + 0);
    glVertex2i(mx +3, my - 5);
    glEnd();

    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);//plane body lower right part
    glVertex2i(mx+37, my+8);
    glVertex2i(mx + 22, my+10);
    glVertex2i(mx +25, my + 0);
    glVertex2i(mx +34, my -5);
    glEnd();

    mY = my + 175;
    mminX = mx - 60;
    mmaxX = mx + 100;
    glFlush();

}


void oppo1()
{
///opponent 1st plane
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS); //opponent 1st plane main body
    glVertex2i(r1x, r1y);
    glVertex2i(r1x + 35, r1y);
    glVertex2i(r1x + 35, r1y + 120);
    glVertex2i(r1x, r1y + 120);
    glEnd();

    glBegin(GL_TRIANGLES); //opponent 1st plane upper body
    glVertex2i(r1x+10, r1y);
    glVertex2i(r1x + 25, r1y);
    glVertex2i(r1x + 17.5, r1y - 20);
    glEnd();

    glBegin(GL_TRIANGLES); //opponent 1st plane right body
    glVertex2i(r1x+35, r1y+35);
    glVertex2i(r1x + 35, r1y+100);
    glVertex2i(r1x + 110, r1y +100);
    glEnd();

    glBegin(GL_TRIANGLES); //opponent 1st plane left body
    glVertex2i(r1x+0, r1y+35);
    glVertex2i(r1x + 0, r1y+100);
    glVertex2i(r1x - 85, r1y + 100);
    glEnd();

    glBegin(GL_QUADS); //opponent 1st plane back left body
    glVertex2i(r1x -20, r1y+140);
    glVertex2i(r1x + 0, r1y+140);
    glVertex2i(r1x + 0, r1y + 110);
    glVertex2i(r1x -15, r1y + 125);
    glEnd();


    glBegin(GL_QUADS); //opponent 1st plane back left body
    glVertex2i(r1x +35, r1y+140);
    glVertex2i(r1x + 55, r1y+140);
    glVertex2i(r1x + 50, r1y + 125);
    glVertex2i(r1x +35, r1y + 110);
    glEnd();

    glBegin(GL_QUADS); //opponent 1st plane back left body
    glVertex2i(r1x +12, r1y+140);
    glVertex2i(r1x + 24, r1y+140);
    glVertex2i(r1x + 24, r1y + 120);
    glVertex2i(r1x +12, r1y + 120);
    glEnd();

    oY[0] = r1y -20;
    ominX[0] = r1x - 85;
    omaxX[0] = r1x + 110;

    glFlush();

}


void oppo2()
{
///opponent plane 2
    glColor3ub(255, 123, 0);
    glBegin(GL_QUADS);//opponent 2nd plane main body
    glVertex2i(r2x, r2y);
    glVertex2i(r2x + 40, r2y);
    glVertex2i(r2x + 40, r2y + 110);
    glVertex2i(r2x, r2y + 110);
    glEnd();

    glColor3ub(255, 123, 0);
    glBegin(GL_TRIANGLES);//opponent 2nd plane upper body
    glVertex2i(r2x, r2y);
    glVertex2i(r2x + 40, r2y);
    glVertex2i(r2x + 20, r2y -25);
    glEnd();

    glColor3ub(255, 123, 0);
    glBegin(GL_TRIANGLES);//opponent 2nd plane upper left body
    glVertex2i(r2x-30, r2y+30);
    glVertex2i(r2x , r2y+30);
    glVertex2i(r2x , r2y+10);
    glEnd();

    glColor3ub(255, 123, 0);
    glBegin(GL_TRIANGLES);//opponent 2nd plane upper right body
    glVertex2i(r2x+40, r2y+30);
    glVertex2i(r2x + 70, r2y+30);
    glVertex2i(r2x + 40, r2y+10);
    glEnd();

    glColor3ub(255, 123, 0);
    glBegin(GL_QUADS);//opponent 2nd plane lower left body
    glVertex2i(r2x-70, r2y+90);
    glVertex2i(r2x, r2y+110);
    glVertex2i(r2x , r2y + 30);
    glVertex2i(r2x -90, r2y + 30);
    glEnd();

    glColor3ub(255, 123, 0);
    glBegin(GL_QUADS);//opponent 2nd plane lower right body
    glVertex2i(r2x+40, r2y+110);
    glVertex2i(r2x + 110, r2y+90);
    glVertex2i(r2x + 130, r2y + 30);
    glVertex2i(r2x +40, r2y + 30);
    glEnd();

    glColor3ub(255, 123, 0);
    glBegin(GL_QUADS);//opponent 2nd plane main body
    glVertex2i(r2x+10, r2y+110);
    glVertex2i(r2x + 30, r2y+110);
    glVertex2i(r2x + 25, r2y + 125);
    glVertex2i(r2x +15, r2y + 125);
    glEnd();

    oY[1] = r2y - 25;
    ominX[1] = r2x - 90;
    omaxX[1]= r2x + 130;
    glFlush();
}

void score_add()
{
//    cout << "ok";
    string message = "SCORE: ";
    int x = 1100;
    int y = 600;
    glColor3ub(255, 255, 255);
    glRasterPos2i(x, y);
    int len = message.size();
    for(int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    char buffer[20];
    sprintf(buffer, "%d", score);
    len = strlen(buffer);
    for(int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
    }
    glFlush();
}

void oppo3()
{

///opponent plane 3
    glColor3ub(255, 0, 123);
    glBegin(GL_QUADS);//opponent 3rd plane main body
    glVertex2i(r3x, r3y+50);
    glVertex2i(r3x + 180, r3y+50);
    glVertex2i(r3x + 180, r3y );
    glVertex2i(r3x, r3y);
    glEnd();


    glBegin(GL_TRIANGLES);//opponent 3rd plane upper body
    glVertex2i(r3x+70, r3y+0);
    glVertex2i(r3x + 110, r3y+0);
    glVertex2i(r3x + 90, r3y-30);
    glEnd();

    glBegin(GL_TRIANGLES);//opponent 3rd plane lower body
    glVertex2i(r3x+50, r3y+40);
    glVertex2i(r3x + 130, r3y+40);
    glVertex2i(r3x + 90, r3y+180);
    glEnd();

    glBegin(GL_QUADS);//opponent 3rd plane left body
    glVertex2i(r3x+90, r3y+180);
    glVertex2i(r3x + 110, r3y+210);
    glVertex2i(r3x + 120, r3y+180 );
    glVertex2i(r3x+95, r3y+160);
    glEnd();

    glBegin(GL_QUADS);//opponent 3rd plane right body
    glVertex2i(r3x+90, r3y+180);
    glVertex2i(r3x + 70, r3y+210);
    glVertex2i(r3x + 60, r3y+180 );
    glVertex2i(r3x+85, r3y+160);
    glEnd();

    oY[2] = r3y - 30;
    ominX[2] = r3x;
    omaxX[2] = r3x + 180;
    glFlush();


}

void oppo4()
{

    //opponent 4th plane
    glColor3ub(255, 124, 123);
    glBegin(GL_QUADS);//opponent 4th plane main body
    glVertex2i(r4x, r4y+0);
    glVertex2i(r4x + 50, r4y);
    glVertex2i(r4x + 50, r4y + 140);
    glVertex2i(r4x, r4y + 140);
    glEnd();


    glColor3ub(255, 124, 123);
    glBegin(GL_QUADS);//opponent 4th plane upper body
    glVertex2i(r4x+0, r4y+0);
    glVertex2i(r4x + 50, r4y);
    glVertex2i(r4x + 40, r4y - 20);
    glVertex2i(r4x+10, r4y - 20);
    glEnd();

    glColor3ub(255, 124, 123);
    glBegin(GL_QUADS);//opponent 4th plane lower body
    glVertex2i(r4x+0, r4y+140 );
    glVertex2i(r4x + 50, r4y+140);
    glVertex2i(r4x + 60, r4y + 160);
    glVertex2i(r4x-10, r4y + 160);
    glEnd();

    glColor3ub(255, 124, 123);
    glBegin(GL_QUADS);//opponent 4th plane left body
    glVertex2i(r4x+50, r4y+40);
    glVertex2i(r4x + 100, r4y+40);
    glVertex2i(r4x + 100, r4y +80);
    glVertex2i(r4x+50, r4y +90);
    glEnd();


    glColor3ub(255, 124, 123);
    glBegin(GL_QUADS);//opponent 4th plane right body
    glVertex2i(r4x-50, r4y+80);
    glVertex2i(r4x + 0, r4y+90);
    glVertex2i(r4x + 0, r4y +40);
    glVertex2i(r4x-50, r4y +40);
    glEnd();

    oY[3] = r4y - 20;
    ominX[3] = r4x - 50;
    omaxX[3] = r4x + 100;
    glFlush();
}



void myDisplay()
{

    glClear (GL_COLOR_BUFFER_BIT);

    backview();

    myPlane();
    oppo1();
    oppo2();
    oppo3();
    oppo4();
    score_add();

    translate();
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1366, 690);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Air Crusher");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    myInit ();
    //srand(clock());
    glutMainLoop();
    return 0;
}
