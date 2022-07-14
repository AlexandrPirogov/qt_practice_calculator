#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <QtWidgets>

class Calculator : public QWidget
{
    Q_OBJECT
    QVBoxLayout* verticalLayout = nullptr;
    QGridLayout* gridLayout = nullptr;
    QLineEdit* lineEdit = nullptr;
    QPushButton* numberBtns[16];
    QString firstNum;
    QString secondNum;
    QString currentOperation;
    bool isSecond = false;
public:
    Calculator();
signals:
    void signalClickedNumberBtn();
protected slots:
    void slotClickedNumberBtn();
    void slotClickedOperation();
    void slotClickedCalculate();
    void slotClickedClearBtn();
};

#endif // CALCULATOR_H
