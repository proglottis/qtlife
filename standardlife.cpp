#include "standardlife.h"

StandardLife::StandardLife(Board *board1, Board *board2, Rule *rule)
        : _curr(board1), _next(board2), _rule(rule)
{
}

StandardLife::~StandardLife()
{
}

Board *StandardLife::getBoard()
{
    return _curr;
}

void StandardLife::step()
{
    for(int x=0; x < _next->getWidth(); x++) {
        for(int y=0; y < _next->getHeight(); y++) {
            int neigh = _curr->getNeighbourCount(x, y);
            int cell = _curr->getCell(x, y);
            _next->setCell(x, y, _rule->checkCell(cell, neigh));
        }
    }
    swap();
    emit stepped(_curr);
}

void StandardLife::swap()
{
    Board *temp = _curr;
    _curr = _next;
    _next = temp;
}

void StandardLife::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    step();
}
