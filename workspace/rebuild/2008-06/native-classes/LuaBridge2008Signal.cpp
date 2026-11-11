// Inactive 2008-06 native recovery: RBX::Lua signal bridge and script slots.
// Body shapes follow the donor reconstruction; counted rows are proven by tests/record_native_lua_bridge2008.py.
// >>> native-status (generated) -- do not edit >>>
// LuaBridge2008Signal | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 47edb3f5 | roc native-status --write
#include "LuaBridge2008/LuaSignalBridge2008.h"
#include "G3D/format.h"
#include "util/standardout.h"

using namespace RBX;
using namespace RBX::Lua;
using namespace RBX::Reflection;

template<>
int SignalBridge::on_index(const boost::shared_ptr<Reflection::SignalInstance>& object, const char* name, lua_State* L)
{
    if (!object.get())
        throw std::runtime_error(G3D::format("The %s event has been deleted", name));

    if (strcmp(name, "connect") == 0)
    {
        lua_pushcfunction(L, SignalBridge::connect);
        return 1;
    }

    if (strcmp(name, "wait") == 0)
    {
        lua_pushcfunction(L, SignalBridge::wait);
        return 1;
    }

    if (strcmp(name, "disconnect") == 0)
        throw std::runtime_error(G3D::format("Event:disconnect() has been deprecated. Use connection object returned by connect()"));

    throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

template<>
void SignalBridge::on_newindex(boost::shared_ptr<Reflection::SignalInstance>& object, const char* name, lua_State* L)
{
    if (!object.get())
        throw std::runtime_error(G3D::format("The %s event has been deleted", name));

    throw std::runtime_error(G3D::format("%s cannot be assigned to", name));
}

// The specialization above is of a member lua/LuaBridge.h defines inside the class body, which MSVC emits only when
// referenced (it is treated as inline): the __newindex wrapper that calls it (ScriptContext unit) is instantiated here
// so that 0061f220 is emitted. The wrapper instance itself is not a row.
namespace RBX { namespace Lua {
template int Bridge<boost::shared_ptr<Reflection::SignalInstance>, false>::on_newindex(lua_State*);
}}

static size_t pushArgs(lua_State* L, const Arguments& arguments)
{
    Arguments::const_iterator iter = arguments.begin();
    Arguments::const_iterator end = arguments.end();

    for (; iter != end; iter++)
    {
        const type_info& argType = iter->type();

        if (argType == typeid(std::string))
        {
            lua_pushstring(L, boost::any_cast<std::string>(*iter).c_str());
        }
        else if (argType == typeid(int))
        {
            lua_pushinteger(L, boost::any_cast<int>(*iter));
        }
        else if (argType == typeid(size_t))
        {
            lua_pushinteger(L, boost::any_cast<size_t>(*iter));
        }
        else if (argType == typeid(float))
        {
            lua_pushnumber(L, boost::any_cast<float>(*iter));
        }
        else if (argType == typeid(double))
        {
            lua_pushnumber(L, boost::any_cast<double>(*iter));
        }
        else if (argType == typeid(bool))
        {
            lua_pushboolean(L,boost::any_cast<bool>(*iter));
        }
        else if (argType == typeid(boost::shared_ptr<Instance>))
        {
            ObjectBridge::push(L, boost::any_cast<boost::shared_ptr<Instance>>(*iter));
        }
        else if (argType == typeid(const Reflection::PropertyDescriptor*))
        {
            lua_pushstring(L, boost::any_cast<const Reflection::PropertyDescriptor*>(*iter)->name.c_str());
        }
        else if (argType == typeid(const char*))
        {
            lua_pushstring(L, boost::any_cast<const char*>(*iter));
        }
        else
        {
            // 2008: the unknown argument type's name is taken (unused) and nil is pushed in its place
            // (lua_pushnil 006121e0 at 0061fe48).
            argType.name();
            lua_pushnil(L);
        }
    }

    return arguments.size();
}

FunctionScriptSlot::FunctionScriptSlot(lua_State* thread, int functionIndex)
    : context(ScriptContext::getContext(thread)),
      function(FunctionRef(thread, functionIndex)),
      cachedSlotThread(ThreadRef()),
      callDepth(0)
{
}

void FunctionScriptSlot::operator()(const Arguments& arguments)
{
    bool reentrant = callDepth > 0;
    const int depth = callDepth + 1;
    ScopedAssign2008 depthScope(callDepth, depth);

    if (callDepth > 6)
    {
        StandardOut::singleton()->print(MESSAGE_ERROR, "maximum event re-entrancy depth exceeded");
        return;
    }

    lua_State* mainThread = function.thread();

    if (!mainThread)
    {
        cnction->disconnect();
        return;
    }

    lua_State* newThread = reentrant ? NULL : cachedSlotThread.thread();
    bool createdThread;

    if (newThread)
        createdThread = false;
    else
    {
        newThread = lua_newthread(mainThread);

        if (!newThread)
            throw std::runtime_error("Unable to create a new event handler thread");

        createdThread = true;
    }

    lua_pushfunction(mainThread, function);
    lua_xmove(mainThread, newThread, 1);
    int narg = static_cast<int>(pushArgs(newThread, arguments));
    ScriptContext::Result resumeResult = context.resume(newThread, narg);

    switch (resumeResult)
    {
    case ScriptContext::Yield:
        if (!reentrant)
            cachedSlotThread.reset();
        break;

    case ScriptContext::Error:
        if (!reentrant)
            cachedSlotThread.reset();
        cnction->disconnect();
        break;
    }

    if (!function.thread())
        cnction->disconnect();

    if (createdThread)
    {
        if (!reentrant && resumeResult == ScriptContext::Success && function.thread())
            cachedSlotThread = ThreadRef(newThread);

        lua_pop(mainThread, 1);
    }

    lua_settop(newThread, 0);
}

WaitScriptSlot::WaitScriptSlot(lua_State* thread)
    : waitThread(ThreadRef(thread))
{
}

void WaitScriptSlot::operator()(const Arguments& arguments)
{
	Slot::cnction->disconnect();
	
	if (lua_State* state = waitThread.thread())
	{
		int top = lua_gettop(state);
		ScriptContext::getContext(state).resume(state, pushArgs(state, arguments));
		lua_settop(state, top);
	}
}

int SignalBridge::connect(lua_State* L)
{
    boost::shared_ptr<Reflection::SignalInstance> si = getObject(L, 1);

    FunctionScriptSlot slot(L, 2);
    *(slot.cnction) = si->connectGeneric(slot, boost::signals::at_front);

    SignalConnectionBridge::pushNewObject(L, *(slot.cnction));

    return 1;
}

int SignalBridge::wait(lua_State* L)
{
    // what's with the scope? connect probably does the same thing
    {
        boost::shared_ptr<Reflection::SignalInstance> si = getObject(L, 1);

        WaitScriptSlot slot(L);
        *(slot.cnction) = si->connectGeneric(slot, boost::signals::at_front);

        RobloxExtraSpace::get(L)->yieldCaptured = true;
    }

    return lua_yield(L, 0);
}

template<>
int SignalConnectionBridge::on_index(const boost::signals::connection& object, const char* name, lua_State* L)
{
    if (strcmp(name, "disconnect") == 0)
    {
        lua_pushcfunction(L, SignalConnectionBridge::disconnect);
        return 1;
    }
    else if (strcmp(name, "connected") == 0)
    {
        lua_pushboolean(L, object.connected());
        return 1;
    }

    throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

int SignalConnectionBridge::disconnect(lua_State* L)
{
    boost::signals::connection& cnction = getObject(L, 1);
    cnction.disconnect();
    return 0;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Lua::Bridge<boost::signals::connection,1>;
template class RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>;
template class boost::shared_ptr<boost::mutex>;
template class boost::shared_ptr<boost::signals::connection>;
template class std::_Vector_const_iterator<boost::any,std::allocator<boost::any> >;
