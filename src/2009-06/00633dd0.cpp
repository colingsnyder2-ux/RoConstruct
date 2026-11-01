// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/script/ScriptContext.cpp

// Candidate translation unit (score above; library headers required).
#include "script/ScriptContext.h"

#include "reflection/signal.h"
#include "script/LuaAtomicClasses.h"
#include "util/Name.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/Stats.h"

namespace RBX {

char sScriptContext[] = "ScriptContext";

namespace Lua {

template <>
const char* Bridge<boost::shared_ptr<Reflection::DescribedBase>, 0>::className = "Object";

} // namespace Lua

// FUNCTION: WEBSERVICE 0x1005eb00
ScriptContext& ScriptContext::getContext(lua_State* L)
{
	lua_pushlightuserdata(L, (void*) 0x43);
	lua_gettable(L, LUA_GLOBALSINDEX);

	ScriptContext* context = static_cast<ScriptContext*>(lua_touserdata(L, -1));

	lua_settop(L, -2);

	return *context;
}

// STUB: WEBSERVICE 0x1005eb60
void ScriptContext::onEvent(const RunService* source, RunTransition event)
{
	STUB(0x1005eb60);
}

// FUNCTION: WEBSERVICE 0x1005f880
void Lua::CoordinateFrameBridge::pushCoordinateFrame(lua_State* L, G3D::CoordinateFrame value)
{
	pushNewObject(L, value);
}

// FUNCTION: WEBSERVICE 0x1005f8c0
void Lua::Vector3Bridge::pushVector3(lua_State* L, G3D::Vector3 value)
{
	pushNewObject(L, value);
}

// FUNCTION: WEBSERVICE 0x1005f910
void Lua::Color3Bridge::pushColor3(lua_State* L, G3D::Color3 value)
{
	pushNewObject(L, value);
}

// STUB: WEBSERVICE 0x100673d0
ScriptContext::Result ScriptContext::resume(lua_State* L, int nargs)
{
	STUB(0x100673d0);
	return Success;
}

// STUB: WEBSERVICE 0x10068880
void ScriptContext::onEvent(const RunService* source, Heartbeat event)
{
	STUB(0x10068880);
}

} // namespace RBX

template void RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::push(
	lua_State* L,
	boost::shared_ptr<RBX::Reflection::DescribedBase> instance
);

template void RBX::Lua::SharedPtrBridge<RBX::Reflection::SignalInstance>::push(
	lua_State* L,
	boost::shared_ptr<RBX::Reflection::SignalInstance> instance
);

template const RBX::Name& RBX::Name::doDeclare<RBX::Stats::sStatsItem>();
template const RBX::Name& RBX::Name::doDeclare<RBX::Stats::sStats>();
template const RBX::Name& RBX::Name::doDeclare<RBX::sDebugSettings>();
template void RBX::Name::callDoDeclare<RBX::Stats::sStatsItem>();
template void RBX::Name::callDoDeclare<RBX::Stats::sStats>();
template void RBX::Name::callDoDeclare<RBX::sDebugSettings>();

template class RBX::FactoryProduct<RBX::ScriptContext, RBX::Instance, RBX::sScriptContext>;
template class RBX::Reflection::Described<
	RBX::ScriptContext,
	RBX::sScriptContext,
	RBX::FactoryProduct<RBX::ScriptContext, RBX::Instance, RBX::sScriptContext> >;
template class RBX::DescribedCreatable<RBX::ScriptContext, RBX::Instance, RBX::sScriptContext>;
