#pragma once
// >>> native-status (generated) -- do not edit >>>
// StandardOut2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 9a17692d | roc native-status --write
// 2008-06 RBX::StandardOut (inactive native recovery). The class itself is the donor util/standardout.h declaration,
// which every native unit already reaches through native-headers/util/Events.h; it is not redeclared here (a second
// declaration would collide in those units). This header only gathers the 2008-06 evidence:
//   RTTI     vtable 0082f510 .?AVStandardOut@RBX@@ -> enable_shared_from_this<StandardOut> (+0x20, no vtable of its
//            own), Notifier<StandardOut, StandardOutMessage> (+0); 3 slots: 0 ??_G 005696d0, then the Notifier
//            onAddListener / onRemoveListener defaults.
//   ctor     00569530: Notifier() 005e9ec0, weak_ptr +0x20/+0x24 = 0, vtable, boost::mutex +0x28 (00594c90).
//   size     singleton() 00569620 news 0x30 before StandardOut() and keeps it in a function-local
//            shared_ptr (atexit).
//   dtor     00569590 never stores the StandardOut vtable: in 2008 the destructor is implicit (no user-declared
//            ~StandardOut), see the proposal in tests/record_native_leaves2008.py.
#include "util/standardout.h"
