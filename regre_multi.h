#ifndef REGRE_MULTI_H
#define REGRE_MULTI_H

#include <QMainWindow>

namespace Ui {
class Regre_Multi;
}

class Regre_Multi : public QMainWindow
{
    Q_OBJECT

public:
    explicit Regre_Multi(QWidget *parent = 0);
    ~Regre_Multi();
    double D[3][4];
    double A[8], B[8], C[8], E[8], F[8];

public slots:
    void metodo();
    void borrar();

private:
    Ui::Regre_Multi *ui;
};

#endif // REGRE_MULTI_H
