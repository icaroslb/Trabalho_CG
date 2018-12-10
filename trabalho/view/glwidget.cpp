#include "glwidget.h"
#include <iostream>


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{}

void GLWidget::initializeGL(){
    canvasHeith = 300;
    canvasWidth = 300;
    glOrtho(-(canvasWidth/2), (canvasWidth/2), -(canvasHeith/2), (canvasHeith/2), -1, 1);
    ray = new rayCast(300, 300, this->width(), this->height(), 10);
}

void GLWidget::resizeGL(int w, int h){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    if (h == 0) h = 1;
    if (w == 0) w = 1;

    glViewport(0,0,w,h);
    ray->mudarDimencoes(w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

void GLWidget::paintGL(){
    Vetor *corPintar;
    int tamW = this->width(), tamH = this->height();

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for(int i = 0; i < tamW; i++){
        for(int j = 0; j < tamH; j++){
            corPintar = ray->obterCor(i, j);
            glBegin(GL_POINTS);
                glPointSize(tamW/canvasWidth);
            //if(corPintar != NULL)
                glColor3d(*(*corPintar)[X], *(*corPintar)[Y], *(*corPintar)[Z]);
            //else
                //glColor3f(0, 0, 0);

                glVertex3f(i-150,j-150,0.0);
            glEnd();
        }
    }
}

void GLWidget::mudarCanvas(int novaLargura, int novaAltura){
    canvasWidth = novaLargura;
    canvasHeith = novaAltura;
    glOrtho(-(canvasWidth/2), (canvasWidth/2), -(canvasHeith/2), (canvasHeith/2), -1, 1);
    this->repaint();
}
