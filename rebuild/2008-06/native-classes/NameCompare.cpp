// >>> native-status (generated) -- do not edit >>>
// NameCompare | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 1fd7548e | roc native-status --write
#include "util/Name.h"

static inline bool isNullName(const RBX::Name* name)
{
    return !name || name == &RBX::Name::getNullName();
}

int RBX::Name::compare(Name& first, Name& second)
{
    if (isNullName(&first)) return isNullName(&second) ? 0 : -1;
    if (isNullName(&second)) return isNullName(&first) ? 0 : 1;
    if (&first == &second) return 0;
    return first.toString().compare(second.toString());
}
