#ifndef BOARDITEM_H
#define BOARDITEM_H

#include <QPointer>
#include <QGraphicsItem>
#include <QBrush>
#include <QPen>

#include "board.h"
#include "boardcache.h"

class BoardItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    BoardItem(BoardCache *cache);
    virtual ~BoardItem() {}
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

public slots:
    void step(BoardCache *cache);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointer<BoardCache> _cache;
    QBrush _brush1;
    QBrush _brush2;
    QPen _pen1;
    QPen _pen2;
    int _mode;
};

#endif // BOARDITEM_H
