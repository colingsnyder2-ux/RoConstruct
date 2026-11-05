// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/script/LuaSignalBridge.cpp

// Candidate translation unit (score above; library headers required).
#include "script/LuaSignalBridge.h"

#include "reflection/property.h"
#include "reflection/signal.h"
#include "script/Script.h"
#include "script/ScriptContext.h"
#include "script/ThreadRef.h"
#include "util/scopedassign.h"
#include "util/standardout.h"
#include "v8tree/Instance.h"

#include <G3D/format.h>
#include <boost/any.hpp>
#include <lua.h>
#include <stdexcept>
#include <string.h>
#include <string>
#include <typeinfo>
#include <vector>

// SIZE 0x28
class WaitScriptSlot : public RBX::Script::Slot
{
public:
	WaitScriptSlot(lua_State* L);

	void operator()(const std::vector<boost::any>& arguments);

private:
	RBX::Lua::ThreadRef waitThread; // 0x08
};

DECOMP_SIZE_ASSERT(WaitScriptSlot, 0x28)

// SIZE 0x54
class FunctionScriptSlot : public RBX::Script::Slot
{
public:
	FunctionScriptSlot(lua_State* L, int index);

	void operator()(const std::vector<boost::any>& arguments);

private:
	RBX::ScriptContext& context;          // 0x08
	RBX::Lua::FunctionRef function;       // 0x0c
	RBX::Lua::ThreadRef cachedSlotThread; // 0x30
	int executionDepth;                   // 0x50
};

DECOMP_SIZE_ASSERT(FunctionScriptSlot, 0x54)

namespace RBX {
namespace Lua {

template <>
const char* Bridge<boost::signals::connection, 1>::className = "RBXScriptConnection";

template <>
const char* Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>, 0>::className = "RBXScriptSignal";

template boost::signals::connection* Bridge<boost::signals::connection, 1>::pushNewObject<boost::signals::connection>(
	lua_State* L,
	boost::signals::connection value
);

// FUNCTION: WEBSERVICE 0x100afc80
template <>
void Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>, 0>::on_newindex(
	boost::shared_ptr<RBX::Reflection::SignalInstance>& value,
	const char* name,
	lua_State* L
)
{
	if (value.get() == NULL) {
		throw std::runtime_error(G3D::format("The %s event has been deleted", name));
	}

	throw std::runtime_error(G3D::format("%s cannot be assigned to", name));
}

// FUNCTION: WEBSERVICE 0x100afe30
int SignalConnectionBridge::disconnect(lua_State* L)
{
	getObject(L, 1).disconnect();
	return 0;
}

// FUNCTION: WEBSERVICE 0x100afee0
template <>
int Bridge<boost::signals::connection, 1>::on_index(
	const boost::signals::connection& value,
	const char* name,
	lua_State* L
)
{
	if (strcmp(name, "disconnect") == 0) {
		lua_pushcclosure(L, SignalConnectionBridge::disconnect, 0);
		return 1;
	}

	if (strcmp(name, "connected") == 0) {
		lua_pushboolean(L, value.connected());
		return 1;
	}

	throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

} // namespace Lua
} // namespace RBX

// STUB: WEBSERVICE 0x100b0440
static unsigned int pushArgs(lua_State* L, const std::vector<boost::any>& arguments)
{
	for (std::vector<boost::any>::const_iterator iter = arguments.begin(), end = arguments.end(); iter != end; ++iter) {
		const std::type_info& type = iter->type();

		if (type == typeid(std::string)) {
			lua_pushstring(L, boost::any_cast<std::string>(*iter).c_str());
		}
		else if (type == typeid(int)) {
			lua_pushinteger(L, boost::any_cast<int>(*iter));
		}
		else if (type == typeid(unsigned int)) {
			lua_pushinteger(L, boost::any_cast<unsigned int>(*iter));
		}
		else if (type == typeid(float)) {
			lua_pushnumber(L, boost::any_cast<float>(*iter));
		}
		else if (type == typeid(double)) {
			lua_pushnumber(L, boost::any_cast<double>(*iter));
		}
		else if (type == typeid(bool)) {
			lua_pushboolean(L, boost::any_cast<bool>(*iter));
		}
		else if (type == typeid(boost::shared_ptr<RBX::Instance>)) {
			RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::push(
				L,
				boost::any_cast<boost::shared_ptr<RBX::Instance> >(*iter)
			);
		}
		else if (type == typeid(const RBX::Reflection::PropertyDescriptor*)) {
			lua_pushstring(L, boost::any_cast<const RBX::Reflection::PropertyDescriptor*>(*iter)->name.name.c_str());
		}
		else if (type == typeid(const char*)) {
			lua_pushstring(L, boost::any_cast<const char*>(*iter));
		}
		else {
			type.name();

			lua_pushnil(L);
		}
	}

	return arguments.size();
}

void WaitScriptSlot::operator()(const std::vector<boost::any>& arguments)
{
	cnction->disconnect();

	lua_State* thread = waitThread.thread();

	if (thread != NULL) {
		int top = lua_gettop(thread);

		RBX::ScriptContext::getContext(thread).resume(thread, pushArgs(thread, arguments));

		lua_settop(thread, top);
	}
}

// FUNCTION: WEBSERVICE 0x100b0920
void FunctionScriptSlot::operator()(const std::vector<boost::any>& arguments)
{
	bool reentrant = executionDepth > 0;
	RBX::ScopedAssign<int> assign(executionDepth, executionDepth + 1);

	if (executionDepth > 6) {
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "maximum event re-entrancy depth exceeded");
		return;
	}

	lua_State* thread = function.thread();

	if (thread == NULL) {
		cnction->disconnect();
		return;
	}

	lua_State* slotThread = reentrant ? NULL : cachedSlotThread.thread();
	bool createdThread;

	if (slotThread != NULL) {
		createdThread = false;
	}
	else {
		slotThread = lua_newthread(thread);

		if (slotThread == NULL) {
			throw std::runtime_error("lua_newthread failed");
		}

		createdThread = true;
	}

	RBX::Lua::lua_pushfunction(thread, function);

	lua_xmove(thread, slotThread, 1);

	RBX::ScriptContext::Result result = context.resume(slotThread, pushArgs(slotThread, arguments));

	switch (result) {
	case RBX::ScriptContext::Yield:
		if (!reentrant) {
			cachedSlotThread.reset();
		}

		break;

	case RBX::ScriptContext::Error:
		if (!reentrant) {
			cachedSlotThread.reset();
		}

		cnction->disconnect();
		break;
	}

	if (function.thread() == NULL) {
		cnction->disconnect();
	}

	if (createdThread) {
		if (!reentrant && result == RBX::ScriptContext::Success && function.thread() != NULL) {
			cachedSlotThread = RBX::Lua::ThreadRef(slotThread);
		}

		lua_settop(thread, -2);
	}

	lua_settop(slotThread, 0);
}

// STUB: WEBSERVICE 0x100b0cb0
FunctionScriptSlot::FunctionScriptSlot(lua_State* L, int index)
	: context(RBX::ScriptContext::getContext(L)), function(L, index), executionDepth(0)
{
}

// STUB: WEBSERVICE 0x100b0d80
WaitScriptSlot::WaitScriptSlot(lua_State* L) : waitThread(L)
{
}

namespace RBX {
namespace Lua {

// FUNCTION: WEBSERVICE 0x100b0f00
int SignalBridge::wait(lua_State* L)
{
	{
		boost::shared_ptr<RBX::Reflection::SignalInstance> si = getObject(L, 1);

		WaitScriptSlot slot(L);

		*slot.cnction = si->connectGeneric(slot, boost::signals::at_front);

		RobloxExtraSpace::get(L)->yieldCaptured = true;
	}

	return lua_yield(L, 0);
}

// FUNCTION: WEBSERVICE 0x100b10b0
int SignalBridge::connect(lua_State* L)
{
	boost::shared_ptr<RBX::Reflection::SignalInstance> si = getObject(L, 1);

	FunctionScriptSlot slot(L, 2);

	*slot.cnction = si->connectGeneric(slot, boost::signals::at_front);

	SignalConnectionBridge::pushNewObject(L, *slot.cnction);

	return 1;
}

// FUNCTION: WEBSERVICE 0x100b11f0
template <>
int Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>, 0>::on_index(
	const boost::shared_ptr<RBX::Reflection::SignalInstance>& value,
	const char* name,
	lua_State* L
)
{
	if (value.get() == NULL) {
		throw std::runtime_error(G3D::format("The %s event has been deleted", name));
	}

	if (strcmp(name, "connect") == 0) {
		lua_pushcclosure(L, SignalBridge::connect, 0);
		return 1;
	}

	if (strcmp(name, "wait") == 0) {
		lua_pushcclosure(L, SignalBridge::wait, 0);
		return 1;
	}

	if (strcmp(name, "disconnect") == 0) {
		throw std::runtime_error(
			G3D::format("Event:disconnect() has been deprecated. Use connection object returned by connect()")
		);
	}

	throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

} // namespace Lua
} // namespace RBX

template int RBX::Lua::Bridge<boost::signals::connection, 1>::on_gc(lua_State* L);

template int RBX::Lua::Bridge<boost::signals::connection, 1>::on_eq(lua_State* L);

template int RBX::Lua::Bridge<boost::signals::connection, 1>::on_newindex(lua_State* L);

template int RBX::Lua::Bridge<boost::signals::connection, 1>::on_index(lua_State* L);

template int RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>, 0>::on_newindex(lua_State* L);

template int RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>, 0>::on_index(lua_State* L);

template RBX::Reflection::GenericSlotWrapper* RBX::Reflection::GenericSlotWrapper::create<WaitScriptSlot>(
	WaitScriptSlot slot
);

template RBX::Reflection::GenericSlotWrapper* RBX::Reflection::GenericSlotWrapper::create<FunctionScriptSlot>(
	FunctionScriptSlot slot
);
