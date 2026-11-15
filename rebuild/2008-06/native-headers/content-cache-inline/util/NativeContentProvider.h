#pragma once
#include "../../util/NativeContentProvider.h"

namespace RBX {
inline bool operator<(const ContentId& a, const ContentId& b)
{
    return a.toString() < b.toString();
}
}
