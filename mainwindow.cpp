#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plot->addGraph();
    ui->plot->xAxis->setLabel("x"); //generowanie osi x,y w konstruktorze
    ui->plot->yAxis->setLabel("y");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::calculateVectorBtn()
{
    double Xa = ui->spinBoxXa->value();
    double Ya = ui->spinBoxYa->value();
    double Xb = ui->spinBoxXb->value();
    double Yb = ui->spinBoxYb->value();
    double vectorLength = qSqrt(qPow(Xb-Xa, 2)+qPow(Yb-Ya, 2)); //z libki qtmath
    QString labelVectorLength = QString::number(vectorLength, 'f', 3);
    ui->labelVectorLength->setText(labelVectorLength);
}



void MainWindow::generatePlotBtn()
{
    QVector<double> x(101), y(101);
    for(int i=0; i<101; ++i) {
        x[i] = i/50.0-1;
        y[i] = x[i]*x[i];
    }
    //ui->plot->addGraph(); idk czy tu tez musze dodawac, w razie czego jest replot()
    ui->plot->graph(0)->setData(x,y); //z dokumentacji, testowy wykres
    double axisRange = ui->axisSpinBox->value();
    ui->plot->xAxis->setRange(-1,1);
    ui->plot->yAxis->setRange(0,axisRange);
    ui->plot->replot();
}


void MainWindow::savePlotBtn()
{
    QString filename = "plot.png"; //dodac moze wzor do nazwy pliku idk
    QString outputDir = "C:/Users/Mirek/Desktop/pwr-calc"; //zmienic na dialog z wyborem miejsca zapisu
    ui->plot->savePng(outputDir+"/"+filename, 500, 400);
}

