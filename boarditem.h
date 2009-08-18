#ifndef BOARDITEM_H
#define BOARDITEM_H

#include <QGraphicsItem>
#include <QBrush>
#include <QPen>

#include "board.h"

class BoardItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    BoardItem(Board *board);
    virtual ~BoardItem() {}
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

public slots:
    void step();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Board *_board;
    QBrush _brush1;
    QBrush _brush2;
    QPen _pen1;
    QPen _pen2;
};

#endif // BOARDITEM_H
