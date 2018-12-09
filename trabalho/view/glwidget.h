#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mudarCanvas(int novaLargura, int novaAltura);

signals:

public slots:

private:
    int canvasWidth, canvasHeith;
};

#endif // GLWIDGET_H
