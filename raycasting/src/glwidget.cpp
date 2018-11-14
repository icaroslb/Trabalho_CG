#include "headers/glwidget.h"
#include <iostream>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

/*---------------------------------------------------------------------------*
  Configura os recursos e estado do OpenGL. Deve ser chamado uma vez antes da
  primeira vez em que resizeGL() e paintGL() são chamados.
 *---------------------------------------------------------------------------*/
void GLWidget::initializeGL()
{
}

/*---------------------------------------------------------------------------*
  Configura o viewport, projeção, etc do OpenGL. Deve ser chamado sempre que
  o widget tem sido redimensionado (e também quando é mostrado pela primeira
  vez devido a todos os widgets criados recentemente obterem um evento de
  redimensionamento automaticamente).
 *---------------------------------------------------------------------------*/
void GLWidget::resizeGL(int w, int h)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
/*
    if (h == 0) h = 1;
    if (w == 0) w = 1;
    tamH = h;
    tamW = w;

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50./2, 50./2, -50./2, 50./2, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    */
    tamH = h;
    tamW = w;
    int wsize = w, hsize = h;
        if (h >= w)
        {
            hsize = w*H/W;
            glViewport(0, (h-hsize)/2, wsize, hsize);
        }
        else if (h < w)
        {
            wsize = h*W/H;
            glViewport((w-wsize)/2, 0,  wsize, hsize);
        }

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-W/2, W/2, -H/2, H/2, 1.0, 10.0);
        glMatrixMode(GL_MODELVIEW);

}

/*---------------------------------------------------------------------------*
  Renderiza a cena em OpenGL. Deve ser chamado sempre que o widget precisar
  ser atualizado.
 *---------------------------------------------------------------------------*/
void GLWidget::paintGL()
{
    double x, y, Dx, Dy;
    Dx = W/tamW;
    Dy = H/tamH;

    glClear (GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslated(0, 0, -2.5);
    glBegin(GL_POINTS);
    for (int l = 0; l < tamH; l++){
        y = H/2 - Dy/2 - l*Dy;
        for (int c = 0; c < tamW; c++){
            x = -W/2 + Dx/2 + c*Dx;
            glColor3f(1.0, 1.0, 0.0);
            glVertex2f(x, y);
        }
    }
    glEnd();
}
