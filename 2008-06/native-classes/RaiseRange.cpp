// >>> native-status (generated) -- do not edit >>>
// RaiseRange | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src bf15fcf3 | roc native-status --write
#include "util/Events.h"

namespace RBX {
void RaiseRange::removeIndex(size_t removed)
{
    RaiseRange* range = this;
    do {
        if (range->upper > removed) --range->upper;
        if (range->index >= removed) --range->index;
        range = range->previous;
    } while (range);
}
}
