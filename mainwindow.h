#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMath>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fxCalculateBtn_clicked();

    void on_calculateVectorBtn_clicked();

    void on_generatePlotBtn_clicked();

    void on_savePlotBtn_clicked();

    void on_sinPlotBtn_clicked();

    void on_cosPlotBtn_clicked();

    void on_clrPlotBtn_clicked();

    void on_tanPlotBtn_clicked();



    void on_actionO_programie_triggered();

    void on_actionZamknij_triggered();

    void on_clrFxPlotBtn_clicked();

    void on_sinSpinBox_valueChanged(double arg1);

    void on_cosSpinBox_valueChanged(double arg1);

    void on_tanSpinBox_valueChanged(double arg1);

    void on_arccosSpinBox_valueChanged(double arg1);

    void on_arctanSpinBox_valueChanged(double arg1);

    void on_arcsinSpinBox_valueChanged(double arg1);

    void on_circleSpinBox_valueChanged(double arg1);

    void on_pushButton_clicked();


    void on_squareCheckbox_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_aRectangleSpinBox_valueChanged(double arg1);

    void on_degSpinBox_valueChanged(double arg1);

    void on_radSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
