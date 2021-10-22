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

void MainWindow::on_fxCalculateBtn_clicked()
{
    double a = ui->aFxSpinBox->value();
    double b = ui->bFxSpinBox->value();
    double c = ui->cFxSpinBox->value();
    double delta = (qPow(b,2) - (4*a*c));
    if(delta>0) {
        double x1 = (((-1)*b-qSqrt(delta))/(2*a));
        double x2 = (((-1)*b+qSqrt(delta))/(2*a));
        QString x1label = QString::number(x1, 'f', 3);
        QString x2label = QString::number(x2, 'f', 3);
        ui->fxX1Label->setText(x1label);
        ui->fxX2Label->setText(x2label);
    }
    else if(delta==0) {
        double x0 = (((-1)*b)/(2*a));
        QString x0label = QString::number(x0, 'f', 3);
        ui->fxX1Label->setText(x0label);
        ui->fxX2Label->setText(NULL);
    }
    else {
        ui->fxX1Label->setText("Brak miejsc zerowych f(x)");
        ui->fxX2Label->setText(NULL);
    }
}


void MainWindow::on_calculateVectorBtn_clicked()
{
    double Xa = ui->spinBoxXa->value();
    double Ya = ui->spinBoxYa->value();
    double Xb = ui->spinBoxXb->value();
    double Yb = ui->spinBoxYb->value();
    double vectorLength = qSqrt(qPow(Xb-Xa, 2)+qPow(Yb-Ya, 2)); //z libki qtmath
    QString labelVectorLength = QString::number(vectorLength, 'f', 3);
    ui->labelVectorLength->setText(labelVectorLength);
}


void MainWindow::on_generatePlotBtn_clicked()
{
    QVector<double> x(101), y(101);
    for(int i=0; i<101; ++i) {
        x[i] = i/50.0-1;
        y[i] = x[i]*x[i];
    }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y); //z dokumentacji, testowy wykres
    double axisRange = ui->axisSpinBox->value();
    ui->plot->xAxis->setRange(-1,1);
    ui->plot->yAxis->setRange(0,axisRange);
    ui->plot->replot();
}


void MainWindow::on_savePlotBtn_clicked()
{
    QString filename = "plot.png"; //dodac moze wzor do nazwy pliku idk
    QString outputDir = "C:/Users/Mirek/Desktop/pwr-calc"; //zmienic na dialog z wyborem miejsca zapisu
    ui->plot->savePng(outputDir+"/"+filename, 500, 400);
}

