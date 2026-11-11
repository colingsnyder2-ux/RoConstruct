#pragma once
// >>> native-status (generated) -- do not edit >>>
// LuaBridge2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src b53d3795 | roc native-status --write
// 2008-06 Roblox Lua object bridge (RBX::Lua userdata wrappers), inactive native recovery.
//
// Range (boundary proof in work/2008-06/shared-layouts/lua-bridge2008-working.json):
//   0061a420 RBX::Lua::newweaktable (first bridge function) .. 006217d0 (last bridge helper);
//   before it the boost thread tss_hooks unit (0061a090..0061a3f0, TLS callback 0061a3f0) and the 31-byte
//   0061a400 (called only from the enum conversion 0061b190); after it ldo.c of the Lua 5.1.1 library
//   (luaD_seterrorobj 006217f0, luaD_rawrunprotected 00621920, ...), which calls only Lua internals.
//   Lua (compiled as C++: ?lua_createtable@@YAXPAUlua_State@@HH@Z at 00612570, ...) is never recovered here:
//   every lua_* / luaL_* call is bound by address and verified by the recorder.
//
// Declarations: the generic Bridge<T, isComparable> / SharedPtrBridge<T> templates are the read-only
// lua/LuaBridge.h that native script/ScriptContext.h already reaches through script/ThreadRef.h (it may not be
// redeclared here). ObjectBridge comes from LuaBridge2008/LuaInstanceBridge2008.h and the signal bridge / script slots
// from LuaBridge2008/LuaSignalBridge2008.h (non-colliding copies of the donor shapes with the 2008 differences the
// target bytes prove); the atomic bridges are the read-only donor script/LuaAtomicClasses.h. Every body this recovery
// counts is byte-exact against the 2008-06 image with every call/data target verified.
//
// Userdata layout (sizeof(T) pushed to lua_newuserdata in the target bytes, recorded under 'layout' in the receipt):
//   G3D::Vector3 0xc (newVector3 0061ce80), G3D::Color3 0xc (newColor3 0061caf0), RBX::BrickColor 4 (push* 0061d230..
//   0061d3f0) (CoordinateFrame pushes go through pushNewObject 005a8c50),
//   boost::signals::connection 0x10 (pushNewObject<connection> 0061f180), boost::shared_ptr<T> 8.
//   FunctionScriptSlot 2008 layout: see LuaSignalBridge2008.h (+0x50 callDepth).
// Metatable names are the constant-initialized Bridge<T>::className statics (data, not code):
//   Bridge<shared_ptr<DescribedBase>>::className 0095af74 -> "Object", Bridge<EnumItem>::className 0095b1dc ->
//   "EnumItem", ... (the recorder reads each pointer and its string from the image).
#include "lua.h"
#include "lauxlib.h"
#include "lua/LuaBridge.h"
#include "script/LuaAtomicClasses.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"

namespace RBX { namespace Lua {
// 0061c830 (atomic bridge unit, also called from the instance bridge 0061b255 / 0061b29c): lapi lua_tonumber 00611f60
// clamped into float range (+-inf -> float infinities via the MSVCP90 _Inf/_FInf imports, NaN passes, +-FLT_MAX clamp).
// The 2008 name is not in the image; the declaration is a codegen analog.
float tonumberClamped(lua_State* L, int index);
// 0061c790 / 0061c7b0 (atomic unit, called from the instance bridge and ScriptContext): lua_tostring returning "" (the
// pointer variable emptyString2008 0095b1cc) or throwing std::runtime_error("String expected") for a non-string.
// Names are codegen analogs.
extern const char* emptyString2008;
const char* tostringOrEmpty(lua_State* L, int index);
const char* tostringChecked(lua_State* L, int index);
}}
