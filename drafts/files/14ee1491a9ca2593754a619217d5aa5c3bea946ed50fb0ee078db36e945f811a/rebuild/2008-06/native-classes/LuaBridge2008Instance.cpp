// Inactive 2008-06 native recovery: RBX::Lua instance bridge (ObjectBridge).
// Body shapes follow the donor reconstruction; counted rows are proven by tests/record_native_lua_bridge2008.py.
// NATIVE_LUABRIDGE_PENDING guards code that needs declarations the shared native headers lack
// (RBX::Instances / Instance::setParent2 in v8tree/Instance.h, and the donor LuaArguments.h that needs Instances).
#include "LuaBridge2008/LuaSignalBridge2008.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "LuaBridge2008/LuaArguments2008.h"
#ifdef NATIVE_LUABRIDGE_PENDING
#include "script/LuaArguments.h"
#endif
#include "script/ThreadRef.h"
#include "util/Sound.h"
#include "util/TextureId.h"
#include "util/standardout.h"
#include "v8tree/Instance.h"
#include "G3D/format.h"
#include "G3D/Vector3.h"


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

// 0061a5f0 / 0061bcb0: LuaArguments size() / get(int, Value&) (vtable 00844174 slots 0 / 1).
size_t LuaArguments2008::size() const
{
    return lua_gettop(L) - 1;
}

void LuaArguments2008::get(int index, Reflection::Value& value) const
{
    get(L, index + offset, value, true);
}

const luaL_Reg ObjectBridge::classLibrary[] = 
{
    {"new", ObjectBridge::newInstance},
    {NULL, NULL}
};

int ObjectBridge::newInstance(lua_State* thread)
{
    const Name& name = Name::lookup(tostringChecked(thread, 1));
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

#ifdef NATIVE_LUABRIDGE_PENDING
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

#endif
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

#ifdef NATIVE_LUABRIDGE_PENDING
                instance->setParent2(parent);
#endif
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

#ifdef NATIVE_LUABRIDGE_PENDING
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
#endif

// Template instances of this unit whose callers are the pending property paths (0061abe0 / 0061b190 / 0061c0e0, guarded
// by NATIVE_LUABRIDGE_PENDING above or not yet recovered): instantiated explicitly so that the unit emits them.
//   0061a720 SharedPtrBridge<DescribedBase>::getPtr<shared_ptr<DescribedBase>> (called from 0061c152), which calls
//   0061a560 Bridge<shared_ptr<DescribedBase>>::getValue<shared_ptr<DescribedBase>> (0061a78b);
//   0061a470 Bridge<EnumItem>::getValue<const EnumDescriptor::Item*> (EnumItem className 0095b1dc; called from 0061b6db);
//   0061a7b0 TypedPropertyDescriptor<ContentId>::getValue (ICF-folded getset forwarder; called from this unit's
//   0061a834 / 0061a8a4 / 0061a914 / 0061a984 and from other units).
namespace RBX { namespace Lua {
template bool Bridge<EnumDescriptorItemPtr, false>::getValue<EnumDescriptorItemPtr>(lua_State*, size_t,
    EnumDescriptorItemPtr&);
template bool SharedPtrBridge<Reflection::DescribedBase>::getPtr<boost::shared_ptr<Reflection::DescribedBase> >(
    lua_State*, size_t, boost::shared_ptr<Reflection::DescribedBase>&);
}}
template ContentId Reflection::TypedPropertyDescriptor<ContentId>::getValue(const Reflection::DescribedBase*) const;

// pass 4: ConstProperty::getValue<T> / Property::setValue<T> (declared in the read-only native reflection/property.h,
// defined in no native header): checked pointer dynamic_cast of the descriptor to TypedPropertyDescriptor<T> (the type
// descriptor pushed in each body names T), std::bad_cast on failure, then the getset getValue / setValue slot. Defined
// after the property paths above so that, as in the target, they stay out of line. The instances are the forwarders
// 0061a600..0061aa60 (callers 0061ad51 / 0061adba / 0061af11 / 0061af6b / 0061b30d / 0061b36d / 0061b3d0 / 0061b433 /
// 0061b5c2 / 0061b669 in the pending property paths).
namespace RBX { namespace Reflection {
template<typename T>
T ConstProperty::getValue() const
{
    const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(&getDescriptor());
    if (typed == NULL)
        throw std::bad_cast();
    return typed->getValue(getInstance());
}

template<typename T>
void Property::setValue(const T& value)
{
    const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(&getDescriptor());
    if (typed == NULL)
        throw std::bad_cast();
    typed->setValue(getInstance(), value);
}

template boost::shared_ptr<Instance> ConstProperty::getValue<boost::shared_ptr<Instance> >() const;
template boost::shared_ptr<DescribedBase> ConstProperty::getValue<boost::shared_ptr<DescribedBase> >() const;
template Lua::FunctionRef ConstProperty::getValue<Lua::FunctionRef>() const;
template boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >
    ConstProperty::getValue<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >() const;
template void Property::setValue<std::string>(const std::string&);
template void Property::setValue<Soundscape::SoundId>(const Soundscape::SoundId&);
template void Property::setValue<TextureId>(const TextureId&);
template void Property::setValue<Lua::FunctionRef>(const Lua::FunctionRef&);
template void Property::setValue<boost::shared_ptr<Instance> >(const boost::shared_ptr<Instance>&);
template void Property::setValue<boost::shared_ptr<DescribedBase> >(const boost::shared_ptr<DescribedBase>&);
}}
