#ifndef PINTAR_H
#define PINTAR_H

#include <QWidget>

namespace Ui {
class pintar;
}

class pintar : public QWidget
{
    Q_OBJECT

public:
    explicit pintar(QWidget *parent = nullptr);
    ~pintar();

private:
    Ui::pintar *ui;
};

#endif // PINTAR_H
