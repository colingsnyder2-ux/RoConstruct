// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/App/lua-5.1.1/src /TP
// Small runtime pieces the Roblox Lua build references but no linked object defines (gemini dossier sections 16/22).
// INFERRED: lua_setlevel is the Lua 5.1.2+ API (ldo.c): copy the C-call depth to a new coroutine; Roblox's 5.1.1 tree
// lacks it, the client's converted code calls the C name _lua_setlevel (stubbed: 30 calls).
// INFERRED: lua_longjmp TypeDescriptor/CatchableType (??_R0PAUlua_longjmp@@@8, __CTA2PAUlua_longjmp@@) were stub data,
// so throw/catch of lua_longjmp* could not match; throwing one in a never-called function makes the compiler emit them.
#include "lstate.h"

extern "C" void lua_setlevel(lua_State* from, lua_State* to)
{
    to->nCcalls = from->nCcalls;
}

struct lua_longjmp;
void roc_emit_lua_longjmp_rtti(lua_longjmp* p)
{
    throw p;
}
