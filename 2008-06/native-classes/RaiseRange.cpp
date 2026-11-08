// >>> native-status (generated) -- do not edit >>>
// RaiseRange | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
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
