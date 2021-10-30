#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    ui->plot->replot(); //reploting
    QVector<double> x(101), y(101);
    for(int i=0; i<101; ++i) {
        x[i] = i/50.0-1;
        y[i] = 2*x[i]*x[i]-4*x[i];
    }


    ui->plot->addGraph();
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    ui->plot->graph(0)->setData(x,y); //z dokumentacji, testowy wykres
    ui->plot->graph(0)->rescaleAxes();
    ui->plot->replot();
}

void MainWindow::on_savePlotBtn_clicked()
{
    QString filename = "plot.png"; //dodac moze wzor do nazwy pliku idk
    QString outputDir = "C:/Users/Mirek/Desktop/pwr-calc"; //zmienic na dialog z wyborem miejsca zapisu
    ui->plot->savePng(outputDir+"/"+filename, 500, 400);
}

void MainWindow::on_sinPlotBtn_clicked()
{

    ui->trigPlot->replot(); //reploting
    QVector<double> x(251), y(251);
    for(int i=0; i<251; ++i) {
        x[i] = i;
        y[i] = qSin(i/10.0);
    }
    ui->trigPlot->addGraph();
    ui->trigPlot->xAxis->setLabel("x");
    ui->trigPlot->yAxis->setLabel("y");
    ui->trigPlot->graph(0)->setData(x,y);
    ui->trigPlot->graph(0)->rescaleAxes();
    ui->trigPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->trigPlot->replot();
}


void MainWindow::on_cosPlotBtn_clicked()
{
   //clearing graph before plotting
    ui->trigPlot->replot(); //reploting
    QVector<double> x(101), y(101);
    for(int i=0; i<101; ++i) {
        x[i] = i;
        y[i] = qCos(i/10.0);
    }
    ui->trigPlot->addGraph();
    ui->trigPlot->xAxis->setLabel("pi");
    ui->trigPlot->yAxis->setLabel("value");
    ui->trigPlot->graph(0)->setData(x,y);
    ui->trigPlot->graph(0)->rescaleAxes();
    ui->trigPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->trigPlot->replot();
}


void MainWindow::on_clrPlotBtn_clicked()
{
    if((ui->trigPlot->graph(0))!=0) { //graph() zwraca 0 jezeli nie ma o zadanym indeksie, walidacja bledow
        ui->trigPlot->graph(0)->data()->clear();
        ui->trigPlot->replot();
    }

}


void MainWindow::on_tanPlotBtn_clicked()
{
    ui->trigPlot->graph(0)->data()->clear(); //clearing graph before plotting
    ui->trigPlot->replot(); //reploting
    QVector<double> x(101), y(101);
    for(int i=0; i<101; ++i) {
        x[i] = i;
        y[i] = qTan(i/10.0);
    }
    ui->trigPlot->addGraph();
    ui->trigPlot->xAxis->setLabel("pi");
    ui->trigPlot->yAxis->setLabel("value");
    ui->trigPlot->graph(0)->setData(x,y);
    ui->trigPlot->graph(0)->rescaleAxes();
    ui->trigPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->trigPlot->replot();
}


