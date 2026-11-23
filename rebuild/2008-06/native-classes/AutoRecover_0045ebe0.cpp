// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include "stats/Stats.h"

// INFERRED: I couldn't read stats/Stats.h in this session, so this is unchecked against it.
// The previous attempt's C2084 says Item::Item() already has an inline body in the header,
// so it can't be redefined here. This helper only forces that inline constructor to be
// emitted (0045ebe0: the DescribedNonCreatable base ctor, then the value and name members).
extern "C" RBX::Stats::Item* fn_force_Item_ctor(void* p)
{
    return new (p) RBX::Stats::Item();
}
