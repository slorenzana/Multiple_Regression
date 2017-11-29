#include "regre_multi.h"
#include "ui_regre_multi.h"
#include <cmath>
#include "QDoubleSpinBox"

Regre_Multi::Regre_Multi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Regre_Multi)
{
    ui->setupUi(this);
    /*First we make the conections of the program with the GUI*/
    connect(ui->Calcular,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

void Regre_Multi::metodo(){
    QString temp, temp1, temp2, temp3, temp4, temp5;
            double X1=ui->x1->value();
            double X2=ui->x2->value();
            double X3=ui->x3->value();
            double X4=ui->x4->value();
            double X5=ui->x5->value();
            double X6=ui->x6->value();
            double X8=ui->x8->value();
            double X9=ui->x9->value();
            double X10=ui->x10->value();
            double X11=ui->x11->value();
            double X12=ui->x12->value();
            double X13=ui->x13->value();
            double F1=ui->f1->value();
            double F2=ui->f2->value();
            double F3=ui->f3->value();
            double F4=ui->f4->value();
            double F5=ui->f5->value();
            double F6=ui->f6->value();
    int i, n=6, x, j;
            double sumaX1=0,sumaX2=0, sumaY=0, productoXY=0, productoX1X2=0;
            double productoX2Y=0, suma_cuadrado_X1=0, suma_cuadrado_X2=0, suma_cuadrado_y=0, mediaX=0, mediaY=0;
    int a2=0, a1=0, a0=0;
            double r=0, mul, Sr=0, St=0, m=0, l=0;
    A[0]=X1;A[1]=X2;A[2]=X3; A[3]=X4; A[4]=X5; A[5]=X6;
    B[0]=F1;B[1]=F2;B[2]=F3; B[3]=F4; B[4]=F5; B[5]=F6;
    C[0]=X8;C[1]=X9;C[2]=X10;C[3]=X11;C[4]=X12;C[5]=X13;
    /*This For´ll calculate the sums fuctions that are needed*/
    for(i=0;i<6;i++){
                sumaX1=sumaX1+A[i];
                sumaX2=sumaX2+C[i];
                sumaY=sumaY+B[i];
                        productoXY=productoXY+(A[i]*B[i]);
                        productoX1X2=productoX1X2+(A[i]*C[i]);
                        productoX2Y=productoX2Y+(C[i]*B[i]);
                    suma_cuadrado_X1=suma_cuadrado_X1+(A[i]*A[i]);
                    suma_cuadrado_X2=suma_cuadrado_X2+(C[i]*C[i]);
                    suma_cuadrado_y=suma_cuadrado_y+(B[i]*B[i]);
                E[i]=0;
                F[i]=0;
             }
    mediaY=sumaY/n;
    /*In this part the matrix is fill*/
    D[0][0]=n;      D[0][1]=sumaX1;           D[0][2]=sumaX2;            D[0][3]=sumaY;
    D[1][0]=sumaX1; D[1][1]=suma_cuadrado_X1; D[1][2]=productoX1X2;      D[1][3]=productoXY;
    D[2][0]=sumaX2; D[2][1]=productoX1X2;     D[2][2]=suma_cuadrado_X2;  D[2][3]=productoX2Y;
    /*Then the metod is resolved*/
    for(i=1;i<3;i++){
        for (x=i;x<3;x++){
             mul=(D[x][i-1])/(D[i-1][i-1]);
                for(j=0;j<4;j++){
                     D[x][j]=(D[x][j]-((D[i-1][j])*mul));
                }
        }
    mul=0;
    }
  a2=(D[2][3]/D[2][2]);
  a1=(((D[1][3])-(D[1][2]*a2))/(D[1][1]));
  a0=((D[0][3])-(a2*D[0][2])-(a1*D[0][1]))/(D[0][0]);
      for (x=0;x<6;x++){
             E[x]=(B[x]-mediaY)*(B[x]-mediaY);
             F[x]=((B[x])-(a0)-(a1*A[x])-(a2*C[x]))*(B[x]-a0-(a1*A[x])-(a2*C[x]));
      }
      for (i=0;i<6;i++){
          St=St+E[i];
          Sr=Sr+F[i];
      }
        if(Sr==0){
        temp.append("\ny=").append(temp2.setNum(a0)).append("+(").append(temp3.setNum(a1)).append(")x1+(").append(temp4.setNum(a2)).append(")x2\nr=Infinito");
        }
    /*We corroborate that the value Sr, its correct*/
        if(Sr!=0){
            r=sqrt((St-Sr)/Sr);
            temp.append("\ny=").append(temp2.setNum(a0)).append("+").append(temp3.setNum(a1)).append("x1+").append(temp4.setNum(a2)).append("x2").append("\nr=").append(temp1.setNum(r));
        }
         ui->texto->setText(temp);
}
void Regre_Multi::borrar(){
    ui->x1->setValue(0.0);
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);
    ui->x8->setValue(0.0);
    ui->x9->setValue(0.0);
    ui->x10->setValue(0.0);
    ui->x11->setValue(0.0);
    ui->x12->setValue(0.0);
    ui->x13->setValue(0.0);
    ui->f1->setValue(0.0);
    ui->f2->setValue(0.0);
    ui->f3->setValue(0.0);
    ui->f4->setValue(0.0);
    ui->f5->setValue(0.0);
    ui->f6->setValue(0.0);
    ui->texto->clear();
}

Regre_Multi::~Regre_Multi()
{
    delete ui;
}
