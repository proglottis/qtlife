#include "standardlife.h"

StandardLife::StandardLife(Board *board, Rule *rule,
                           BoardCache *cache)
        : _next(board), _rule(rule), _cache(cache)
{
}

StandardLife::~StandardLife()
{
}

BoardCache *StandardLife::getCache()
{
    return _cache;
}

void StandardLife::step()
{
    const Board *curr = _cache->getBoard();
    for(int x=0; x < _next->getWidth(); x++) {
        for(int y=0; y < _next->getHeight(); y++) {
            int neigh = curr->getNeighbourCount(x, y);
            int cell = curr->getCell(x, y);
            _next->setCell(x, y, _rule->checkCell(cell, neigh));
        }
    }
    if(_cache->append(_next)) {
        emit stepped(_cache);
    }
}

void StandardLife::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    step();
}
