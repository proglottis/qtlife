#include "standardlife.h"

StandardLife::StandardLife(Board *board1, Board *board2)
        : _curr(board1), _next(board2)
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
    for(int x=0; x < _curr->getWidth(); x++) {
        for(int y=0; y < _curr->getHeight(); y++) {
            int neigh = _curr->getNeighbourCount(x, y);
            int cell = _curr->getCell(x, y);
            if(cell > 0) {
                if(neigh == 2 || neigh == 3) {
                    _next->setCell(x, y, 1);
                    continue;
                }
            }
            else {
                if(neigh == 3) {
                    _next->setCell(x, y, 1);
                    continue;
                }
            }
            _next->setCell(x, y, 0);
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
