// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/script/LuaAtomicClasses.cpp

// Candidate translation unit (score above; library headers required).
#include "script/LuaAtomicClasses.h"

#include "decomp.h"
#include "lua/LuaBridge.h"
#include "lua/lua.h"
#include "v8datamodel/BrickColor.h"

#include <G3D/Color3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Quat.h>
#include <G3D/Vector3.h>
#include <G3D/Vector4.h>
#include <G3D/g3dmath.h>
#include <algorithm>
#include <float.h>
#include <limits>
#include <lua.h>
#include <string.h>

namespace RBX {
namespace Lua {

// FUNCTION: WEBSERVICE 0x100ada30
float lua_tofloat(lua_State* L, int index)
{
	double value = lua_tonumber(L, index);

	if (value == std::numeric_limits<double>::infinity()) {
		return std::numeric_limits<float>::infinity();
	}

	if (value == -std::numeric_limits<double>::infinity()) {
		return -std::numeric_limits<float>::infinity();
	}

	if (!(value < 0.0 || value >= 0.0)) {
		return static_cast<float>(value);
	}

	if (value > FLT_MAX) {
		return FLT_MAX;
	}

	if (value < -FLT_MAX) {
		return -FLT_MAX;
	}

	return static_cast<float>(value);
}

template <>
const char* Bridge<G3D::Color3, 1>::className = "Color3";

// FUNCTION: WEBSERVICE 0x100adac0
template <>
int Bridge<G3D::Color3, 1>::on_index(const G3D::Color3& value, const char* name, lua_State* L)
{
	if (strcmp(name, "r") == 0) {
		lua_pushnumber(L, value.r);
		return 1;
	}

	if (strcmp(name, "g") == 0) {
		lua_pushnumber(L, value.g);
		return 1;
	}

	if (strcmp(name, "b") == 0) {
		lua_pushnumber(L, value.b);
		return 1;
	}

	throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

// FUNCTION: WEBSERVICE 0x100adc80
int Color3Bridge::newColor3(lua_State* L)
{
	float color[3];

	int count = std::min(3, lua_gettop(L));

	for (int i = 0; i < count; i++) {
		color[i] = lua_tofloat(L, i + 1);
	}

	for (int i = count; i < 3; i++) {
		color[i] = 0.0f;
	}

	pushNewObject(L, G3D::Color3(color[0], color[1], color[2]));
	return 1;
}

// FUNCTION: WEBSERVICE 0x100add30
int Vector3Bridge::on_add(lua_State* L)
{
	pushNewObject(L, getObject(L, 2) + getObject(L, 1));
	return 1;
}

// FUNCTION: WEBSERVICE 0x100addc0
int Vector3Bridge::on_sub(lua_State* L)
{
	const G3D::Vector3& left = getObject(L, 1);
	const G3D::Vector3& right = getObject(L, 2);

	pushNewObject(L, left - right);
	return 1;
}

// FUNCTION: WEBSERVICE 0x100ade50
int Vector3Bridge::on_mul(lua_State* L)
{
	G3D::Vector3 vector;

	if (getValue(L, 1, vector)) {
		G3D::Vector3 other;

		if (getValue(L, 2, other)) {
			pushVector3(L, vector * other);
			return 1;
		}

		pushVector3(L, vector * lua_tofloat(L, 2));
		return 1;
	}

	vector = getObject(L, 2);

	pushVector3(L, vector * lua_tofloat(L, 1));
	return 1;
}

// FUNCTION: WEBSERVICE 0x100adf30
int Vector3Bridge::on_div(lua_State* L)
{
	G3D::Vector3 vector;

	if (getValue(L, 1, vector)) {
		G3D::Vector3 other;

		if (getValue(L, 2, other)) {
			pushVector3(L, vector / other);
			return 1;
		}

		pushVector3(L, vector / lua_tofloat(L, 2));
		return 1;
	}

	vector = getObject(L, 2);

	float scalar = lua_tofloat(L, 1);

	pushVector3(L, G3D::Vector3(scalar, scalar, scalar) / vector);
	return 1;
}

// FUNCTION: WEBSERVICE 0x100ae030
int Vector3Bridge::on_unm(lua_State* L)
{
	pushNewObject(L, -getObject(L, 1));
	return 1;
}

// FUNCTION: WEBSERVICE 0x100ae0b0
int Vector3Bridge::newVector3(lua_State* L)
{
	float vector[3];

	int count = std::min(3, lua_gettop(L));

	for (int i = 0; i < count; i++) {
		vector[i] = lua_tofloat(L, i + 1);
	}

	for (int i = count; i < 3; i++) {
		vector[i] = 0.0f;
	}

	pushNewObject(L, G3D::Vector3(vector[0], vector[1], vector[2]));
	return 1;
}

// FUNCTION: WEBSERVICE 0x100ae160
static int lerp(lua_State* L)
{
	const G3D::Vector3& value = Vector3Bridge::getObject(L, 1);
	const G3D::Vector3& other = Vector3Bridge::getObject(L, 2);
	float alpha = lua_tofloat(L, 3);

	Vector3Bridge::pushNewObject(L, value.lerp(other, alpha));
	return 1;
}

// FUNCTION: WEBSERVICE 0x100ae210
template <>
int Bridge<G3D::Vector3, 1>::on_index(const G3D::Vector3& value, const char* name, lua_State* L)
{
	if (strcmp(name, "x") == 0) {
		lua_pushnumber(L, value.x);
		return 1;
	}

	if (strcmp(name, "y") == 0) {
		lua_pushnumber(L, value.y);
		return 1;
	}

	if (strcmp(name, "z") == 0) {
		lua_pushnumber(L, value.z);
		return 1;
	}

	if (strcmp(name, "unit") == 0) {
		pushNewObject(L, value.unit());
		return 1;
	}

	if (strcmp(name, "magnitude") == 0) {
		lua_pushnumber(L, value.magnitude());
		return 1;
	}

	if (strcmp(name, "lerp") == 0) {
		lua_pushcclosure(L, lerp, 0);
		return 1;
	}

	throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

template <>
const char* Bridge<G3D::Vector3, 1>::className = "Vector3";

template bool Bridge<G3D::Vector3, 1>::getValue<G3D::Vector3>(lua_State* L, unsigned int index, G3D::Vector3& value);

template G3D::Vector3* Bridge<G3D::Vector3, 1>::pushNewObject<G3D::Vector3>(lua_State* L, G3D::Vector3 value);

template G3D::Color3* Bridge<G3D::Color3, 1>::pushNewObject<G3D::Color3>(lua_State* L, G3D::Color3 value);

template RBX::BrickColor* Bridge<RBX::BrickColor, 1>::pushNewObject<RBX::BrickColor>(
	lua_State* L,
	RBX::BrickColor value
);

// FUNCTION: WEBSERVICE 0x100ae580
int BrickColorBridge::newBrickColor(lua_State* L)
{
	int count = std::min(4, lua_gettop(L));

	if (count == 0) {
		pushNewObject(L, RBX::BrickColor(RBX::BrickColor::lego_194));
	}
	else if (count == 1) {
		if (lua_isnumber(L, 1)) {
			pushNewObject(L, RBX::BrickColor(lua_tointeger(L, 1)));
			return count;
		}

		if (lua_isstring(L, 1)) {
			pushNewObject(L, RBX::BrickColor::parse(lua_tolstring(L, 1, 0)));
			return 1;
		}

		pushNewObject(L, RBX::BrickColor::closest(Color3Bridge::getObject(L, 1)));
		return 1;
	}

	float color[4] = {0.0f, 0.0f, 0.0f, 1.0f};

	for (int i = 0; i < count; i++) {
		color[i] = lua_tofloat(L, i + 1);
	}

	pushNewObject(L, RBX::BrickColor::closest(G3D::Color4(color[0], color[1], color[2], color[3])));
	return 1;
}

// FUNCTION: WEBSERVICE 0x100ae740
int BrickColorBridge::randomBrickColor(lua_State* L)
{
	pushNewObject(L, RBX::BrickColor::random());
	return 1;
}

// FUNCTION: WEBSERVICE 0x100ae790
template <>
int Bridge<RBX::BrickColor, 1>::on_index(const RBX::BrickColor& value, const char* name, lua_State* L)
{
	if (strcmp(name, "number") == 0) {
		lua_pushinteger(L, value.number);
		return 1;
	}

	if (strcmp(name, "Number") == 0) {
		lua_pushinteger(L, value.number);
		return 1;
	}

	if (strcmp(name, "Color") == 0) {
		Bridge<G3D::Color3, 1>::pushNewObject(L, value.color3());
		return 1;
	}

	if (strcmp(name, "r") == 0) {
		lua_pushnumber(L, value.color3().r);
		return 1;
	}

	if (strcmp(name, "g") == 0) {
		lua_pushnumber(L, value.color3().g);
		return 1;
	}

	if (strcmp(name, "b") == 0) {
		lua_pushnumber(L, value.color3().b);
		return 1;
	}

	if (strcmp(name, "name") == 0) {
		lua_pushstring(L, value.name().c_str());
		return 1;
	}

	if (strcmp(name, "Name") == 0) {
		lua_pushstring(L, value.name().c_str());
		return 1;
	}

	throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

template <>
const char* Bridge<RBX::BrickColor, 1>::className = "BrickColor";

// FUNCTION: WEBSERVICE 0x100ae950
int CoordinateFrameBridge::newCoordinateFrame(lua_State* L)
{
	G3D::CoordinateFrame result;

	int count = lua_gettop(L);

	switch (count) {
	case 0:
		break;

	case 1:
		result.translation = Vector3Bridge::getObject(L, 1);
		break;

	case 2:
		result.translation = Vector3Bridge::getObject(L, 1);
		result.lookAt(Vector3Bridge::getObject(L, 2));
		break;

	case 3:
		for (int i = 0; i < 3; i++) {
			result.translation[i] = lua_tofloat(L, i + 1);
		}
		break;

	case 7: {
		for (int i = 0; i < 3; i++) {
			result.translation[i] = lua_tofloat(L, i + 1);
		}

		G3D::Quat quaternion;

		quaternion.x = lua_tofloat(L, 4);
		quaternion.y = lua_tofloat(L, 5);
		quaternion.z = lua_tofloat(L, 6);
		quaternion.w = lua_tofloat(L, 7);

		G3D::Matrix3 rotation(quaternion);

		result.rotation = rotation;
		break;
	}

	case 12: {
		for (int i = 0; i < 3; i++) {
			result.translation[i] = lua_tofloat(L, i + 1);
		}

		int index = 4;

		float* element = result.rotation[0];

		while (index < 13) {
			for (int c = 0; c < 3; c++) {
				*element++ = lua_tofloat(L, c + index);
			}

			index += 3;
		}
		break;
	}

	default:
		throw std::runtime_error(G3D::format("Invalid number of arguments: %d", count));
	}

	pushNewObject(L, result);
	return 1;
}

// FUNCTION: WEBSERVICE 0x100aebc0
int CoordinateFrameBridge::on_add(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);
	const G3D::Vector3& other = Vector3Bridge::getObject(L, 2);

	G3D::CoordinateFrame result = value + other;

	pushNewObject(L, result);
	return 1;
}

// FUNCTION: WEBSERVICE 0x100aec40
int CoordinateFrameBridge::on_sub(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);
	const G3D::Vector3& other = Vector3Bridge::getObject(L, 2);

	G3D::CoordinateFrame result = value - other;

	pushNewObject(L, result);
	return 1;
}

// FUNCTION: WEBSERVICE 0x100aecc0
int CoordinateFrameBridge::on_inverse(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	G3D::CoordinateFrame result = value.inverse();

	pushNewObject(L, result);
	return 1;
}

// FUNCTION: WEBSERVICE 0x100aed30
int CoordinateFrameBridge::on_toWorldSpace(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	int count = lua_gettop(L) - 1;

	if (count == 0) {
		G3D::CoordinateFrame result = value;

		pushNewObject(L, result);
		return 1;
	}

	for (int i = 0; i < count; i++) {
		G3D::CoordinateFrame result = value * getObject(L, i + 2);

		pushNewObject(L, result);
	}

	return count;
}

// FUNCTION: WEBSERVICE 0x100aee30
int CoordinateFrameBridge::on_toObjectSpace(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	int count = lua_gettop(L) - 1;

	if (count == 0) {
		G3D::CoordinateFrame result = value.inverse();

		pushNewObject(L, result);
		return 1;
	}

	for (int i = 0; i < count; i++) {
		G3D::CoordinateFrame result = value.toObjectSpace(getObject(L, i + 2));

		pushNewObject(L, result);
	}

	return count;
}

// FUNCTION: WEBSERVICE 0x100aef20
int CoordinateFrameBridge::on_pointToWorldSpace(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	int count = lua_gettop(L) - 1;

	if (count == 0) {
		Vector3Bridge::pushVector3(L, value.pointToWorldSpace(G3D::Vector3::zero()));
		return 1;
	}

	for (int i = 0; i < count; i++) {
		Vector3Bridge::pushNewObject(L, value.pointToWorldSpace(Vector3Bridge::getObject(L, i + 2)));
	}

	return count;
}

// FUNCTION: WEBSERVICE 0x100af060
int CoordinateFrameBridge::on_pointToObjectSpace(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	int count = lua_gettop(L) - 1;

	if (count == 0) {
		Vector3Bridge::pushVector3(L, value.pointToObjectSpace(G3D::Vector3::zero()));
		return 1;
	}

	for (int i = 0; i < count; i++) {
		Vector3Bridge::pushNewObject(L, value.pointToObjectSpace(Vector3Bridge::getObject(L, i + 2)));
	}

	return count;
}

// STUB: WEBSERVICE 0x100af1a0
int CoordinateFrameBridge::on_vectorToWorldSpace(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	int count = lua_gettop(L) - 1;

	if (count == 0) {
		Vector3Bridge::pushVector3(L, value.vectorToWorldSpace(G3D::Vector3::zero()));
		return 1;
	}

	for (int i = 0; i < count; i++) {
		Vector3Bridge::pushNewObject(L, value.vectorToWorldSpace(Vector3Bridge::getObject(L, i + 2)));
	}

	return count;
}

// FUNCTION: WEBSERVICE 0x100af340
int CoordinateFrameBridge::on_components(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	lua_pushnumber(L, value.translation.x);
	lua_pushnumber(L, value.translation.y);
	lua_pushnumber(L, value.translation.z);

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			lua_pushnumber(L, value.rotation[r][c]);
		}
	}

	return 12;
}

// FUNCTION: WEBSERVICE 0x100af3d0
int CoordinateFrameBridge::on_toEulerAnglesXYZ(lua_State* L)
{
	float x;
	float y;
	float z;

	const G3D::CoordinateFrame& value = getObject(L, 1);

	value.rotation.toEulerAnglesXYZ(x, y, z);

	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	lua_pushnumber(L, z);
	return 3;
}

// FUNCTION: WEBSERVICE 0x100af440
int CoordinateFrameBridge::on_vectorToObjectSpace(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	int count = lua_gettop(L) - 1;

	if (count == 0) {
		Vector3Bridge::pushVector3(L, value.vectorToObjectSpace(G3D::Vector3::zero()));
		return 1;
	}

	for (int i = 0; i < count; i++) {
		Vector3Bridge::pushNewObject(L, value.vectorToObjectSpace(Vector3Bridge::getObject(L, i + 2)));
	}

	return count;
}

// FUNCTION: WEBSERVICE 0x100af610
int CoordinateFrameBridge::fromEulerAnglesXYZ(lua_State* L)
{
	G3D::CoordinateFrame result;

	result.rotation =
		G3D::Matrix3::fromEulerAnglesXYZ(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));

	pushNewObject(L, result);
	return 1;
}

// FUNCTION: WEBSERVICE 0x100af6b0
int CoordinateFrameBridge::fromAxisAngle(lua_State* L)
{
	G3D::CoordinateFrame result;

	const G3D::Vector3& axis = Vector3Bridge::getObject(L, 1);
	float angle = luaL_checknumber(L, 2);

	result.rotation = G3D::Matrix3::fromAxisAngle(axis, angle);

	pushNewObject(L, result);
	return 1;
}

template <>
const char* Bridge<G3D::CoordinateFrame, 1>::className = "CFrame";

// FUNCTION: WEBSERVICE 0x100af750
template <>
int Bridge<G3D::CoordinateFrame, 1>::on_index(const G3D::CoordinateFrame& value, const char* name, lua_State* L)
{
	if (strcmp(name, "p") == 0) {
		Vector3Bridge::pushVector3(L, value.translation);
		return 1;
	}

	if (strcmp(name, "lookVector") == 0) {
		Vector3Bridge::pushVector3(L, value.getLookVector());
		return 1;
	}

	if (strcmp(name, "inverse") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_inverse, 1);
		return 1;
	}

	if (strcmp(name, "toWorldSpace") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_toWorldSpace, 1);
		return 1;
	}

	if (strcmp(name, "toObjectSpace") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_toObjectSpace, 1);
		return 1;
	}

	if (strcmp(name, "pointToWorldSpace") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_pointToWorldSpace, 1);
		return 1;
	}

	if (strcmp(name, "pointToObjectSpace") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_pointToObjectSpace, 1);
		return 1;
	}

	if (strcmp(name, "vectorToWorldSpace") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_vectorToWorldSpace, 1);
		return 1;
	}

	if (strcmp(name, "vectorToObjectSpace") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_vectorToObjectSpace, 1);
		return 1;
	}

	if (strcmp(name, "toEulerAnglesXYZ") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_toEulerAnglesXYZ, 1);
		return 1;
	}

	if (strcmp(name, "components") == 0) {
		lua_pushvalue(L, -1);
		lua_pushcclosure(L, CoordinateFrameBridge::on_components, 1);
		return 1;
	}

	if (strcmp(name, "x") == 0) {
		lua_pushnumber(L, value.translation.x);
		return 1;
	}

	if (strcmp(name, "y") == 0) {
		lua_pushnumber(L, value.translation.y);
		return 1;
	}

	if (strcmp(name, "z") == 0) {
		lua_pushnumber(L, value.translation.z);
		return 1;
	}

	throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

// FUNCTION: WEBSERVICE 0x100afaf0
int CoordinateFrameBridge::on_mul(lua_State* L)
{
	const G3D::CoordinateFrame& value = getObject(L, 1);

	G3D::CoordinateFrame other;

	if (getValue(L, 2, other)) {
		G3D::CoordinateFrame result = value * other;

		pushNewObject(L, result);
		return 1;
	}

	Vector3Bridge::pushVector3(L, value.toWorldSpace(G3D::Vector4(Vector3Bridge::getObject(L, 2), 1.0f)).xyz());
	return 1;
}

template bool Bridge<G3D::CoordinateFrame, 1>::getValue<G3D::CoordinateFrame>(
	lua_State* L,
	unsigned int index,
	G3D::CoordinateFrame& value
);

template void Bridge<G3D::Color3, 1>::on_newindex(G3D::Color3& value, const char* name, lua_State* L);

template int Bridge<G3D::CoordinateFrame, 1>::on_gc(lua_State* L);

template int Bridge<G3D::Vector3, 1>::on_gc(lua_State* L);

template int Bridge<G3D::Color3, 1>::on_gc(lua_State* L);

template int Bridge<RBX::BrickColor, 1>::on_gc(lua_State* L);

template int Bridge<G3D::CoordinateFrame, 1>::on_index(lua_State* L);

template int Bridge<G3D::Vector3, 1>::on_index(lua_State* L);

template int Bridge<G3D::Color3, 1>::on_index(lua_State* L);

template int Bridge<RBX::BrickColor, 1>::on_index(lua_State* L);

template int Bridge<G3D::CoordinateFrame, 1>::on_eq(lua_State* L);

template int Bridge<G3D::Vector3, 1>::on_eq(lua_State* L);

template int Bridge<G3D::Color3, 1>::on_eq(lua_State* L);

template int Bridge<RBX::BrickColor, 1>::on_eq(lua_State* L);

template int Bridge<G3D::Vector3, 1>::on_tostring(const G3D::Vector3& value, lua_State* L);

template int Bridge<G3D::Vector3, 1>::on_tostring(lua_State* L);

} // namespace Lua
} // namespace RBX
