// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "stats/Stats.h"

// INFERRED: the target type of the RTDynamicCast (type descriptor 0x9320f4) is Stats::Item,
// so a Stats::Item only accepts other Stats::Items as children.
bool RBX::Stats::Item::askAddChild(const RBX::Instance* instance) const
{
    return dynamic_cast<const RBX::Stats::Item*>(instance) != 0;
}
