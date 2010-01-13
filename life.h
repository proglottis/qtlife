#ifndef LIFE_H
#define LIFE_H

#include <QObject>

#include "board.h"
#include "boardcache.h"

class Life : public QObject
{
    Q_OBJECT

public:
    virtual ~Life() {}

    virtual BoardCache *getCache() = 0;
    virtual void step() = 0;

signals:
    void stepped(BoardCache *cache);
};

#endif // LIFE_H
