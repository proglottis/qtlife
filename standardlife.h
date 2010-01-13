#ifndef STANDARDLIFE_H
#define STANDARDLIFE_H

#include <QPointer>

#include "life.h"
#include "rule.h"
#include "boardcache.h"

class StandardLife : public Life
{
    Q_OBJECT

public:
    StandardLife(Board *board, Rule *rule, BoardCache *cache);
    virtual ~StandardLife();

    virtual BoardCache *getCache();
    virtual void step();

protected:
    void timerEvent(QTimerEvent *event);

private:
    QPointer<Board> _next;
    QPointer<Rule> _rule;
    QPointer<BoardCache> _cache;
};

#endif // STANDARDLIFE_H
