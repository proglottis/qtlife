#ifndef BOARDCACHE_H
#define BOARDCACHE_H

#include <QObject>

#include "board.h"

class BoardCache : public QObject
{
    Q_OBJECT

public:
    virtual ~BoardCache() {}
    virtual void step() = 0;
    virtual void clear(const Board *seed) = 0;
    virtual const Board *getBoard() const = 0;
    virtual bool append(const Board *board) = 0;
};

#endif // BOARDCACHE_H
