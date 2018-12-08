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

signals:

public slots:
};

#endif // GLWIDGET_H
