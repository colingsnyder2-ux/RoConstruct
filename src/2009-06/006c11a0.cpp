// from server: 38% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/script/ScriptEvent.cpp

// Candidate translation unit (score above; library headers required).
#include "script/ScriptEvent.h"

#include <lua.h>

namespace RBX {
namespace Lua {

// STUB: WEBSERVICE 0x100b5790
YieldingThreads::WaitingThread::WaitingThread(lua_State* L, double requestedDelay)
	: thread(new ThreadRef(L)), requestedDelay(requestedDelay), elapsedTime(0.0)
{
}

// FUNCTION: WEBSERVICE 0x100b5e00
YieldingThreads::YieldingThreads(ScriptContext* context) : context(context)
{
}

// STUB: WEBSERVICE 0x100b5f80
void YieldingThreads::queueWaiter(lua_State* L, double requestedDelay)
{
	waitingThreads.push_back(WaitingThread(L, requestedDelay));
}

// FUNCTION: WEBSERVICE 0x100b61d0
void YieldingThreads::queueWaiter(lua_State* L)
{
	queueWaiter(L, 0.0);
}

} // namespace Lua
} // namespace RBX
