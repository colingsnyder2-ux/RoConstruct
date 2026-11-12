// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// RaiseRange::removeIndex (00420740) - native 2008-06.
// >>> native-status (generated) -- do not edit >>>
// RaiseRange | 2008-06 | draft (byte proof at 00420740)
// 1/1 mapped addresses byte-exact | no mapped strings | by colin
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
