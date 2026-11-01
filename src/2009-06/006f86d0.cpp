// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_8db4e23178a6d799.cpp

// Candidate translation unit (score above; library headers required).
#include "tool/RunDragger.h"
#include <boost/shared_ptr.hpp>
#include <stddef.h>
namespace RBX {
bool __cdecl check(boost::shared_ptr<PartInstance>);
struct ExePartInstance2009 { char pad[0x118]; Primitive* primitive; };
inline Primitive* exePrimitive(PartInstance* p) { return reinterpret_cast<ExePartInstance2009*>(p)->primitive; }
void RunDragger::smartPtrHackPost() {
 typedef char weak_offset[offsetof(RunDragger,snapPart)==8?1:-1];
 typedef char snap_offset[offsetof(RunDragger,snapInfo)==0x24?1:-1];
 boost::shared_ptr<PartInstance> value=snapPart.lock();
 // 2009: PartInstance holds a Primitive* at 0x118.
 if(check(value))snapInfo.snap=exePrimitive(value.get());
 else snapInfo.snap=0;
}
}
typedef char weak_size[sizeof(boost::weak_ptr<RBX::PartInstance>)==8?1:-1];
typedef char snap_size[sizeof(RBX::RunDragger::SnapInfo)==32?1:-1];

