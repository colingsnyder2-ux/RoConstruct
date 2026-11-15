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
