// from server: 0% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/script/LuaInstanceBridge.cpp

// Candidate translation unit (score above; library headers required).
#include "script/LuaInstanceBridge.h"

#include "lua/LuaBridge.h"
#include "lua/lua.h"
#include "reflection/object.h"
#include "reflection/property.h"
#include "script/ThreadRef.h"
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

// FUNCTION: WEBSERVICE 0x100aaf70
void newweaktable(lua_State* L, const char* mode)
{
	lua_newtable(L);
	lua_pushvalue(L, -1);
	lua_setmetatable(L, -2);
	lua_pushliteral(L, "__mode");
	lua_pushstring(L, mode);
	lua_settable(L, -3);
}

// STUB: WEBSERVICE 0x100ac300
boost::shared_ptr<Instance> ObjectBridge::getInstance(lua_State* L, unsigned int index)
{
	boost::shared_ptr<Reflection::DescribedBase> object = SharedPtrBridge<Reflection::DescribedBase>::getPtr(L, index);

	Instance* instance;

	if (object.get() != NULL) {
		instance = dynamic_cast<Instance*>(object.get());

		if (instance == NULL) {
			throw std::runtime_error(
				G3D::format(
					"Object %s is not an Instance",
					Reflection::ClassDescriptor::rootDescriptor().name.name.c_str()
				)
			);
		}
	}
	else {
		instance = NULL;
	}

	return shared_from(instance);
}

static void assignLuaValue(Reflection::Property p, lua_State* L, int index)
{
	const Reflection::PropertyDescriptor& descriptor = p.getDescriptor();

	if (&descriptor.type == &Reflection::Type::singleton<int>()) {
		p.setValue<int>(lua_tointeger(L, index));
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<bool>()) {
		p.setValue<bool>(lua_toboolean(L, index) != 0);
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<float>()) {
		p.setValue<float>(lua_tofloat(L, index));
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<std::string>()) {
		p.setValue<std::string>(lua_tostring(L, index));
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<FunctionRef>()) {
		p.setValue<FunctionRef>(FunctionRef(L, index));
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<boost::shared_ptr<Instance> >()) {
		p.setValue<boost::shared_ptr<Instance> >(ObjectBridge::getInstance(L, index));
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<boost::shared_ptr<Reflection::DescribedBase> >()) {
		p.setValue<boost::shared_ptr<Reflection::DescribedBase> >(
			SharedPtrBridge<Reflection::DescribedBase>::getPtr(L, index)
		);
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<G3D::Vector3>()) {
		p.setValue<G3D::Vector3>(Bridge<G3D::Vector3, 1>::getObject(L, index));
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<G3D::CoordinateFrame>()) {
		p.setValue<G3D::CoordinateFrame>(Bridge<G3D::CoordinateFrame, 1>::getObject(L, index));
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<G3D::Color3>()) {
		p.setValue<G3D::Color3>(Bridge<G3D::Color3, 1>::getObject(L, index));
		return;
	}

	if (&descriptor.type == &Reflection::Type::singleton<BrickColor>()) {
		p.setValue<BrickColor>(Bridge<BrickColor, 1>::getObject(L, index));
		return;
	}

	if (dynamic_cast<const Reflection::TypedPropertyDescriptor<Soundscape::SoundId>*>(&descriptor) != NULL) {
		p.setValue<Soundscape::SoundId>(Soundscape::SoundId(ContentId(lua_tostring(L, index))));
		return;
	}

	if (dynamic_cast<const Reflection::TypedPropertyDescriptor<TextureId>*>(&descriptor) != NULL) {
		p.setValue<TextureId>(TextureId(ContentId(lua_tostring(L, index))));
		return;
	}

	if (dynamic_cast<const Reflection::EnumPropertyDescriptor*>(&descriptor) != NULL) {
		p.setValue<int>(lua_tointeger(L, index));
		return;
	}

	if (dynamic_cast<const Reflection::RefPropertyDescriptor*>(&descriptor) != NULL) {
		p.setValue<boost::shared_ptr<Instance> >(ObjectBridge::getInstance(L, index));
		return;
	}

	throw std::runtime_error(
		G3D::format(
			"Unable to set property %s, type %s",
			descriptor.name.name.c_str(),
			descriptor.type.name.name.c_str()
		)
	);
}

} // namespace Lua
} // namespace RBX

template bool RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::DescribedBase>, 0>::getValue<
	boost::shared_ptr<RBX::Reflection::DescribedBase> >(
	lua_State* L,
	unsigned int index,
	boost::shared_ptr<RBX::Reflection::DescribedBase>& value
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
