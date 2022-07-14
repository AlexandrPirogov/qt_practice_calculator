#include "calculator.h"

Calculator::Calculator() : QWidget()
{
    firstNum = "";
    secondNum = "";
    currentOperation = "";
    verticalLayout = new QVBoxLayout();
    gridLayout = new QGridLayout();
    lineEdit = new QLineEdit();
    lineEdit->setAlignment(Qt::AlignRight);
    lineEdit->resize(50,100);
    lineEdit->setFont(QFont("Times", 20, QFont::Bold));
    lineEdit->resize(50,50);
    lineEdit->setReadOnly(true);
    verticalLayout->addWidget(lineEdit);


    numberBtns[0] = new QPushButton(QString::number(1));
    gridLayout->addWidget(numberBtns[0], 0,0);
    numberBtns[1] = new QPushButton(QString::number(2));
    gridLayout->addWidget(numberBtns[1], 0,1);
    numberBtns[2] = new QPushButton(QString::number(3));
    gridLayout->addWidget(numberBtns[2], 0,2);
    numberBtns[3] = new QPushButton(QString::number(4));
    gridLayout->addWidget(numberBtns[3], 1,0);
    numberBtns[4] = new QPushButton(QString::number(5));
    gridLayout->addWidget(numberBtns[4], 1,1);
    numberBtns[5] = new QPushButton(QString::number(6));
    gridLayout->addWidget(numberBtns[5], 1,2);
    numberBtns[6] = new QPushButton(QString::number(7));
    gridLayout->addWidget(numberBtns[6], 2,0);
    numberBtns[7] = new QPushButton(QString::number(8));
    gridLayout->addWidget(numberBtns[7], 2,1);
    numberBtns[8] = new QPushButton(QString::number(9));
    gridLayout->addWidget(numberBtns[8], 2,2);

    numberBtns[9] = new QPushButton("+");
    gridLayout->addWidget(numberBtns[9], 0,3);
    connect(numberBtns[9], SIGNAL(clicked()), SLOT(slotClickedOperation()));
    numberBtns[9]->resize(75,75);
    numberBtns[9]->setFont(QFont("Times", 20, QFont::Bold));

    numberBtns[10] = new QPushButton("-");
    gridLayout->addWidget(numberBtns[10], 1,3);
    connect(numberBtns[10], SIGNAL(clicked()), SLOT(slotClickedOperation()));
    numberBtns[10]->resize(75,75);
    numberBtns[10]->setFont(QFont("Times", 20, QFont::Bold));

    numberBtns[11] = new QPushButton("*");
    gridLayout->addWidget(numberBtns[11], 2,3);
    connect(numberBtns[11], SIGNAL(clicked()), SLOT(slotClickedOperation()));
    numberBtns[11]->resize(75,75);
    numberBtns[11]->setFont(QFont("Times", 20, QFont::Bold));

    numberBtns[12] = new QPushButton("/");
    gridLayout->addWidget(numberBtns[12], 3,3);
    connect(numberBtns[12], SIGNAL(clicked()), SLOT(slotClickedOperation()));
    numberBtns[12]->resize(75,75);
    numberBtns[12]->setFont(QFont("Times", 20, QFont::Bold));

    numberBtns[13] = new QPushButton("=");
    gridLayout->addWidget(numberBtns[13], 4,3);
    connect(numberBtns[13], SIGNAL(clicked()), SLOT(slotClickedCalculate()));
    numberBtns[13]->resize(75,75);
    numberBtns[13]->setFont(QFont("Times", 20, QFont::Bold));

    numberBtns[14] = new QPushButton(".");
    gridLayout->addWidget(numberBtns[14], 4,0);
        connect(numberBtns[14], SIGNAL(clicked()), SLOT(slotClickedNumberBtn()));
    numberBtns[14]->resize(75,75);
    numberBtns[14]->setFont(QFont("Times", 20, QFont::Bold));

    for(int i = 0; i < 9; i++)
    {
        numberBtns[i]->setStyleSheet("color: black;"
                                     "background-color: #F5EEEE;"
                                     "selection-color: blue;"
                                     "selection-background-color: blue;");
        numberBtns[i]->resize(75,75);
        numberBtns[i]->setFont(QFont("Times", 20, QFont::Bold));
        connect(numberBtns[i], SIGNAL(clicked()), SLOT(slotClickedNumberBtn()));
    }
    numberBtns[15] = new QPushButton("CE");
    gridLayout->addWidget(numberBtns[15], 4,1);
    connect(numberBtns[15], SIGNAL(clicked()), SLOT(slotClickedClearBtn()));
    numberBtns[15]->resize(75,75);
    numberBtns[15]->setFont(QFont("Times", 20, QFont::Bold));

    verticalLayout->addLayout(gridLayout,1);
    this->setLayout(verticalLayout);
    this->resize(500,500);
};

 void Calculator::slotClickedNumberBtn()
 {
    QString str = ((QPushButton*)sender())->text();
    if(!isSecond)
    {
        firstNum.append(str);
        lineEdit->setText(firstNum);
    } else
    {
        secondNum.append(str);
        lineEdit->setText(secondNum);
    };
 };

 void Calculator::slotClickedOperation()
 {
    QString str = ((QPushButton*)sender())->text();
    lineEdit->setText(str);
    currentOperation = str;
    isSecond = true;
 };

 void Calculator::slotClickedCalculate()
 {
      if(currentOperation == "+")
      {
          lineEdit->setText(QString::number(firstNum.toDouble() + secondNum.toDouble()));
      } else if (currentOperation == "-")
      {
           lineEdit->setText(QString::number(firstNum.toDouble() - secondNum.toDouble()));
      } else if (currentOperation == "*")
      {
           lineEdit->setText(QString::number(firstNum.toDouble() * secondNum.toDouble()));
      } else {
           lineEdit->setText(QString::number(firstNum.toDouble() / secondNum.toDouble()));
      }
      firstNum = "";
      secondNum = "";
      currentOperation = "";
      isSecond = false;
 };

 void Calculator::slotClickedClearBtn()
 {
     firstNum = "";
     secondNum = "";
     currentOperation = "";
     isSecond = false;
     lineEdit->setText(0);
 };
