#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
    int val;
public:
    Counter();

public slots:
    void slotInc();

signals:
    void goodbye();
    void counterChanged(int);
};

#endif // COUNTER_H
