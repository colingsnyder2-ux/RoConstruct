// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_script_default_set_ctor_0d9dc12ea3eae01a.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_part_instance_guid_decl_2b7e2a3e9ffcb726.cpp")
#pragma include_alias("script/ScriptContext.h", "roc_script_timeout_volatile_decl_62638bbf965ad4fc.cpp")
#include <stddef.h>
#include <roc_script_timeout_volatile_decl_62638bbf965ad4fc.cpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace RBX {
ScriptContext::ScriptContext()
 : globalState(NULL),
   nextPendingScripts(boost::posix_time::second_clock::local_time()),
   scriptsDisabled(false), timoutSpan(0), timoutTime(0), timedout(0)
{
 typedef char instanceSize[sizeof(Instance)==0x130?1:-1];
 typedef char ownerSize[sizeof(ScriptContext)==0x1f8?1:-1];
 typedef char globalOffset[offsetof(ScriptContext,globalState)==0x138?1:-1];
 typedef char spanOffset[offsetof(ScriptContext,timoutSpan)==0x1b8?1:-1];
 typedef char flagOffset[offsetof(ScriptContext,timedout)==0x1c8?1:-1];
 typedef char threadOffset[offsetof(ScriptContext,timeoutThread)==0x1cc?1:-1];
 typedef char mutexOffset[offsetof(ScriptContext,timeoutMutex)==0x1d0?1:-1];
 typedef char conditionOffset[offsetof(ScriptContext,timeoutCondition)==0x1d8?1:-1];
 typedef char allocatorOffset[offsetof(ScriptContext,allocator)==0x1f0?1:-1];
 setName("Script Context");
}
}
