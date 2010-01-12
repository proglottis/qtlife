#ifndef STANDARDRULE_H
#define STANDARDRULE_H

#include "rule.h"

class StandardRule : public Rule
{
    Q_OBJECT

public:
    StandardRule();
    virtual ~StandardRule() {}

    virtual int checkCell(int cell, int neighbours) const;
};

#endif // STANDARDRULE_H
