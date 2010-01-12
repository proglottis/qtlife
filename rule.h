#ifndef RULE_H
#define RULE_H

#include <QObject>

class Rule : public QObject
{
    Q_OBJECT

public:
    virtual ~Rule() {}
    virtual int checkCell(int cell, int neighbours) const = 0;
};

#endif // RULE_H
