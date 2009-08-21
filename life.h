#ifndef LIFE_H
#define LIFE_H

#include <QObject>

#include "board.h"

class Life : public QObject
{
    Q_OBJECT

public:
    virtual ~Life() {}

    virtual Board *getBoard() = 0;
    virtual void step() = 0;

signals:
    void stepped(Board *board);
};

#endif // LIFE_H
