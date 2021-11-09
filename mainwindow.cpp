#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("dev compilation from 09-11-2021");
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
    if(a==0) {
        ui->fxX1Label->setText("Niepoprawna fx");
        ui->fxX2Label->setText(NULL);
    }
    else {
        double delta = (qPow(b,2) - (4*a*c));
        if(delta>0) {
            double x1 = (((-1)*b-qSqrt(delta))/(2*a));
            double x2 = (((-1)*b+qSqrt(delta))/(2*a));
            QString x1label = QString::number(x1, 'f', 3);
            x1label = "x1 = "+x1label;
            QString x2label = QString::number(x2, 'f', 3);
            x2label = "x2 = "+x2label;
            ui->fxX1Label->setText(x1label);
            ui->fxX2Label->setText(x2label);
        }
        else if(delta==0) {
            double x0 = (((-1)*b)/(2*a));
            QString x0label = QString::number(x0, 'f', 3);
            x0label = "x0 = "+x0label;
            ui->fxX1Label->setText(x0label);
            ui->fxX2Label->setText(NULL);
        }
        else {
            ui->fxX1Label->setText("Brak miejsc zerowych f(x)");
            ui->fxX2Label->setText(NULL);
        }
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
    ui->labelVectorLength->setText("|AB| = "+labelVectorLength);
}


void MainWindow::on_generatePlotBtn_clicked()
{

    //debug btns
//    double dbgA=ui->debugA->value();
//    double dbgB=ui->debugB->value();
//    double dbgC=ui->debugC->value();
//    double dbgXAxisFrom=ui->debugXAxisFrom->value();
//    double dbgXAxisTo=ui->debugXAxisTo->value();
//    double dbgYAxisFrom=ui->debugYAxisFrom->value();
//    double dbgYAxisTo=ui->debugYAxisTo->value();
//    double dbgDivider=ui->debugDivider->value();
    //end of debug btns
    //debbuing plot
    double a = ui->aFxSpinBox->value();
    double b = ui->bFxSpinBox->value();
    double c = ui->cFxSpinBox->value();
    ui->plot->replot();
    QVector<double> x(101), y(101);
    for(int i=0; i<101; ++i) {
        x[i] = i/50.0-1;
        y[i] = a*(x[i]*x[i])+b*x[i]+c;
    }


    ui->plot->addGraph();
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    ui->plot->graph(0)->setData(x,y); //z dokumentacji, testowy wykres
    //ui->plot->xAxis->setRange(dbgXAxisFrom,dbgXAxisTo);
    ui->plot->graph(0)->rescaleAxes(true);
    //ui->plot->graph(0)->rescaleAxes();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot->replot();
}

void MainWindow::on_savePlotBtn_clicked()
{
    QString outputDir = QFileDialog::getSaveFileName(this, tr("Zapisz plik"),"",tr("*.png"));
    ui->plot->savePng(outputDir, 500, 400);
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
    ui->trigPlot->graph(0)->data()->clear();
    ui->trigPlot->replot();
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



void MainWindow::on_actionO_programie_triggered()
{
    QMessageBox::information(this, "O programie","Wykonał: Mirosław Wierzbicki 262121");
}


void MainWindow::on_actionZamknij_triggered()
{
    QApplication::quit();
}


void MainWindow::on_clrFxPlotBtn_clicked()
{
    if((ui->plot->graph(0))!=0) { //graph() zwraca 0 jezeli nie ma o zadanym indeksie, walidacja bledow
        ui->plot->graph(0)->data()->clear();
        ui->plot->replot();
    }
}

//logika dla spin boxow dla sin cos tan i arc
void MainWindow::on_sinSpinBox_valueChanged(double arg1) //argument potrzebny ale nie uzywany
{
    double value = qSin(ui->sinSpinBox->value());
    ui->sinValue->setValue(value);
}


void MainWindow::on_cosSpinBox_valueChanged(double arg1)
{
    double value = qCos(ui->cosSpinBox->value());
    ui->cosValue->setValue(value);
}


void MainWindow::on_tanSpinBox_valueChanged(double arg1)
{
    double value = qTan(ui->tanSpinBox->value());
    ui->tanValue->setValue(value);
}

void MainWindow::on_arcsinSpinBox_valueChanged(double arg1)
{
    double value = qAsin(ui->arcsinSpinBox->value());
    ui->arcsinValue->setValue(value);
}


void MainWindow::on_arccosSpinBox_valueChanged(double arg1)
{
    double value = qAcos(ui->arccosSpinBox->value());
    ui->arccosValue->setValue(value);
}


void MainWindow::on_arctanSpinBox_valueChanged(double arg1)
{
    double value = qAtan(ui->arctanSpinBox->value());
    ui->arctanValue->setValue(value);
}

void MainWindow::on_circleSpinBox_valueChanged(double arg1)
{
    if(ui->doublePiCheckbox->isChecked()) {
        double value = ui->circleSpinBox->value()*ui->circleSpinBox->value()*3.14159265359;
        QString qvalue = QString::number(value, 'f', 7);
        ui->circleValue->setText("Pole = "+qvalue);
    }
    else {
        double value = ui->circleSpinBox->value()*ui->circleSpinBox->value()*3.14;
        QString qvalue = QString::number(value, 'f', 3);
        ui->circleValue->setText("Pole = "+qvalue);
    }
}


void MainWindow::on_pushButton_clicked()
{
    double a = ui->aTriangleSpinBox->value();
    double b = ui->bTriangleSpinBox->value();
    double c = ui->cTriangleSpinBox->value();
    double p = (a + b + c) / 2; //wzor Herona
    double s = qSqrt(p * (p-a) * (p-b) * (p-c)); //same
    QString value = QString::number(s, 'f', 7);
    if ((a+b>c) && (a+c>b) && (b+c>a)) {
        ui->triangleValue->setText("Pole =  "+value);
    }
    else {
        ui->triangleValue->setText("Nie można stworzyć takiego trójkąta!");
    }
}


void MainWindow::on_squareCheckbox_stateChanged(int arg1)
{
    double aVal = ui->aRectangleSpinBox->value();
    if(ui->bRectangleSpinBox->isEnabled()) {
        ui->bRectangleSpinBox->setDisabled(true);
        ui->bRectangleSpinBox->setValue(aVal);
    }

    else
        ui->bRectangleSpinBox->setDisabled(false);
}


void MainWindow::on_pushButton_2_clicked()
{
    double a = ui->aRectangleSpinBox->value();
    double b = ui->bRectangleSpinBox->value();
    double p = a*b;
    QString value = QString::number(p, 'f', 7);
    ui->rectangleValue->setText("Pole = "+value);
}


void MainWindow::on_aRectangleSpinBox_valueChanged(double arg1)
{
    if(!ui->bRectangleSpinBox->isEnabled()) {
        ui->bRectangleSpinBox->setValue(ui->aRectangleSpinBox->value());
    }
}

