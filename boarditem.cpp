#include "boarditem.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

BoardItem::BoardItem(Board *board)
        : _board(board),
          _brush1(QColor(0, 0, 255), Qt::SolidPattern),
          _brush2(QColor(204, 204, 204), Qt::SolidPattern),
          _pen1(QColor(0, 0, 255)),
          _pen2(QColor(204, 204, 204))
{
}

QRectF BoardItem::boundingRect() const
{
    return QRectF(0, 0, 11 * _board->getWidth(), 11 * _board->getHeight());
}

void BoardItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget)
{
    for(int x=0; x<_board->getWidth(); x++) {
        for(int y=0; y<_board->getHeight(); y++) {
            if(_board->getCell(x, y) > 0) {
                painter->setBrush(_brush1);
                painter->setPen(_pen1);
            }
            else {
                painter->setBrush(_brush2);
                painter->setPen(_pen2);
            }
            painter->drawRect(11 * x, 11 * y, 9, 9);
        }
    }
}

void BoardItem::step()
{
    update(boundingRect());
}

void BoardItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    _board->toggleCell(event->pos().x() / 11, event->pos().y() / 11);
    step();
}
