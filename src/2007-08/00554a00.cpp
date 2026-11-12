// from server: 0% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/script/LuaInstanceBridge.cpp

// Candidate translation unit (score above; library headers required).
#include "script/LuaInstanceBridge.h"

#include "lua/LuaBridge.h"
#include "lua/lua.hpp"
#include "reflection/function.h"
#include "reflection/object.h"
#include "reflection/property.h"
#include "script/LuaArguments.h"
#include "script/ThreadRef.h"
#include "security/SecurityContext.h"
#include "util/Name.h"
#include "util/Sound.h"
#include "util/TextureId.h"
#include "util/object.h"
#include "v8datamodel/BrickColor.h"
#include "v8datamodel/Decal.h"
#include "v8tree/Instance.h"

#include <G3D/Color3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>
#include <G3D/format.h>
#include <lua.h>
#include <stdexcept>

namespace RBX {
namespace Lua {

const luaL_Reg ObjectBridge::classLibrary[] = {
	{"new", newInstance},
	{NULL, NULL},
};

// FUNCTION: WEBSERVICE 0x100aaf70
// FUNCTION: ROBLOX 0x005fc5d0
void newweaktable(lua_State* L, const char* mode)
{
	lua_newtable(L);
	lua_pushvalue(L, -1);
	lua_setmetatable(L, -2);
	lua_pushliteral(L, "__mode");
	lua_pushstring(L, mode);
	lua_settable(L, -3);
}

} // namespace Lua
} // namespace RBX

// FUNCTION: WEBSERVICE 0x100abd50
// FUNCTION: ROBLOX 0x005fcd10
static void pushLuaValue(RBX::Reflection::ConstProperty p, lua_State* L)
{
	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<int>()) {
		lua_pushinteger(L, p.getValue<int>());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<bool>()) {
		lua_pushboolean(L, p.getValue<bool>());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<float>()) {
		lua_pushnumber(L, p.getValue<float>());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<double>()) {
		lua_pushnumber(L, p.getValue<double>());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<std::string>()) {
		lua_pushstring(L, p.getStringValue().c_str());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<boost::shared_ptr<RBX::Instance> >()) {
		RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::push(
			L, p.getValue<boost::shared_ptr<RBX::Instance> >()
		);
		return;
	}

	if (p.getDescriptor().type ==
		RBX::Reflection::Type::singleton<boost::shared_ptr<RBX::Reflection::DescribedBase> >()) {
		RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::push(
			L, p.getValue<boost::shared_ptr<RBX::Reflection::DescribedBase> >()
		);
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<G3D::Vector3>()) {
		RBX::Lua::Vector3Bridge::pushVector3(L, p.getValue<G3D::Vector3>());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<G3D::CoordinateFrame>()) {
		RBX::Lua::CoordinateFrameBridge::pushCoordinateFrame(L, p.getValue<G3D::CoordinateFrame>());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<G3D::Color3>()) {
		RBX::Lua::Color3Bridge::pushColor3(L, p.getValue<G3D::Color3>());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<RBX::BrickColor>()) {
		RBX::Lua::Bridge<RBX::BrickColor, 1>::pushNewObject(L, p.getValue<RBX::BrickColor>());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<RBX::ContentId>()) {
		lua_pushstring(L, p.getStringValue().c_str());
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<RBX::Lua::FunctionRef>()) {
		RBX::Lua::lua_pushfunction(L, p.getValue<RBX::Lua::FunctionRef>());
		return;
	}

	if (p.getDescriptor().type ==
		RBX::Reflection::Type::singleton<boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > >()) {
		boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > objects =
			p.getValue<boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > >();
		if (objects) {
			std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator iter = objects->begin();
			std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator end = objects->end();
			lua_createtable(L, end - iter, 0);
			int index = 1;
			while (iter != end) {
				RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::push(L, *iter);
				lua_rawseti(L, -2, index);
				++iter;
				++index;
			}
		}
		else {
			lua_newtable(L);
		}
		return;
	}

	const RBX::Reflection::EnumPropertyDescriptor* enumDescriptor =
		dynamic_cast<const RBX::Reflection::EnumPropertyDescriptor*>(&p.getDescriptor());
	if (enumDescriptor) {
		lua_pushinteger(L, enumDescriptor->getEnumValue(p.getInstance()));
		return;
	}

	const RBX::Reflection::RefPropertyDescriptor* refDescriptor =
		dynamic_cast<const RBX::Reflection::RefPropertyDescriptor*>(&p.getDescriptor());
	if (refDescriptor) {
		RBX::Reflection::DescribedBase* value = refDescriptor->getRefValue(p.getInstance());
		if (value) {
			RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::push(
				L, static_cast<RBX::Instance*>(value)->shared_from_this()
			);
		}
		else {
			RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::push(L, boost::shared_ptr<RBX::Instance>());
		}
		return;
	}

	throw std::runtime_error(
		G3D::format("Unable to get property %s, type %s", p.getName().c_str(), p.getDescriptor().type.name.name.c_str())
	);
}

namespace RBX {
namespace Lua {

// FUNCTION: WEBSERVICE 0x100ac300
// FUNCTION: ROBLOX 0x005fd2c0
boost::shared_ptr<Instance> ObjectBridge::getInstance(lua_State* L, unsigned int index)
{
	boost::shared_ptr<Reflection::DescribedBase> object = SharedPtrBridge<Reflection::DescribedBase>::getPtr(L, index);
	if (object && !dynamic_cast<Instance*>(object.get())) {
		throw std::runtime_error(
			G3D::format("Object %s is not an Instance", Reflection::ClassDescriptor::rootDescriptor().name.name.c_str())
		);
	}
	return shared_from(static_cast<Instance*>(object.get()));
}

} // namespace Lua
} // namespace RBX

// FUNCTION: WEBSERVICE 0x100ac420
// FUNCTION: ROBLOX 0x005fd3e0
static void assignLuaValue(RBX::Reflection::Property p, lua_State* L, int index)
{
	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<int>()) {
		p.setValue<int>(lua_tointeger(L, index));
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<bool>()) {
		p.setValue<bool>(lua_toboolean(L, index) != 0);
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<float>()) {
		p.setValue<float>(RBX::Lua::lua_tofloat(L, index));
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<std::string>()) {
		p.setValue<std::string>(lua_tostring(L, index));
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<RBX::Lua::FunctionRef>()) {
		p.setValue<RBX::Lua::FunctionRef>(RBX::Lua::FunctionRef(L, index));
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<boost::shared_ptr<RBX::Instance> >()) {
		p.setValue<boost::shared_ptr<RBX::Instance> >(RBX::Lua::ObjectBridge::getInstance(L, index));
		return;
	}

	if (p.getDescriptor().type ==
		RBX::Reflection::Type::singleton<boost::shared_ptr<RBX::Reflection::DescribedBase> >()) {
		p.setValue<boost::shared_ptr<RBX::Reflection::DescribedBase> >(
			RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::getPtr(L, index)
		);
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<G3D::Vector3>()) {
		p.setValue<G3D::Vector3>(RBX::Lua::Bridge<G3D::Vector3, 1>::getObject(L, index));
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<G3D::CoordinateFrame>()) {
		p.setValue<G3D::CoordinateFrame>(RBX::Lua::Bridge<G3D::CoordinateFrame, 1>::getObject(L, index));
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<G3D::Color3>()) {
		p.setValue<G3D::Color3>(RBX::Lua::Bridge<G3D::Color3, 1>::getObject(L, index));
		return;
	}

	if (p.getDescriptor().type == RBX::Reflection::Type::singleton<RBX::BrickColor>()) {
		p.setValue<RBX::BrickColor>(RBX::Lua::Bridge<RBX::BrickColor, 1>::getObject(L, index));
		return;
	}

	const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>* soundDescriptor =
		dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>*>(&p.getDescriptor());
	if (soundDescriptor) {
		p.setValue<RBX::Soundscape::SoundId>(RBX::ContentId(lua_tostring(L, index)));
		return;
	}

	const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>* textureDescriptor =
		dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>*>(&p.getDescriptor());
	if (textureDescriptor) {
		p.setValue<RBX::TextureId>(RBX::ContentId(lua_tostring(L, index)));
		return;
	}

	const RBX::Reflection::EnumPropertyDescriptor* enumDescriptor =
		dynamic_cast<const RBX::Reflection::EnumPropertyDescriptor*>(&p.getDescriptor());
	if (enumDescriptor) {
		enumDescriptor->setEnumValue(p.getInstance(), lua_tointeger(L, index));
		return;
	}

	const RBX::Reflection::RefPropertyDescriptor* refDescriptor =
		dynamic_cast<const RBX::Reflection::RefPropertyDescriptor*>(&p.getDescriptor());
	if (refDescriptor) {
		boost::shared_ptr<RBX::Instance> value = RBX::Lua::ObjectBridge::getInstance(L, index);
		refDescriptor->setRefValue(p.getInstance(), value.get());
		return;
	}

	throw std::runtime_error(
		G3D::format("Unable to set property %s, type %s", p.getName().c_str(), p.getDescriptor().type.name.name.c_str())
	);
}

namespace RBX {
namespace Lua {

// FUNCTION: WEBSERVICE 0x100ac9b0
// FUNCTION: ROBLOX 0x005fd970
template <>
void Bridge<boost::shared_ptr<Reflection::DescribedBase>, 0>::on_newindex(
	boost::shared_ptr<Reflection::DescribedBase>& object, const char* name, lua_State* L
)
{
	if (!object) {
		throw std::runtime_error("The object has been deleted");
	}

	const Name& propName = Name::lookup(name);

	Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::Iterator iter =
		object->findProperty(propName);
	if (iter != object->properties_end()) {
		if ((*iter).getDescriptor() == Instance::propParent) {
			Instance* instance = dynamic_cast<Instance*>(object.get());
			if (!instance) {
				throw std::runtime_error(
					G3D::format(
						"%s is not a valid member of %s",
						name,
						Reflection::ClassDescriptor::rootDescriptor().name.name.c_str()
					)
				);
			}

			boost::shared_ptr<Instance> parent = ObjectBridge::getInstance(L, 3);
			if (instance->getParent() != parent.get()) {
				if (!instance->canSetParent(parent.get())) {
					StandardOut::singleton()->print(
						MESSAGE_WARNING,
						"%s should not be a child of %s",
						instance->getName().c_str(),
						parent->getName().c_str()
					);
				}
				instance->setParent2(parent);
			}
		}
		else {
			assignLuaValue(*iter, L, 3);
		}
	}
	else {
		throw std::runtime_error(
			G3D::format(
				"%s is not a valid member of %s", name, Reflection::ClassDescriptor::rootDescriptor().name.name.c_str()
			)
		);
	}
}

// FUNCTION: WEBSERVICE 0x100ad180
// FUNCTION: ROBLOX 0x005fdc60
int ObjectBridge::newInstance(lua_State* thread)
{
	const Name& className = Name::lookup(lua_tostring(thread, 1));

	boost::shared_ptr<Instance> instance = Instance::create(className);
	if (lua_gettop(thread) >= 2) {
		boost::shared_ptr<Instance> parent = getInstance(thread, 2);
		if (parent) {
			instance->setParent(parent.get());
		}
	}

	push(thread, instance);
	return 1;
}

// FUNCTION: WEBSERVICE 0x100ad2e0
// FUNCTION: ROBLOX 0x005fddc0
int ObjectBridge::callMemberFunction(lua_State* L)
{
	const Reflection::FunctionDescriptor* desc =
		static_cast<const Reflection::FunctionDescriptor*>(lua_touserdata(L, lua_upvalueindex(1)));

	if (desc->security == Reflection::FunctionDescriptor::NeedTrustedCaller) {
		Security::Context::current().requirePermission(Security::Administrator, desc->name.name.c_str());
	}

	boost::shared_ptr<Reflection::DescribedBase> instance;

	if (!getPtr(L, 1, instance) || !instance) {
		throw std::runtime_error(
			G3D::format(
				"Did you forget a semicolon?  The first argument of member function %s must be an Object",
				desc->name.name.c_str()
			)
		);
	}

	if (!desc->isMemberOf(instance.get())) {
		throw std::runtime_error(
			G3D::format(
				"The function %s is not a member of \"%s\"",
				desc->name.name.c_str(),
				Reflection::ClassDescriptor::rootDescriptor().name.name.c_str()
			)
		);
	}

	LuaArguments args(L, 1);
	desc->execute(instance.get(), args);
	return args.pushReturnValue();
}

// FUNCTION: WEBSERVICE 0x100ad4b0
// FUNCTION: ROBLOX 0x005fdf90
template <>
int Bridge<boost::shared_ptr<Reflection::DescribedBase>, 0>::on_index(
	const boost::shared_ptr<Reflection::DescribedBase>& object, const char* name, lua_State* L
)
{
	if (!object) {
		throw std::runtime_error("The object has been deleted");
	}

	const Name& memberName = Name::lookup(name);

	{
		Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::Iterator iter =
			object->findProperty(memberName);
		if (iter != object->properties_end()) {
			pushLuaValue(*iter, L);
			return 1;
		}
	}

	{
		Reflection::MemberDescriptorContainer<Reflection::FunctionDescriptor>::ConstIterator iter =
			object->findFunction(memberName);
		if (iter != object->functions_end()) {
			const Reflection::FunctionDescriptor* descriptor = (*iter).getDescriptor();

			lua_pushlightuserdata(L, (void*) descriptor);
			lua_rawget(L, LUA_ENVIRONINDEX);
			if (lua_isnil(L, -1)) {
				lua_pop(L, 1);

				lua_pushlightuserdata(L, (void*) descriptor);
				lua_pushcclosure(L, ObjectBridge::callMemberFunction, 1);

				lua_pushlightuserdata(L, (void*) descriptor);
				lua_pushvalue(L, -2);
				lua_settable(L, LUA_ENVIRONINDEX);
			}

			return 1;
		}
	}

	{
		Reflection::MemberDescriptorContainer<Reflection::SignalDescriptor>::Iterator iter =
			object->findSignal(memberName);
		if (iter != object->signals_end()) {
			Reflection::Signal s = *iter;
			SharedPtrBridge<Reflection::SignalInstance>::push(L, s.getSignalInstance());
			return 1;
		}
	}

	Instance* instance = dynamic_cast<Instance*>(object.get());
	if (instance) {
		Instance* child = instance->findFirstChildByName(name);
		if (child) {
			SharedPtrBridge<Reflection::DescribedBase>::push(L, shared_from(child));
			return 1;
		}
	}

	if (&Name::getNullName() == &memberName) {
		std::string name2 = name;
		name2[0] = toupper(name[0]);
		if (name2[0] != name[0] && !Name::lookup(name2).empty()) {
			return on_index(object, name2.c_str(), L);
		}
	}

	throw std::runtime_error(G3D::format("%s is not a valid member of %s", name, instance->getClassName().c_str()));
}

} // namespace Lua
} // namespace RBX

template bool RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::DescribedBase>, 0>::getValue<
	boost::shared_ptr<RBX::Reflection::DescribedBase> >(
	lua_State* L, unsigned int index, boost::shared_ptr<RBX::Reflection::DescribedBase>& value
);

template boost::shared_ptr<RBX::Reflection::DescribedBase> RBX::Lua::SharedPtrBridge<
	RBX::Reflection::DescribedBase>::getPtr(lua_State* L, unsigned int index);

template const RBX::Name& RBX::Name::doDeclare<RBX::sDecal>();
template const RBX::Name& RBX::Name::doDeclare<RBX::sTexture>();
template void RBX::Name::callDoDeclare<RBX::sDecal>();
template void RBX::Name::callDoDeclare<RBX::sTexture>();

template bool RBX::Reflection::ConstProperty::getValue<bool>() const;
template float RBX::Reflection::ConstProperty::getValue<float>() const;
template int RBX::Reflection::ConstProperty::getValue<int>() const;
template double RBX::Reflection::ConstProperty::getValue<double>() const;
template G3D::Vector3 RBX::Reflection::ConstProperty::getValue<G3D::Vector3>() const;
template G3D::CoordinateFrame RBX::Reflection::ConstProperty::getValue<G3D::CoordinateFrame>() const;
template G3D::Color3 RBX::Reflection::ConstProperty::getValue<G3D::Color3>() const;
template RBX::BrickColor RBX::Reflection::ConstProperty::getValue<RBX::BrickColor>() const;

template void RBX::Reflection::Property::setValue<bool>(const bool& value);
template void RBX::Reflection::Property::setValue<float>(const float& value);
template void RBX::Reflection::Property::setValue<int>(const int& value);
template void RBX::Reflection::Property::setValue<G3D::Vector3>(const G3D::Vector3& value);
template void RBX::Reflection::Property::setValue<G3D::CoordinateFrame>(const G3D::CoordinateFrame& value);
template void RBX::Reflection::Property::setValue<G3D::Color3>(const G3D::Color3& value);
template void RBX::Reflection::Property::setValue<RBX::BrickColor>(const RBX::BrickColor& value);

template void RBX::Reflection::Property::setValue<RBX::TextureId>(const RBX::TextureId& value);

template void RBX::Reflection::Property::setValue<RBX::Soundscape::SoundId>(const RBX::Soundscape::SoundId& value);
