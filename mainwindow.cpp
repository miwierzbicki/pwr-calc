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


void MainWindow::on_pushButton_clicked()
{
    double Xa = ui->spinBoxXa->value();
    double Ya = ui->spinBoxYa->value();
    double Xb = ui->spinBoxXb->value();
    double Yb = ui->spinBoxYb->value();
    double vectorLength = qSqrt(qPow(Xb-Xa, 2)+qPow(Yb-Ya, 2)); //z libki qtmath
    QString labelVectorLength = QString::number(vectorLength, 'f', 3);
    ui->labelVectorLength->setText(labelVectorLength);
}

