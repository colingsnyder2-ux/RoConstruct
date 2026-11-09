// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_lua_report_native_tolstring_8841c4a4718b888b.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8datamodel/DebugSettings.h", "../roc_lua_debug_settings_header_c5ae733591533a2b.cpp")
#undef _RELEASEASSERT
#include "script/ScriptContext.h"
#include "v8datamodel/DebugSettings.h"
#include "util/StandardOut.h"
extern "C" {
#include "lobject.h"
#include "lauxlib.h"
}
namespace RBX {
void ScriptContext::reportError(lua_State* thread) {
 StandardOut::singleton()->print(MESSAGE_ERROR, "%s", lua_tostring(thread, -1));
 if (DebugSettings::singleton().getStackTracingEnabled()) {
  lua_Debug ar;
  if (lua_getstack(thread, 0, &ar)) {
   bool moreStack = false;
   int level = 0;
   while (level < 12 && lua_getstack(thread, level++, &ar)) {
    if (lua_getinfo(thread, "nSlu", &ar) && ar.currentline >= 0) {
     moreStack = true;
     char source[64];
     luaO_chunkid(source, ar.source, sizeof(source));
     if (ar.name)
      StandardOut::singleton()->print(MESSAGE_INFO, "%s, line %d - %s %s", source, ar.currentline, ar.namewhat, ar.name);
     else
      StandardOut::singleton()->print(MESSAGE_INFO, "%s, line %d", source, ar.currentline);
    }
   }
   if (moreStack && level < 12) StandardOut::singleton()->print(MESSAGE_INFO, "   stack end");
  }
 } else StandardOut::singleton()->print(MESSAGE_ERROR, "%s", lua_tostring(thread, -1));
}
}
