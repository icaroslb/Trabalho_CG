#include "pintar.h"
#include "../controler/raycast.h"

pintar::pintar(QWidget *parent) : QGLWidget (parent)
{
    ray = new rayCast(250, 250, this->width(), this->height(), 1);
    larguraTam = this->width();
    alturaTam = this->height();

    larguraResol = 250;
    alturaResol = 250;

    larguraPix = larguraTam/larguraResol;
    alturaPix = alturaTam/alturaResol;
}

void pintar::initializeGL(){}

void pintar::reziseGL(int w, int h){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    if (h == 0) h = 1;
    if (w == 0) w = 1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

void pintar::paintGL(){
    double *corPintar;

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    /*for(int i = 0; i < larguraTam; i++){
        for(int j = 0; j < alturaTam; j++){
            corPintar = ray->obterCor(i, j);
            glBegin(GL_POINT);
                glColor3f(1, 1, 1);
                glVertex3f(i,j,0);
            glEnd();
        }
    }*/

    glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
        glVertex3f( 0.0, 0.5,0.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-0.5,-0.5,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f( 0.5,-0.5,0.0);
    glEnd();
}
