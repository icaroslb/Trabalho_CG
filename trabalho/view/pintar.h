#ifndef PINTAR_H
#define PINTAR_H

#include <QGLWidget>
#include "../controler/raycast.h"

class pintar : public QGLWidget
{
private:
    int larguraResol, alturaResol, larguraTam, alturaTam;
    double larguraPix, alturaPix;
    rayCast *ray;

public:
    pintar(QWidget *parent);

    void initializeGL();
    void reziseGL(int w, int h);
    void paintGL();
};

#endif // PINTAR_H
