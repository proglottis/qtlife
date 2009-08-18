#ifndef BOARD_H
#define BOARD_H

#include <QObject>

class Board : public QObject
{
    Q_OBJECT

public:
    virtual ~Board() {}
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual bool isWrapped() const = 0;
    virtual int getCell(int x, int y) const = 0;
    virtual void setCell(int x, int y, int value) = 0;
    virtual void toggleCell(int x, int y) = 0;
    virtual void step() = 0;

signals:
    void stepped();
};

#endif // BOARD_H
