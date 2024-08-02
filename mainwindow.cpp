#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Establecer un tamaño fijo para la ventana
    setFixedSize(455, 530); // Tamaño fijo de 800x600 píxeles
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_boton0_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "0");
}

void MainWindow::on_boton1_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "1");
}

void MainWindow::on_boton2_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "2");
}

void MainWindow::on_boton3_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "3");
}

void MainWindow::on_boton4_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "4");
}

void MainWindow::on_boton5_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "5");
}

void MainWindow::on_boton6_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "6");
}

void MainWindow::on_boton7_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "7");
}

void MainWindow::on_boton8_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "8");
}

void MainWindow::on_boton9_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + "9");
}

void MainWindow::on_coma_clicked()
{
    ui->calc_Line_Edit->setText(ui->calc_Line_Edit->text() + ",");
}

void MainWindow::on_clear_button_clicked()
{
    ui->calc_Line_Edit->clear();
    ui->operador->clear();
    this->operador.clear();
}


void MainWindow::on_suma_clicked()
{
    this->operador = "+";
    // Convertir QString a std::string
    std::string str = ui->calc_Line_Edit->text().toStdString();
    // Convertir std::string a long double usando std::stold
    this->operando1 = std::stold(str);
    ui->operador->setText(ui->calc_Line_Edit->text() + " +");
    ui->calc_Line_Edit->clear();
}


void MainWindow::on_resta_clicked()
{
    this->operador = "-";
    std::string str = ui->calc_Line_Edit->text().toStdString();
    this->operando1 = std::stold(str);
    ui->operador->setText(ui->calc_Line_Edit->text() + " -");
    ui->calc_Line_Edit->clear();
}


void MainWindow::on_mul_clicked()
{
    this->operador = "*";
    std::string str = ui->calc_Line_Edit->text().toStdString();
    this->operando1 = std::stold(str);
    ui->operador->setText(ui->calc_Line_Edit->text() + " *");
    ui->calc_Line_Edit->clear();
}


void MainWindow::on_div_clicked()
{
    this->operador = "/";
    std::string str = ui->calc_Line_Edit->text().toStdString();
    this->operando1 = std::stold(str);
    ui->operador->setText(ui->calc_Line_Edit->text() + " /");
    ui->calc_Line_Edit->clear();
}

bool MainWindow::no_tiene_parte_decimal(long double& res){
    long double parteEntera;
    long double fractionalPart = std::modf(res, &parteEntera);
    // Compara si la parte fraccionaria es aproximadamente 0
    return std::fabs(fractionalPart) < 1e-10; // Usar una tolerancia para errores de precisión
}

void MainWindow::on_boton_igual_clicked()
{
    ui->operador->clear();
    std::string str = ui->calc_Line_Edit->text().toStdString();
    long double operando2 = std::stold(str);
    long double result;
    if (this->operador == "+"){
        result = this->operando1 + operando2;
        if (no_tiene_parte_decimal(result)){
            // Redondear y convertir a int
            int resultado_entero = std::llround(result);
            ui->calc_Line_Edit->setText(QString::number(resultado_entero));
        } else {
            ui->calc_Line_Edit->setText(QString::number(result, 'f', 10));
        }
        return;
    }
    if (this->operador == "-"){
        result = this->operando1 - operando2;
        if (no_tiene_parte_decimal(result)){
            // Redondear y convertir a int
            int resultado_entero = std::llround(result);
            ui->calc_Line_Edit->setText(QString::number(resultado_entero));
        } else {
            ui->calc_Line_Edit->setText(QString::number(result, 'f', 10));
        }
        return;
    }
    if (this->operador == "*"){
        result = this->operando1 * operando2;
        if (no_tiene_parte_decimal(result)){
            // Redondear y convertir a int
            int resultado_entero = std::llround(result);
            ui->calc_Line_Edit->setText(QString::number(resultado_entero));
        } else {
            ui->calc_Line_Edit->setText(QString::number(result, 'f', 10));
        }
        return;
    }
    if (this->operador == "/"){
        result = this->operando1 / operando2;
        if (no_tiene_parte_decimal(result)){
            // Redondear y convertir a int
            int resultado_entero = std::llround(result);
            ui->calc_Line_Edit->setText(QString::number(resultado_entero));
        } else {
            ui->calc_Line_Edit->setText(QString::number(result, 'f', 10));
        }
        return;
    }
}


