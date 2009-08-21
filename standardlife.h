#ifndef STANDARDLIFE_H
#define STANDARDLIFE_H

#include <QPointer>

#include "life.h"

class StandardLife : public Life
{
    Q_OBJECT

public:
    StandardLife(Board *board1, Board *board2);
    virtual ~StandardLife();

    virtual Board *getBoard();
    virtual void step();
    void swap();

protected:
    void timerEvent(QTimerEvent *event);

private:
    QPointer<Board> _curr;
    QPointer<Board> _next;
};

#endif // STANDARDLIFE_H
