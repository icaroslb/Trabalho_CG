#include "glwidget.h"
#include <iostream>


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    glOrtho(-300,300,-300,300,-1,1);
}

void GLWidget::initializeGL(){}

void GLWidget::reziseGL(int w, int h){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    if (h == 0) h = 1;
    if (w == 0) w = 1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

void GLWidget::paintGL(){
    double *corPintar;

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    std::cout << this->width() << std::endl;
    /*for(int i = 0; i < 300; i++){
        for(int j = 0; j < 300; j++){
            //corPintar = ray->obterCor(i, j);
            glBegin(GL_POINTS);
                glColor3f(1, 0, 0);
                glVertex3f(i,j,0.0);
            glEnd();
        }
    }*/

    glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
        glVertex3f( 0.0, 1.0,0.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-1.0,-1.0,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(1.5,-1.0,0.0);
    glEnd();
}

/*pintar::~pintar(){
    delete ray;
}*/
