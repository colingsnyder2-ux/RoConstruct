#pragma once
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
// redeclared here). The bridge classes are the read-only donor declarations below; every body this recovery
// counts is byte-exact against the 2008-06 image with every call/data target verified, which is what binds
// these declarations to 2008-06 (no field of a bridge class is declared: the bridges are static-only classes).
//
// Userdata layout (sizeof(T) pushed to lua_newuserdata in the target bytes, recorded under 'layout' in the receipt):
//   G3D::Vector3 0xc (newVector3 0061ce80), G3D::Color3 0xc (newColor3 0061caf0), RBX::BrickColor 4 (push* 0061d230..
//   0061d3f0) (CoordinateFrame pushes go through pushNewObject 005a8c50),
//   boost::signals::connection 0x10 (pushNewObject<connection> 0061f180), boost::shared_ptr<T> 8.
//   (FunctionScriptSlot: the 2008 copy constructor 0061f960 also copies a dword at +0x50 that the donor declaration
//   lacks; its rows are not counted.)
// Metatable names are the constant-initialized Bridge<T>::className statics (data, not code):
//   Bridge<shared_ptr<DescribedBase>>::className 0095af74 -> "Object", Bridge<EnumItem>::className 0095b1dc ->
//   "EnumItem", ... (the recorder reads each pointer and its string from the image).
#include "lua.h"
#include "lauxlib.h"
#include "lua/LuaBridge.h"
#include "script/LuaAtomicClasses.h"
#include "script/LuaInstanceBridge.h"
