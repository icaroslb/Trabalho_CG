#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
  Q_OBJECT
  float tamW;
  float tamH;

public:
  explicit GLWidget(QWidget *parent = 0);

  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

private:

public slots:

};

#endif // GLWIDGET_H
