#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_boton0_clicked();
    void on_boton1_clicked();
    void on_boton2_clicked();
    void on_boton3_clicked();
    void on_boton4_clicked();
    void on_boton5_clicked();
    void on_boton6_clicked();
    void on_boton7_clicked();
    void on_boton8_clicked();
    void on_boton9_clicked();
    void on_coma_clicked();

    void on_clear_button_clicked();

    void on_suma_clicked();
    void on_resta_clicked();
    void on_mul_clicked();
    void on_div_clicked();

    void on_boton_igual_clicked();

    bool no_tiene_parte_decimal(long double& res);

private:
    Ui::MainWindow *ui;
    long double operando1;
    QString operador;
};
#endif // MAINWINDOW_H
