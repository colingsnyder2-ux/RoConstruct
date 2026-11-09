// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_abstract_family_52b6defeb78c4a0e.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_header_7a4c998b489b0ddf.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_irenderable_header_89bd00a76e9b5599.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_irenderable_header_89bd00a76e9b5599.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#include "script/LuaSignalBridge.h"
#include "script/LuaInstanceBridge.h"
#include "G3D/format.h"

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
            // Â¯\_(ãƒ„)_/Â¯
            // maybe they meant to print it? lol
            argType.name();
        }
    }

    return arguments.size();
}

FunctionScriptSlot::FunctionScriptSlot(lua_State* thread, int functionIndex)
    : context(ScriptContext::getContext(thread)),
      function(FunctionRef(thread, functionIndex)),
      cachedSlotThread(ThreadRef())
{
}

// TODO: 99.09% (functional match - registers swapped in codegen)
void FunctionScriptSlot::operator()(const Arguments& arguments)
{
    lua_State* mainThread = function.thread();

    if (!mainThread)
    {
        cnction->disconnect();
        return;
    }

    lua_State* newThread = cachedSlotThread.thread();
    bool createdThread = false;

    if (!newThread)
    {
        newThread = lua_newthread(mainThread);

        if (!newThread)
            throw std::runtime_error("lua_newthread failed");

        createdThread = true;
    }

    lua_pushfunction(mainThread, function);
    lua_xmove(mainThread, newThread, 1);
    int narg = static_cast<int>(pushArgs(newThread, arguments));
    ScriptContext::Result resumeResult = context.resume(newThread, narg);

    switch (resumeResult)
    {
    case ScriptContext::Yield:
        cachedSlotThread.reset();
        break;

    case ScriptContext::Error:
        cachedSlotThread.reset();
        cnction->disconnect();
        break;
    }

    if (!function.thread())
        cnction->disconnect();

    if (createdThread)
    {
        if (resumeResult == ScriptContext::Success && function.thread())
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
