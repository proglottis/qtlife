#include "simpleboardcache.h"

#include "standardboard.h"

SimpleBoardCache::SimpleBoardCache(int limit, const Board *seed)
        : _boards(),
          _limit(limit)
{
    Board *newboard = new StandardBoard(*seed);
    newboard->setParent(this);
    _boards.clear();
    _boards.push_back(newboard);
}

void SimpleBoardCache::step()
{
    if(_boards.front() == _boards.back()) {
        return;
    }
    _boards.pop_front();
}

void SimpleBoardCache::clear(const Board *seed)
{
    Board *newboard = new StandardBoard(*seed);
    newboard->setParent(this);
    _boards.clear();
    _boards.push_back(newboard);
}

const Board *SimpleBoardCache::getBoard() const
{
    return _boards.front();
}

bool SimpleBoardCache::append(const Board *board)
{
    if(_boards.size() > _limit) {
        return false;
    }
    Board *newboard = new StandardBoard(*board);
    newboard->setParent(this);
    _boards.push_back(newboard);
    return true;
}
