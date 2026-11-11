#pragma once
// >>> native-status (generated) -- do not edit >>>
// RevoluteLink2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src b0487f3e | roc native-status --write
// 2008-06 RBX::Link / RBX::RevoluteLink (inactive native recovery). The donor v8kernel/Link.h layout is the 2008 one
// (it is already reached through native-headers/v8world/Joints2008.h, so it is not redeclared here):
//   RTTI     vtable 0083f75c .?AVRevoluteLink@RBX@@ -> Link (mdisp 0); Link is __declspec(novtable) (Link() 00613d20
//            stores no vtable); one slot, computeChildInParent 00613cc0. ~Link is the shared empty body 0047d410.
//   ctor     Link() 00613d20: body +0x04 = NULL, CoordinateFrame() 004782d0 for parentCoord +0x08, childCoord +0x38,
//            childCoordInverse +0x68, childInParent +0x98, stateIndex +0xc8 = Body::getNextStateIndex() 00613f20.
//   size     MotorJoint() 005e5bf0 news 0xd0 for the RevoluteLink (jointAngle +0xcc).
// getChildInParent 00613d60 reads Body parent +0x14 and stateIndex +0x90 (donor Body.h: +0x08 / +0x84); and
// computeChildInParent 00613cc0 calls the cdecl CoordinateFrame product helper 005989d0 (a, b, out), which has no
// declaration in any native or donor header. Both are reported, not attempted further.
#include "v8kernel/Link.h"
#include "v8kernel/Body.h"
