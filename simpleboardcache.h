#ifndef SIMPLEBOARDCACHE_H
#define SIMPLEBOARDCACHE_H

#include <QLinkedList>

#include "boardcache.h"

class SimpleBoardCache : public BoardCache
{
    Q_OBJECT

public:
    SimpleBoardCache(int limit, const Board *seed);
    virtual ~SimpleBoardCache() {}
    virtual void step();
    virtual void clear(const Board *seed);
    virtual const Board *getBoard() const;
    virtual bool append(const Board *board);
private:
    QLinkedList<Board *> _boards;
    int _limit;
};

#endif // SIMPLEBOARDCACHE_H
