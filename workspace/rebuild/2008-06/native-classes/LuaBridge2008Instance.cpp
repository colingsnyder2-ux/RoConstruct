// Inactive 2008-06 native recovery: RBX::Lua instance bridge (ObjectBridge).
// Body shapes follow the donor reconstruction; counted rows are proven by tests/record_native_lua_bridge2008.py.
// NATIVE_LUABRIDGE_PENDING guards code that needs declarations the shared native headers lack
// (RBX::Instances / Instance::setParent2 in v8tree/Instance.h, and the donor LuaArguments.h that needs Instances).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
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
#ifdef NATIVE_LUABRIDGE_PENDING
#include "v8datamodel/DataModel.h"
#include "gui/Gui.h"
#include "v8datamodel/Stats.h"
#include "security/SecurityContext.h"
#endif
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

// 0061abe0: file-local pushLuaValue (called from on_index 0061c2c0 and the LuaArguments push paths). The 2008 body
// tests p.getDescriptor().type against Type::singleton<T>() in this order: int, bool, float, double (0056cd10 /
// getValue 004adc90), std::string, shared_ptr<Instance>, shared_ptr<DescribedBase>, Vector3, CoordinateFrame, Color3,
// BrickColor, ContentId, FunctionRef, shared_ptr<const vector<shared_ptr<Instance> > > (0056cb50 / 0061a930, a table
// built with lua_createtable(L, end - begin, 0)), then the enum and ref descriptors and the throw. The target receives
// L in esi (custom convention of a file-local function) and keeps a 64-byte aligned frame.
// Remaining blocker: the enum branch calls EnumPropertyDescriptor vtable slot 16 (+0x40; e.g. 00448740, returns the
// const EnumDescriptor::Item* at index getEnumValue() of the enum's item vector) and pushes it with
// Bridge<EnumItem>::pushNewObject 005a9bd0. The core reflection/property.h declares only 16 slots (no such virtual),
// so the enum branch below keeps the donor lua_pushinteger shape.
static void pushLuaValue(ConstProperty p, lua_State* L)
{
    if (p.getDescriptor().type == Type::singleton<int>())
    {
        lua_pushinteger(L, p.getValue<int>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<bool>())
    {
        lua_pushboolean(L, p.getValue<bool>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<float>())
    {
        lua_pushnumber(L, p.getValue<float>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<double>())
    {
        lua_pushnumber(L, p.getValue<double>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<std::string>())
    {
        lua_pushstring(L, p.getStringValue().c_str());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<Instance> >())
    {
        ObjectBridge::push(L, p.getValue<boost::shared_ptr<Instance> >());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<DescribedBase> >())
    {
        ObjectBridge::push(L, p.getValue<boost::shared_ptr<DescribedBase> >());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<G3D::Vector3>())
    {
        Vector3Bridge::pushVector3(L, p.getValue<G3D::Vector3>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<G3D::CoordinateFrame>())
    {
        CoordinateFrameBridge::pushCoordinateFrame(L, p.getValue<G3D::CoordinateFrame>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<G3D::Color3>())
    {
        Color3Bridge::pushColor3(L, p.getValue<G3D::Color3>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<BrickColor>())
    {
        BrickColorBridge::pushNewObject(L, p.getValue<BrickColor>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<ContentId>())
    {
        lua_pushstring(L, p.getStringValue().c_str());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<FunctionRef>())
    {
        lua_pushfunction(L, p.getValue<FunctionRef>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >())
    {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > objects =
            p.getValue<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >();
        if (objects)
        {
            std::vector<boost::shared_ptr<Instance> >::const_iterator iter = objects->begin();
            std::vector<boost::shared_ptr<Instance> >::const_iterator end = objects->end();

            lua_createtable(L, end - iter, 0);

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

    PropertyDescriptor& descriptor = const_cast<PropertyDescriptor&>(p.getDescriptor());
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

// 0061c2c0: ObjectBridge::on_index (Bridge<shared_ptr<DescribedBase>>::on_index(const shared_ptr&, const char*,
// lua_State*)); pushes 0061c0e0 (callMemberFunction) at 0061c476.
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

            // 0061c2c0 has no lua_type(L, -1) check here: the donor's RBXASSERT(lua_type(L, -1) == LUA_TFUNCTION)
            // (a global-flag test, lua_type and a failure call) is absent from the 2008-06 body.

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

// 0061b190: file-local assignLuaValue (called from on_newindex 0061bda0). Test order (p.getDescriptor().type against
// Type::singleton<T>()): int, bool, float, double (both through tonumberClamped 0061c830), std::string
// (tostringChecked 0061c7b0), FunctionRef, shared_ptr<Instance>, shared_ptr<DescribedBase>, Vector3, CoordinateFrame,
// Color3, BrickColor; then SoundId / TextureId typed descriptors (dynamic_cast), the enum descriptor (EnumItem userdata
// through setEnumItem 0061a400, a number through setEnumValue (vtable +0x3c), a string through setStringValue
// (+0x20), each failing with its own "Invalid ... for enum %s" message 00844240 / 00844220 / 00844200 / 008441e4),
// the ref descriptor and the throw 008441c0. The target receives index in ecx and L in edi (custom convention of a
// file-local function; this /c compile reproduces it).
// Closest (2026-11-19): 2171 B against 2168 B, identical through 0061b9b0; only the final throw differs: the target
// reads the descriptor name string through the Name* with folded displacements (mov ecx,[ecx+4]; [ecx+0x1c] / [ecx+8])
// while this compile materializes Name+4 (add eax,4) and keeps the type string in esi. Rejected for that tail:
// p.getDescriptor() in the arguments, a local descriptor reference (kept), descriptor.name.name.c_str().
// pushLuaValue 0061abe0 shows the same tail difference after its enum branch.
static void assignLuaValue(Property p, lua_State* L, int index)
{
    if (p.getDescriptor().type == Type::singleton<int>())
    {
        p.setValue<int>(lua_tointeger(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<bool>())
    {
        p.setValue<bool>(lua_toboolean(L, index) != 0);
        return;
    }

    if (p.getDescriptor().type == Type::singleton<float>())
    {
        p.setValue<float>(tonumberClamped(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<double>())
    {
        p.setValue<double>(tonumberClamped(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<std::string>())
    {
        p.setValue<std::string>(tostringChecked(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<FunctionRef>())
    {
        p.setValue(FunctionRef(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<Instance> >())
    {
        p.setValue(ObjectBridge::getInstance(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<DescribedBase> >())
    {
        p.setValue(ObjectBridge::getPtr(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<G3D::Vector3>())
    {
        p.setValue(Vector3Bridge::getObject(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<G3D::CoordinateFrame>())
    {
        p.setValue(CoordinateFrameBridge::getObject(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<G3D::Color3>())
    {
        p.setValue(Color3Bridge::getObject(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<BrickColor>())
    {
        p.setValue(BrickColorBridge::getObject(L, index));
        return;
    }

    if (dynamic_cast<const TypedPropertyDescriptor<SoundId>*>(&p.getDescriptor()))
    {
        p.setValue<SoundId>(ContentId(tostringChecked(L, index)));
        return;
    }

    if (dynamic_cast<const TypedPropertyDescriptor<TextureId>*>(&p.getDescriptor()))
    {
        p.setValue<TextureId>(ContentId(tostringChecked(L, index)));
        return;
    }

    if (const EnumPropertyDescriptor* enumDesc = dynamic_cast<const EnumPropertyDescriptor*>(&p.getDescriptor()))
    {
        const EnumDescriptor::Item* item;
        if (Bridge<EnumDescriptorItemPtr, false>::getValue(L, index, item))
        {
            if (!enumDesc->setEnumItem(p.getInstance(), *item))
                throw std::runtime_error(G3D::format("Invalid type %s for enum %s", item->owner.name.c_str(),
                    enumDesc->name.c_str()));
        }
        else if (lua_isnumber(L, index))
        {
            if (!enumDesc->setEnumValue(p.getInstance(), lua_tointeger(L, index)))
                throw std::runtime_error(G3D::format("Invalid value %d for enum %s", lua_tointeger(L, index),
                    enumDesc->name.c_str()));
        }
        else if (lua_isstring(L, index))
        {
            if (!enumDesc->setStringValue(p.getInstance(), lua_tostring(L, index)))
                throw std::runtime_error(G3D::format("Invalid value \"%s\" for enum %s", lua_tostring(L, index),
                    enumDesc->name.c_str()));
        }
        else
        {
            throw std::runtime_error(G3D::format("Invalid value for enum %s", enumDesc->name.c_str()));
        }
        return;
    }

    if (const RefPropertyDescriptor* refDesc = dynamic_cast<const RefPropertyDescriptor*>(&p.getDescriptor()))
    {
        boost::shared_ptr<Instance> value = ObjectBridge::getInstance(L, index);
        refDesc->setRefValue(p.getInstance(), value.get());
        return;
    }

    const PropertyDescriptor& descriptor = p.getDescriptor();
    throw std::runtime_error(G3D::format("Unable to set property %s, type %s", descriptor.name.c_str(),
        descriptor.type.name.c_str()));
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

// NATIVE_LUABRIDGE_PENDING: the write-access check 0061bcd0 calls Instance::getRootAncestor() 0042a5f0 and
// Instance::isAncestorOf(const Instance*) const 004c9c50, which the core native v8tree/Instance.h does not declare
// (owner: v8tree/Instance.h). callMemberFunction 0061c0e0 calls 0061bcd0 at 0061c185, so it stays guarded with it.
// Diagnostic compile with the check removed (2026-11-15): 451 B against 478 B; every difference is the missing
// dynamic_cast + 0061bcd0 call and the register allocation that follows; the LuaArguments2008 construction, execute
// and pushReturnValue -> push 005aba50 sequence (0061c1f6..0061c264) is identical. The esi-argument convention of
// 0061bcd0 is not a whole-program artifact: this /c compile gives the file-local pushLuaValue / assignLuaValue the same
// register-argument conventions as the target (2026-11-19), so the declarations are the remaining blocker.
#ifdef NATIVE_LUABRIDGE_PENDING
// 0061bcd0: write-access check called from 0061be19 (on_newindex) and 0061c185 (callMemberFunction) right after the
// dynamic_cast<Instance*> of the object. Name not established (file-local; no registry name). Without Administrator
// permission (Context::isInRole 005cf070 with identity and 1): StatsService (RTTI 0093244c) needs "modify a StatsService";
// the root DataModel (getRootAncestor 0042a5f0 of the parent, the object itself when it has none; RTTI 0092e8a0) guards
// guiRoot (+0x21c) "GuiRoot" and guiHooks (+0x224) "GuiHooks" and their descendants (isAncestorOf 004c9c50).
// The target passes the Instance* in esi (custom convention of a file-local function, reproducible by a /c compile).
static void checkWriteAccess(Instance* instance)
{
    if (Security::Context::current().hasPermission(Security::Administrator))
        return;

    if (dynamic_cast<Stats::StatsService*>(instance))
        Security::Context::current().requirePermission(Security::Administrator, "modify a StatsService");

    Instance* root = instance->getParent() ? instance->getParent()->getRootAncestor() : instance;
    DataModel* dataModel = dynamic_cast<DataModel*>(root);
    if (dataModel)
    {
        Instance* guiRoot = dataModel->guiRoot.get();
        if (guiRoot == instance || guiRoot->isAncestorOf(instance))
            Security::Context::current().requirePermission(Security::Administrator, "GuiRoot");

        Instance* guiHooks = dataModel->guiHooks.get();
        if (guiHooks == instance || guiHooks->isAncestorOf(instance))
            Security::Context::current().requirePermission(Security::Administrator, "GuiHooks");
    }
}

// 0061c0e0: the closure pushed by on_index 0061c2c0 (push 0x61c0e0 at 0061c476) for a member function. fd is the
// light userdata upvalue (lua_touserdata(L, lua_upvalueindex(1)) 00612120); a nonzero security (+0x10) is passed as the
// permission to Context::requirePermission 00489810 with the function name; getPtr<shared_ptr<DescribedBase>> 0061a720
// of argument 1; isMemberOf 00570c40; LuaArguments (vtable 00844174, offset 1, L) built on the stack, execute (vtable
// slot 1), then the static push 005aba50 of returnValue.
int ObjectBridge::callMemberFunction(lua_State* L)
{
    const Reflection::FunctionDescriptor* fd =
        static_cast<const Reflection::FunctionDescriptor*>(lua_touserdata(L, lua_upvalueindex(1)));

    // INFERRED: the 2008 security value is used directly as a Security::Permissions (cmp [fd+0x10], 0 then pushed
    // unchanged at 0061c12e); the read-only native reflection/function.h names it FunctionDescriptor::Security.
    if (fd->security)
        Security::Context::current().requirePermission(static_cast<Security::Permissions>(fd->security), fd->name.c_str());

    boost::shared_ptr<Reflection::DescribedBase> instance;

    if (!getPtr(L, 1, instance) || !instance)
        throw std::runtime_error(G3D::format(
            "Did you forget a semicolon?  The first argument of member function %s must be an Object",
            fd->name.c_str()));

    checkWriteAccess(dynamic_cast<Instance*>(instance.get()));

    if (!fd->isMemberOf(instance.get()))
        throw std::runtime_error(G3D::format(
            "The function %s is not a member of \"%s\"",
            fd->name.c_str(),
            instance->classDescriptor().name.c_str()));

    LuaArguments2008 args(L, 1);
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Lua::Bridge<G3D::CoordinateFrame,1>;
template class RBX::Lua::Bridge<G3D::Vector3,1>;
template class RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>,0>;
template class RBX::Lua::SharedPtrBridge<RBX::Reflection::SignalInstance>;
template class RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>;
template class RBX::Reflection::TypedPropertyDescriptor<G3D::CoordinateFrame>;
template class RBX::Reflection::TypedPropertyDescriptor<RBX::ContentId>;
template class RBX::Reflection::TypedPropertyDescriptor<RBX::Lua::FunctionRef>;
template class RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>;
template class RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>;
template class RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<RBX::Instance> >;
template class RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<RBX::Reflection::DescribedBase> >;
template class RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > const > >;
template class RBX::Reflection::TypedPropertyDescriptor<int>;
template class boost::shared_ptr<RBX::Reflection::DescribedBase>;
template class boost::shared_ptr<RBX::Reflection::SignalInstance>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<G3D::CoordinateFrame>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<RBX::ContentId>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<RBX::Lua::FunctionRef>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<RBX::Instance> >::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<RBX::Reflection::DescribedBase> >::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > const > >::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<int>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >::GetSet>;
