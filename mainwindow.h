/*
*==========================
* Inlämnings_uppgift_del5
* Kalkylatorn
* Kursprogram i C++
* Handledare: Gladyz Pabon
* Datum:  2018-03-09
* @auktor: Amer Ahmed
*==========================
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    // ======================================
    // Funktionersdefinierar här
    // =======================================
    void digit_pressed();
    void on_pushButton_decimal_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equals_released();
    void binary_operation_pressed();
};
#endif // MAINWINDOW_H
