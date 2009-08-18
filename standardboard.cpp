#include "standardboard.h"

StandardBoard::StandardBoard(int width, int height, bool wrap)
        : Board(),
          _width(width),
          _height(height),
          _wrap(wrap),
          _cells(new int[width*height])
{
    for(int ii=0; ii<_width*_height; ii++) {
        _cells[ii] = 0;
    }
}

StandardBoard::~StandardBoard()
{
    delete [] _cells;
}

int StandardBoard::getWidth() const
{
    return _width;
}

int StandardBoard::getHeight() const
{
    return _height;
}

bool StandardBoard::isWrapped() const
{
    return _wrap;
}

int StandardBoard::getNeighbourCount(int x, int y) const
{
    int count = 0;
    for(int ii=-1; ii<2; ii++) {
        for(int jj=-1; jj<2; jj++) {
            if(ii == 0 && jj == 0) {
                continue;
            }
            if(getCell(x+ii, y+jj) > 0) {
                ++count;
            }
        }
    }
    return count;
}

int StandardBoard::getCell(int x, int y) const
{
    if(x < 0 || x >= _width || y < 0 || y >= _height) {
        if(_wrap) {
            x = (x + 2 * _width) % _width;
            y = (y + 2 * _height) % _height;
        }
        else {
            return 0;
        }
    }
    return _cells[y * _width + x];
}

void StandardBoard::setCell(int x, int y, int value)
{
    if(x < 0 || x >= _width || y < 0 || y >= _height) {
        if(_wrap) {
            x = (x + 2 * _width) % _width;
            y = (y + 2 * _height) % _height;
        }
        else {
            return;
        }
    }
    _cells[y * _width + x] = value;
}

void StandardBoard::toggleCell(int x, int y)
{
    if(getCell(x, y) > 0) {
        setCell(x, y, 0);
    }
    else {
        setCell(x, y, 1);
    }
}

void StandardBoard::step()
{
    int *newcells = new int[_width * _height];
    for(int x=0; x < _width; x++) {
        for(int y=0; y<_height; y++) {
            int neigh = getNeighbourCount(x, y);
            int cell = getCell(x, y);
            if(cell > 0) {
                if(neigh == 2 || neigh == 3) {
                    newcells[y * _width + x] = 1;
                    continue;
                }
            }
            else {
                if(neigh == 3) {
                    newcells[y * _width + x] = 1;
                    continue;
                }
            }
            newcells[y * _width + x] = 0;
        }
    }
    delete [] _cells;
    _cells = newcells;
    emit stepped();
}

void StandardBoard::timerEvent(QTimerEvent *event)
{
    step();
}
