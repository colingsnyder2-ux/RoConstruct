#pragma once
// >>> native-status (generated) -- do not edit >>>
// NativeContentProvider | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 6d8342e6 | roc native-status --write
#include "../../util/NativeContentProvider.h"

namespace RBX {
inline bool operator<(const ContentId& a, const ContentId& b)
{
    return a.toString() < b.toString();
}
}
