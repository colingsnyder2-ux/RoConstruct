#pragma once
// >>> native-status (generated) -- do not edit >>>
// NativeContentProvider | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 6d8342e6 | roc native-status --write
#include "../../util/NativeContentProvider.h"

namespace RBX {
inline bool operator<(const ContentId& a, const ContentId& b)
{
    return a.toString() < b.toString();
}
}
