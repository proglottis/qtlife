#ifndef STANDARDBOARD_H
#define STANDARDBOARD_H

#include "board.h"

#include <QVector>

class StandardBoard : public Board
{
    Q_OBJECT

public:
    StandardBoard(int width, int height, bool wrap);
    StandardBoard(const Board &other);

    virtual ~StandardBoard();

    virtual void operator=(const Board &other);

    virtual int getWidth() const;
    virtual int getHeight() const;
    virtual bool isWrapped() const;
    virtual int getCell(int x, int y) const;
    virtual int getNeighbourCount(int x, int y) const;
    virtual void setCell(int x, int y, int value);
    virtual void toggleCell(int x, int y);
    virtual void clear();

private:
    int _width;
    int _height;
    bool _wrap;
    int *_cells;
};

#endif // STANDARDBOARD_H
