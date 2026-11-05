// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_abstract_family_d7e6688da5b4b440.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#undef _DLL
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
#include "script/LuaInstanceBridge.h"
#include "script/LuaSignalBridge.h"
#include "script/LuaArguments.h"
#include "script/LuaAtomicClasses.h"
#include "script/ThreadRef.h"
#include "util/Sound.h"
#include "util/TextureId.h"
#include "util/standardout.h"
#include "v8tree/Instance.h"
#include "G3D/format.h"
#include "G3D/Vector3.h"

// matches generally aren't very good here

using namespace RBX;
using namespace RBX::Lua;
using namespace RBX::Reflection;
using namespace RBX::Soundscape;

void RBX::Lua::newweaktable(lua_State* L, const char* mode)
{
    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setmetatable(L, -2);
    lua_pushliteral(L, "__mode");
    lua_pushstring(L, mode);
    lua_settable(L, -3);
}

const luaL_Reg ObjectBridge::classLibrary[] = 
{
    {"new", ObjectBridge::newInstance},
    {NULL, NULL}
};

int ObjectBridge::newInstance(lua_State* thread)
{
    const Name& name = Name::lookup(lua_tostring(thread, 1));
    boost::shared_ptr<Instance> instance = AbstractFactoryProduct<Instance>::create(name);

    if (lua_gettop(thread) >= 2)
    {
        boost::shared_ptr<Instance> parent = ObjectBridge::getInstance(thread, 2);

        if (parent)
            instance->setParent(parent.get());
    }

    ObjectBridge::push(thread, instance);

    return 1;
}

// TODO: 98.80% (functional match)
static void pushLuaValue(ConstProperty p, lua_State* L)
{
    // (0024BC)  S_BPREL32: [FFFFFF40], Type:             0x3639, objects
    // (0024D0)  S_BPREL32: [FFFFFF50], Type:             0x36A2, end
    // (0024E0)  S_BPREL32: [FFFFFF48], Type:             0x36A2, iter

    PropertyDescriptor& descriptor = const_cast<PropertyDescriptor&>(p.getDescriptor());

    if (descriptor.type == Type::singleton<int>())
    {
        lua_pushinteger(L, p.getValue<int>());
        return;
    }

    if (descriptor.type == Type::singleton<bool>())
    {
        lua_pushboolean(L, p.getValue<bool>());
        return;
    }

    if (descriptor.type == Type::singleton<float>())
    {
        lua_pushnumber(L, p.getValue<float>());
        return;
    }

    if (descriptor.type == Type::singleton<std::string>())
    {
        lua_pushstring(L, p.getStringValue().c_str());
        return;
    }

    if (descriptor.type == Type::singleton<boost::shared_ptr<Instance>>())
    {
        ObjectBridge::push(L, p.getValue<boost::shared_ptr<Instance>>());
        return;
    }

    if (descriptor.type == Type::singleton<boost::shared_ptr<DescribedBase>>())
    {
        ObjectBridge::push(L, p.getValue<boost::shared_ptr<DescribedBase>>());
        return;
    }

    if (descriptor.type == Type::singleton<G3D::Vector3>())
    {
        Vector3Bridge::pushVector3(L, p.getValue<G3D::Vector3>());
        return;
    }

    if (descriptor.type == Type::singleton<G3D::CoordinateFrame>())
    {
        CoordinateFrameBridge::pushCoordinateFrame(L, p.getValue<G3D::CoordinateFrame>());
        return;
    }

    if (descriptor.type == Type::singleton<G3D::Color3>())
    {
        Color3Bridge::pushColor3(L, p.getValue<G3D::Color3>());
        return;
    }

    if (descriptor.type == Type::singleton<BrickColor>())
    {
        BrickColorBridge::pushNewObject(L, p.getValue<BrickColor>());
        return;
    }

    if (descriptor.type == Type::singleton<ContentId>())
    {
        lua_pushstring(L, p.getStringValue().c_str());
        return;
    }

    if (descriptor.type == Type::singleton<FunctionRef>())
    {
        lua_pushfunction(L, p.getValue<FunctionRef>());
        return;
    }

    if (descriptor.type == Type::singleton<boost::shared_ptr<Instances>>())
    {
        boost::shared_ptr<Instances> objects = p.getValue<boost::shared_ptr<Instances>>();
        if (objects)
        {
            Instances::const_iterator iter = objects->begin();
            Instances::const_iterator end = objects->end();

            // objects->size() doesn't match
            lua_createtable(L, end-iter, 0);

            for (int i = 1; iter != end; i++)
            {
                ObjectBridge::push(L, *iter);
                lua_rawseti(L, -2, i);
                ++iter;
            }
        }
        else
        {
            lua_newtable(L);
        }
        return;
    }

    EnumPropertyDescriptor* enumDesc = dynamic_cast<EnumPropertyDescriptor*>(&descriptor);
    if (enumDesc)
    {
        lua_pushinteger(L, enumDesc->getEnumValue(p.getInstance()));
        return;
    }

    RefPropertyDescriptor* refDesc = dynamic_cast<RefPropertyDescriptor*>(&descriptor);
    if (refDesc)
    {
        DescribedBase* ref = refDesc->getRefValue(p.getInstance());

        // this just seems strange /shrug
        if (ref)
            ObjectBridge::push(L, static_cast<Instance*>(ref)->shared_from_this());
        else
            ObjectBridge::push(L, boost::shared_ptr<Instance>());

        return;
    }

    throw std::runtime_error(G3D::format(
        "Unable to get property %s, type %s",
        descriptor.name.c_str(),
        descriptor.type.name.c_str()));
}

template<>
int ObjectBridge::on_index(const boost::shared_ptr<DescribedBase>& object, const char* name, lua_State* L)
{
    if (!object)
        throw std::runtime_error("The object has been deleted");

    const Name& name2 = Name::lookup(name);

    // what's with the scopes? they can't be inlines

    {
        PropertyIterator iter = object->findProperty(name2);
        if (iter != object->properties_end())
        {
            pushLuaValue(*iter, L);
            return 1;
        }
    }

    {
        FunctionIterator iter = object->findFunction(name2);
        if (iter != object->functions_end())
        {
            const FunctionDescriptor* fd = (*iter).getDescriptor();

            lua_pushlightuserdata(L, (void*)fd);
            lua_rawget(L, LUA_ENVIRONINDEX);

            if (lua_type(L, -1) == LUA_TNIL)
            {
                lua_pop(L, 1);
                lua_pushlightuserdata(L, (void*)fd);
                lua_pushcclosure(L, ObjectBridge::callMemberFunction, 1);
                lua_pushlightuserdata(L, (void*)fd);
                lua_pushvalue(L, -2);
                lua_settable(L, LUA_ENVIRONINDEX);
            }

            RBXASSERT(lua_type(L, -1) == LUA_TFUNCTION);

            return 1;
        }
    }

    {
        SignalIterator iter = object->findSignal(name2);
        if (iter != object->signals_end())
        {
            Signal s = *iter;
            SignalBridge::push(L, s.getSignalInstance());
            return 1;
        }
    }

    Instance* instance = dynamic_cast<Instance*>(object.get());
    if (instance)
    {
        Instance* child = instance->findFirstChildByName(name);
        if (child)
        {
            ObjectBridge::push(L, shared_from(child));
            return 1;
        }
    }

    if (name2.empty())
    {
        std::string pascalName = name;
        pascalName[0] = toupper(name[0]);

        if (pascalName[0] != name[0] && !Name::lookup(pascalName).empty())
            return on_index(object, pascalName.c_str(), L);
    }

    throw std::runtime_error(G3D::format("%s is not a valid member of %s", name, instance->getClassName().c_str()));
}

// TODO: 94.38% (functional match)
static void assignLuaValue(Property p, lua_State* L, int index)
{
    // (002DA8)  S_BPREL32: [FFFFFF60], Type:             0x238B, value

    PropertyDescriptor& descriptor = const_cast<PropertyDescriptor&>(p.getDescriptor());

    if (descriptor.type == Type::singleton<int>())
    {
        p.setValue<int>(lua_tointeger(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<bool>())
    {
        p.setValue<bool>(lua_toboolean(L, index) != 0);
        return;
    }

    if (descriptor.type == Type::singleton<float>())
    {
        p.setValue<float>(lua_tonumber(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<std::string>())
    {
        p.setValue<std::string>(lua_tostring(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<FunctionRef>())
    {
        p.setValue(FunctionRef(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<boost::shared_ptr<Instance>>())
    {
        p.setValue(ObjectBridge::getInstance(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<boost::shared_ptr<DescribedBase>>())
    {
        p.setValue(ObjectBridge::getPtr(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<G3D::Vector3>())
    {
        p.setValue(Vector3Bridge::getObject(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<G3D::CoordinateFrame>())
    {
        p.setValue(CoordinateFrameBridge::getObject(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<G3D::Color3>())
    {
        p.setValue(Color3Bridge::getObject(L, index));
        return;
    }

    if (descriptor.type == Type::singleton<BrickColor>())
    {
        p.setValue(BrickColorBridge::getObject(L, index));
        return;
    }

    // the contentid dtors for these two checks should be merged
    // seems like an inline, but i can't get it to work
    if (dynamic_cast<TypedPropertyDescriptor<SoundId>*>(&descriptor))
    {
        p.setValue<SoundId>(ContentId(lua_tostring(L, index)));
        return;
    }

    if (dynamic_cast<TypedPropertyDescriptor<TextureId>*>(&descriptor))
    {
        p.setValue<TextureId>(ContentId(lua_tostring(L, index)));
        return;
    }

    EnumPropertyDescriptor* enumDesc = dynamic_cast<EnumPropertyDescriptor*>(&descriptor);
    if (enumDesc)
    {
        int value = lua_tointeger(L, index);
        enumDesc->setEnumValue(p.getInstance(), value);
        return;
    }

    RefPropertyDescriptor* refDesc = dynamic_cast<RefPropertyDescriptor*>(&descriptor);
    if (refDesc)
    {
        boost::shared_ptr<Instance> value = ObjectBridge::getInstance(L, index);
        refDesc->setRefValue(p.getInstance(), value.get());
        return;
    }

    throw std::runtime_error(G3D::format("Unable to set property %s, type %s", descriptor.name.c_str(), descriptor.type.name.c_str()));
}

// TODO: 91.56%
// a lot of stack space gets wasted for some reason
template <>
void ObjectBridge::on_newindex(boost::shared_ptr<DescribedBase>& object, const char* name, lua_State* L)
{
    // (0033F8)  S_BPREL32: [FFFFFF68], Type:             0x3058, iter
    // (00340C)  S_BPREL32: [FFFFFF58], Type:             0x238B, parent (boost::shared_ptr<RBX::Instance>)

    if (!object)
        throw std::runtime_error("The object has been deleted");

    DescribedBase* objectPtr = object.get();
    PropertyIterator iter = object->findProperty(Name::lookup(name));
    if (iter != object->properties_end())
    {
        if ((*iter).getDescriptor() == Instance::propParent)
        {
            Instance* instance = dynamic_cast<Instance*>(objectPtr);

            if (!instance)
                throw std::runtime_error(G3D::format("%s is not a valid member of %s", name, object->classDescriptor().name.c_str()));

            boost::shared_ptr<Instance> parent = ObjectBridge::getInstance(L, 3);

            if (instance->getParent() != parent.get())
            {
                if (!instance->canSetParent(parent.get()))
                    StandardOut::singleton()->print(MESSAGE_WARNING, "%s should not be a child of %s", instance->getName().c_str(), parent->getName().c_str());

                instance->setParent2(parent);
            }
        }
        else
        {
            assignLuaValue(*iter, L, 3);    
        }

        return;
    }

    throw std::runtime_error(G3D::format("%s is not a valid member of %s", name, object->classDescriptor().name.c_str()));
}

int ObjectBridge::callMemberFunction(lua_State* L)
{
    int idx = lua_upvalueindex(1);
    RBXASSERT(lua_type(L, idx) == LUA_TLIGHTUSERDATA);
    Reflection::FunctionDescriptor* fd = static_cast<Reflection::FunctionDescriptor*>(lua_touserdata(L, idx));

    if (fd->security == FunctionDescriptor::NeedTrustedCaller)
        Security::Context::current().requirePermission(Security::Administrator, fd->name.c_str());

    boost::shared_ptr<Reflection::DescribedBase> instance;

    if (!getPtr(L, 1, instance) || !instance)
        throw std::runtime_error(G3D::format(
            "Did you forget a semicolon?  The first argument of member function %s must be an Object",
            fd->name.c_str()));

    if (!fd->isMemberOf(instance.get()))
        throw std::runtime_error(G3D::format(
        "The function %s is not a member of \"%s\"",
        fd->name.c_str(),
        instance->classDescriptor().name.c_str()));

    LuaArguments args(L, 1);
    fd->execute(instance.get(), args);
    return args.pushReturnValue();
}
