#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "headers/vetor.h"
#include "headers/forma.h"
#include "headers/face.h"
#include "headers/vertice.h"
#include "headers/esfera.h"
#include "headers/objeto.h"
#include "parser.h"

class GLWidget : public QGLWidget
{
  Q_OBJECT
  float tamW;
  float tamH;
  float W = 50.;
  float H = 50.;
  std :: vector<Objeto> objetos;

public:
  explicit GLWidget(QWidget *parent = 0);

  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

private:

public slots:

};

#endif // GLWIDGET_H
