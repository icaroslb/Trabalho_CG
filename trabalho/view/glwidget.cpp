#include "glwidget.h"
#include <iostream>


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{}

void GLWidget::initializeGL(){
    glOrtho(-150, 150, -150, 150, -1, 1);
}

void GLWidget::resizeGL(int w, int h){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    if (h == 0) h = 1;
    if (w == 0) w = 1;

    glViewport(0,0,w,h);
    std::cout << w << "   " << h << std::endl;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

void GLWidget::paintGL(){
    double *corPintar;
    int tamW = this->width(), tamH = this->height();

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for(int i = 0; i < tamW; i++){
        for(int j = 0; j < tamH; j++){
            //corPintar = ray->obterCor(i, j);
            glBegin(GL_POINTS);
                glColor3f(1, 0, 0);
                glVertex3f(i-150,j-150,0.0);
            glEnd();
        }
    }

    /*glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
        glVertex3f( 0.0, 1.0,0.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-1.0,-1.0,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(1.5,-1.0,0.0);
    glEnd();*/
}

/*pintar::~pintar(){
    delete ray;
}*/
