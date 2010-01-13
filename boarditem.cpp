#include "boarditem.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "standardboard.h"

BoardItem::BoardItem(BoardCache *cache)
        : _cache(cache),
          _brush1(QColor(0, 0, 255), Qt::SolidPattern),
          _brush2(QColor(204, 204, 204), Qt::SolidPattern),
          _pen1(QColor(0, 0, 255)),
          _pen2(QColor(204, 204, 204)),
          _mode(1)
{
}

QRectF BoardItem::boundingRect() const
{
    return QRectF(0, 0, 11 * _cache->getBoard()->getWidth(), 11 * _cache->getBoard()->getHeight());
}

void BoardItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    const Board *board = _cache->getBoard();
    for(int x=0; x<board->getWidth(); x++) {
        for(int y=0; y<board->getHeight(); y++) {
            if(board->getCell(x, y) > 0) {
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

void BoardItem::step(BoardCache *cache)
{
    _cache = cache;
    _cache->step();
    update(boundingRect());
}

void BoardItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Board *board = new StandardBoard(*_cache->getBoard());
    int cell = board->getCell(event->pos().x() / 11, event->pos().y() / 11);
    _mode = cell < 1?1:0;
    board->setCell(event->pos().x() / 11, event->pos().y() / 11, _mode);
    _cache->clear(board);
    update(boundingRect());
}

void BoardItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton) {
        Board *board = new StandardBoard(*_cache->getBoard());
        board->setCell(event->pos().x() / 11, event->pos().y() / 11, _mode);
        _cache->clear(board);
        update(boundingRect());
    }
}
