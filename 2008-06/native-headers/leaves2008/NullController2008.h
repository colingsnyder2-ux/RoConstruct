#pragma once
// >>> native-status (generated) -- do not edit >>>
// NullController2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src bd3987e4 | roc native-status --write
// 2008-06 RBX::NullController (inactive native recovery). The donor v8world/Controller.h declaration is the 2008 one
// (reached already through native-headers/v8datamodel/PVInstance.h, so it is not redeclared here):
//   RTTI     vtable 00832a04 .?AVNullController@RBX@@ -> Controller -> G3D::ReferenceCountedObject (all mdisp 0);
//            5 slots: 0 ??_G (ICF-shared with ReferenceCountedObject 004729b0), 1 Controller::getValue 00598a50,
//            2 getControllerType 00416690 (shared `xor eax, eax`), 3 hasIntelligence / 4 isUserController 0060a2f0.
//   size     0x0c (static instance 00976384..0097638f; ControllerService() 005cb9e0 news 0x0c).
//   statics  getStaticNullController 00599e50 (function-local static, guard 00976390, atexit 007fdbc0).
#include "v8world/Controller.h"
