// from server: 100% by EspClaude
// from server: 70% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_1b56d51498b8d9ae.cpp

// Candidate translation unit (score above; library headers required).
#include "script/ThreadRef.h"

namespace RBX
{
    namespace Lua
    {
		boost::shared_ptr<boost::mutex> ThreadRef::syncSingleton(new boost::mutex);
    }
}
