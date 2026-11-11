#pragma once
// >>> native-status (generated) -- do not edit >>>
// Point2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src aa07e8a9 | roc native-status --write
// 2008-06 RBX::Point (inactive native recovery). The donor v8kernel/Point.h layout is the 2008 one (it is already
// reached through native-headers/v8kernel/Connector2008.h, so it is not redeclared here):
//   RTTI     vtable 0084b24c .?AVPoint@RBX@@ -> KernelIndex at +0x04 (non-polymorphic); one slot, the scalar deleting
//            destructor 0064dc50 (inline ~Point, empty ~KernelIndex with /U_RELEASEASSERT).
//   ctor     0064dc00 Point(Body*), ret 4: kernelIndex +0x04 = -1, numOwners +0x08 = 1, body +0x0c (argument, or
//            Body::getWorldBody() 00614bb0 when NULL), localPos +0x10, worldPos +0x1c, force +0x28 zeroed; size 0x34.
// step 0064dc90, forceToBody 0064dc70 and setWorldPos 0064dd40 read Body fields at 2008 offsets (pv position at
// +0x94..+0xc0, root +0x10, root+0x2c, parent +0x14) that the donor v8kernel/Body.h does not have; they need a native
// 2008 Body header (not attempted here, see the recorder report).
#include "v8kernel/Point.h"
#include "v8kernel/Body.h"
