// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_nativefunctioncalla37dc4602e9c987d.cpp

// Candidate translation unit (score above; library headers required).
#include "script/ScriptContext.h"
#include <stdexcept>
namespace RBX {
void ScriptContext::call(const Lua::FunctionRef& f,PushArgumentsClosure pushArguments,ReadResultsClosure readResults){
 if(f.empty())throw std::runtime_error("Cannot call a nil function");
 Lua::lua_pushfunction(f.thread(),f);
 resume(f.thread(),pushArguments,readResults);
}
}
