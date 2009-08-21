#ifndef STANDARDBOARD_H
#define STANDARDBOARD_H

#include "board.h"

#include <QVector>

class StandardBoard : public Board
{
    Q_OBJECT

public:
    StandardBoard(int width, int height, bool wrap);
    virtual ~StandardBoard();

    virtual int getWidth() const;
    virtual int getHeight() const;
    virtual bool isWrapped() const;
    virtual int getCell(int x, int y) const;
    virtual void setCell(int x, int y, int value);
    virtual void toggleCell(int x, int y);
    virtual void step();

protected:
    void timerEvent(QTimerEvent *event);

private:
    int getNeighbourCount(int x, int y) const;
    int getNextCell(int x, int y) const;
    void setNextCell(int x, int y, int value);
    void swap();

    int _width;
    int _height;
    bool _wrap;
    int *_cells;
    int *_nextCells;
};

#endif // STANDARDBOARD_H
