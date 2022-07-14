#include "counter.h"

Counter::Counter() : QObject(), val(0)
{

}

void Counter::slotInc()
{
    emit counterChanged(++val);
    if(val == 5)
        emit goodbye();
}
