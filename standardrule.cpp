#include "standardrule.h"

StandardRule::StandardRule()
{
}

int StandardRule::checkCell(int cell, int neighbours) const
{
    if(cell > 0) {
        if(neighbours == 2 || neighbours == 3) {
            return 1;
        }
    }
    else {
        if(neighbours == 3) {
            return 1;
        }
    }
    return 0;
}
