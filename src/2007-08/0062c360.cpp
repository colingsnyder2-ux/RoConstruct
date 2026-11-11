// from server: 97% by EspClaude
// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_claude_a4aef23b02cf8729.cpp

// Candidate translation unit (score above; library headers required).
#include "tool/RunDragger.h"
#include <boost/shared_ptr.hpp>
#include <stddef.h>
namespace RBX {
bool __cdecl check(boost::shared_ptr<PartInstance>);
void RunDragger::smartPtrHackPost() {
 typedef char weak_offset[offsetof(RunDragger,snapPart)==8?1:-1];
 typedef char snap_offset[offsetof(RunDragger,snapInfo)==0x24?1:-1];
 boost::shared_ptr<PartInstance> value=snapPart.lock();
 // Native LEA/add228 establishes the embedded Primitive on this borrowed receiver.
 if(check(value)){Primitive* p=*reinterpret_cast<Primitive**>(reinterpret_cast<char*>(value.get())+0x1d8);snapInfo.snap=p;}
 else snapInfo.snap=0;
}
}
typedef char weak_size[sizeof(boost::weak_ptr<RBX::PartInstance>)==8?1:-1];
typedef char snap_size[sizeof(RBX::RunDragger::SnapInfo)==32?1:-1];
