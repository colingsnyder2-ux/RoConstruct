// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_claudeM_1feff24e20b19cb1.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/enumconverter.h", "roc_enum_item_genuine_owner_header4eec83b4b5d2a3a5.cpp")
#pragma include_alias("reflection/enumConverter.h", "roc_enum_item_genuine_owner_header4eec83b4b5d2a3a5.cpp")
#pragma include_alias("reflection/property.h", "roc_espeon_luapropertyenumitemexternal80d2c317f95c3a46.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_espeon_luainstanceexternalancestorsfe6ba092ad87ac69.cpp")
#include "roc_genuine_lua_singleton_enum_headerf079742c7efc6c9f.cpp"
namespace RBX { namespace Lua { template<> const char* Bridge<EnumDescriptorItemPtr, false>::className = "EnumItem"; } }
// Native setter reloads its descriptor across type branches. Getter retains
// its genuine source alias: removing it reduced the measured similarity.
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

namespace RBX { namespace Lua { extern const char* throwable_lua_tostring(lua_State*, int); } }

// matches generally aren't very good here

inline const RBX::Name& RBX::Reflection::ConstProperty::getName() const {return descriptor->name;}
using namespace RBX;
using namespace RBX::Lua;
using namespace RBX::Reflection;
using namespace RBX::Soundscape;

namespace RBX {

class DataModel:public Instance {public: char gap[0x21c-sizeof(Instance)];Instance* guiRoot;char gap2[4];Instance* guiHooks;};
}
struct NativePermissionContext {unsigned long identity;void report(int,const char*);};
extern "C" NativePermissionContext* __cdecl nativePermissionContext();
extern bool __cdecl nativeHasPermission(unsigned long,int);
static __declspec(noinline) void nativeCheckModification(RBX::Instance* instance){
 if(nativeHasPermission(nativePermissionContext()->identity,1))return;
 if(dynamic_cast<RBX::Stats::StatsService*>(instance))nativePermissionContext()->report(1,"modify a StatsService");
 RBX::Instance* root=instance->getParent()?instance->getParent()->getRootAncestor():instance;
 RBX::DataModel* model=dynamic_cast<RBX::DataModel*>(root);
 if(model){
 if(model->guiRoot==instance||model->guiRoot->isAncestorOf(instance))nativePermissionContext()->report(1,"GuiRoot");
 if(model->guiHooks==instance||model->guiHooks->isAncestorOf(instance))nativePermissionContext()->report(1,"GuiHooks");
 }
}
// Declare the real specialization before explicit registration instantiation.
// The public registration path below emits the otherwise unused callbacks.
template<> void ObjectBridge::on_newindex(boost::shared_ptr<DescribedBase>&,const char*,lua_State*);


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

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<Instance>>())
    {
        ObjectBridge::push(L, p.getValue<boost::shared_ptr<Instance>>());
        return;
    }

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<DescribedBase>>())
    {
        ObjectBridge::push(L, p.getValue<boost::shared_ptr<DescribedBase>>());
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

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<Instances>>())
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

    EnumPropertyDescriptor* enumDesc = dynamic_cast<EnumPropertyDescriptor*>(&const_cast<PropertyDescriptor&>(p.getDescriptor()));
    if (enumDesc)
    {
        EnumItem::push(L, enumDesc->getEnumItem(p.getInstance()));
        return;
    }

    RefPropertyDescriptor* refDesc = dynamic_cast<RefPropertyDescriptor*>(&const_cast<PropertyDescriptor&>(p.getDescriptor()));
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
        p.getName().c_str(),
        p.getDescriptor().type.name.c_str()));
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

            // No function-type assertion in the target callback.

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
// Native0061b190 is a separate callee; preserve the observed boundary.
static __declspec(noinline) void assignLuaValue(Property p, lua_State* L, int index)
{
    // (002DA8)  S_BPREL32: [FFFFFF60], Type:             0x238B, value


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
        p.setValue<float>(lua_tonumber(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<double>())
    {
        p.setValue<double>(lua_tonumber(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<std::string>())
    {
        p.setValue<std::string>(throwable_lua_tostring(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<FunctionRef>())
    {
        p.setValue(FunctionRef(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<Instance>>())
    {
        p.setValue(ObjectBridge::getInstance(L, index));
        return;
    }

    if (p.getDescriptor().type == Type::singleton<boost::shared_ptr<DescribedBase>>())
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

    // the contentid dtors for these two checks should be merged
    // seems like an inline, but i can't get it to work
    if (dynamic_cast<TypedPropertyDescriptor<SoundId>*>(const_cast<PropertyDescriptor*>(&p.getDescriptor())))
    {
        p.setValue<SoundId>(ContentId(throwable_lua_tostring(L, index)));
        return;
    }

    if (dynamic_cast<TypedPropertyDescriptor<TextureId>*>(const_cast<PropertyDescriptor*>(&p.getDescriptor())))
    {
        p.setValue<TextureId>(ContentId(throwable_lua_tostring(L, index)));
        return;
    }

	const EnumPropertyDescriptor* enumDesc = dynamic_cast<const EnumPropertyDescriptor*>(&p.getDescriptor());
	if (enumDesc!=NULL)
	{
		EnumDescriptorItemPtr item;
		if (EnumItem::getItem(L, index, item))
		{
			if (!enumDesc->setEnumItem(p.getInstance(), *item))
				throw std::runtime_error(G3D::format("Invalid type %s for enum %s", item->owner.name.c_str(), enumDesc->name.c_str()));
		}
		else if (lua_isnumber(L, index))
		{
			if (!enumDesc->setEnumValue(p.getInstance(), lua_tointeger(L, index) ))
				throw std::runtime_error(G3D::format("Invalid value %d for enum %s", static_cast<int>(lua_tointeger(L, index)), enumDesc->name.c_str()));
		}
		else if (lua_isstring(L, index))
		{
			if (!enumDesc->setStringValue(p.getInstance(), lua_tostring(L, index)))
				throw std::runtime_error(G3D::format("Invalid value \"%s\" for enum %s", lua_tostring(L, index), enumDesc->name.c_str()));
		} 
		else
			throw std::runtime_error(G3D::format("Invalid value for enum %s", enumDesc->name.c_str()));
		return;
	}


    RefPropertyDescriptor* refDesc = dynamic_cast<RefPropertyDescriptor*>(const_cast<PropertyDescriptor*>(&p.getDescriptor()));
    if (refDesc)
    {
        boost::shared_ptr<Instance> value = ObjectBridge::getInstance(L, index);
        refDesc->setRefValue(p.getInstance(), value.get());
        return;
    }

    const char* typeName=p.getDescriptor().type.name.c_str();
    const char* propertyName=p.getName().c_str();
    throw std::runtime_error(G3D::format("Unable to set property %s, type %s", propertyName, typeName));
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

    nativeCheckModification(dynamic_cast<Instance*>(object.get()));

    
    const Name& propertyName = Name::lookup(name);
    PropertyIterator iter = object->findProperty(propertyName);
    if (iter != object->properties_end())
    {
        if ((*iter).getDescriptor() == Instance::propParent)
        {
            Instance* instance = dynamic_cast<Instance*>(object.get());

            if (!instance)
                throw std::runtime_error(G3D::format("%s is not a valid member of %s", name, object->getDescriptor().name.c_str()));

            boost::shared_ptr<Instance> parent = ObjectBridge::getInstance(L, 3);

            if (instance->getParent() != parent.get())
            {
                if (!instance->canSetParent(parent.get()))
                    StandardOut::singleton()->print(MESSAGE_WARNING, "%s should not be a child of %s", instance->getFullName().c_str(), parent->getFullName().c_str());

                instance->setParent2(parent);
            }
        }
        else
        {
            assignLuaValue(*iter, L, 3);    
        }

        return;
    }

    throw std::runtime_error(G3D::format("%s is not a valid member of %s", name, object->getDescriptor().name.c_str()));
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

// Public native registration path takes the real Lua metamethod callbacks.
// Explicitly instantiate it so MSVC emits the otherwise unused specialization.
template void RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::registerClass(lua_State*);
