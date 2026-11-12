#pragma once
// 2008-06 util/NormalId.cpp helper that the donor util/NormalId.h (included read-only) does not declare.
// normalIdToVector3Internal 005ec240 (cdecl, hidden Vector3 result): zeroes x/y/z, then writes +1.0f (id < 3) or
// -1.0f (constant 0081c3b8) into component id % 3 (imul 0x55555556). Its only callers are the six function-static
// initializers of normalIdToVector3 005ec570 (push id / push static / call 005ec240).
#include "util/NormalId.h"

namespace RBX
{
	G3D::Vector3 normalIdToVector3Internal(NormalId normalId);
}
