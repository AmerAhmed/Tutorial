/*
*===========================
* Inlämnings_uppgift_del5
* kalkylatorn
* Kursprogram i C++
* Handledare: Gladyz Pabon
* Datum:  2018-03-09
* @auktor: Amer Ahmed
*===========================
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

// =====================
// Glabla variabler
// =====================
double  firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

  ui->setupUi(this);
  // ==================================
  // Här är alla pushButtton från 0-9
  // ==================================
 connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
 connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));
 // ==================================================================
 // Här är plusMinus och percent  pushButton med deras funktioner
 // ==================================================================
 connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
 connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
  // =======================================================================
 // Här är add,subtract,multiply och dividepushButton med deras funktioner
 // ========================================================================
 connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
 connect(ui->pushButton_subtract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
 connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
 connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
  // ==========================================
 // Här Sättar de till sant ( true)
 // ===========================================
 ui->pushButton_add->setCheckable(true);
 ui->pushButton_subtract->setCheckable(true);
 ui->pushButton_multiply->setCheckable(true);
 ui->pushButton_divide->setCheckable(true);

}
// =========================
// MainWindow: Funktion
// =========================
MainWindow::~MainWindow()
{
    // ta bort efter sig
    delete ui;

}
// ==============================
// Funktion för digit-pressed
// ===============================
void MainWindow::digit_pressed()
{
    // ==============
    // Sändare
    // ==============
   QPushButton * button = (QPushButton*)sender();

   // ==============
   // två variabler
   // ===============
   double labelNumber;
   QString newlabel;

   // ==============================================
   // Kontrollera dem med två operativer eller
   // ===============================================
   if((ui->pushButton_add->isChecked() || ui->pushButton_subtract->isChecked() ||
    ui->pushButton_multiply->isChecked() || ui->pushButton_divide->isChecked()) &&
    (!userIsTypingSecondNumber))
   {
      labelNumber = button->text().toDouble();

      // sätter till sant
      userIsTypingSecondNumber = true;

       // 'g' är samma som char och 15 står antal siffor på kalkylatorn
      newlabel = QString::number(labelNumber,'g',15);

   }
   else
   {
       if(ui->label->text().contains('.') && button->text() == "0")
       {
           newlabel = ui->label->text() + button->text();
       }
       else
       {
          labelNumber =(ui->label->text() + button->text()).toDouble();
          newlabel = QString::number(labelNumber,'g',15);
       }
   }
   ui->label->setText(newlabel);
}
void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}
void MainWindow::unary_operation_pressed()
{
   QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newlabel;

    if(button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
    }

    if(button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{
   // Sättar alla dem till falska
  ui->pushButton_add->setChecked(false);
  ui->pushButton_subtract->setChecked(false);
  ui->pushButton_multiply->setChecked(false);
  ui->pushButton_divide->setChecked(false);
  userIsTypingSecondNumber = false;

   // label text lika med 0
  ui->label->setText("0");

}
void MainWindow::on_pushButton_equals_released()
{

    double labelNumber, secondNum;
    QString newlabel;

    secondNum = ui->label->text().toDouble();

    // ============================================
    // Här kontrollera dem  med if satser
    // ============================================
    if(ui->pushButton_add->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_add->setChecked(false);
    }
    else if(ui->pushButton_subtract->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_subtract->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_divide->setChecked(false);
    }
    // När användaren skriver andra tal är falska
    userIsTypingSecondNumber = false;
}
// Funktion:för operation
void MainWindow::binary_operation_pressed()
{
   QPushButton * button = (QPushButton*)sender();

   firstNum = ui->label->text().toDouble();

   // button->setChecked är sant
   button->setChecked(true);

}
