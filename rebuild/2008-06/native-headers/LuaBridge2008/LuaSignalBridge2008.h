#pragma once
// 2008-06 Lua signal bridge (SignalBridge, SignalConnectionBridge, FunctionScriptSlot, WaitScriptSlot), inactive.
// Range 0061f180..00620a60 inside the bridge range documented in LuaBridge2008.h. Declarations are the read-only
// donor script/LuaSignalBridge.h; the recorder binds them to 2008-06 by byte-exact bodies with verified targets:
//   FunctionScriptSlot: ~FunctionScriptSlot 0061f2c0; WaitScriptSlot: ctor 00620190, copy ctor 0061f410, dtor 0061f350;
//   TGenericSlotWrapper<WaitScriptSlot>/<FunctionScriptSlot> vtables compared slot by slot (RTTI names).
#include "LuaBridge2008/LuaBridge2008.h"
#include "script/LuaSignalBridge.h"
