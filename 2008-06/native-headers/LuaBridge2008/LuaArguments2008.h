#pragma once
// 2008-06 Lua function-call arguments (RBX::Lua::LuaArguments), inactive. The read-only donor script/LuaArguments.h
// needs RBX::Instances (missing from native v8tree/Instance.h) and has a different static get, so this recovery declares
// the 2008 shape under the non-colliding name LuaArguments2008 (a codegen analog of RBX::Lua::LuaArguments; nothing is
// declared at a donor path). Evidence:
//   vtable 00844174 (RTTI .?AVLuaArguments@Lua@RBX@@, base .?AVArguments@FunctionDescriptor@Reflection@RBX@@):
//     slot 0 size() 0061a5f0, slot 1 get(int, Value&) 0061bcb0; its only reference is the pending call path 0061c203;
//   fields after Arguments (vptr +0, Value returnValue +4): int offset +0xc, lua_State* L +0x10
//     (size() reads [ecx+0x10]; get() adds [ecx+0xc] to the index and passes [ecx+0x10]);
//   size() 0061a5f0 returns lua_gettop(L) - 1 (no offset);
//   get(int, Value&) 0061bcb0 calls the static get 005ad380 (evidence name
//     ?get@LuaArguments@Lua@RBX@@SA_NPAUlua_State@@HAAVValue@Reflection@3@_N@Z, unique) with (L, index + offset, value,
//     true): a cdecl bool function with a fourth bool argument (push 1).
#include "reflection/function.h"
#include "lua.h"

namespace RBX
{
    namespace Lua
    {
        class LuaArguments2008 : public Reflection::FunctionDescriptor::Arguments
        {
        private:
            const int offset;
            lua_State* L;

        public:
            LuaArguments2008(lua_State* L, int offset)
                : offset(offset),
                  L(L)
            {
            }
            virtual size_t size() const;
            virtual void get(int index, Reflection::Value& value) const;
            // Inline at its only caller ObjectBridge::callMemberFunction 0061c0e0 (0061c22a..0061c234): the static
            // push 005aba50 is called with (&returnValue at args+4, L at args+0x10) and its result is returned.
            int pushReturnValue() const
            {
                return push(returnValue, L);
            }

        public:
            // 005ad380 (ScriptContext unit, external target bound by its evidence name).
            static bool get(lua_State* L, int luaIndex, Reflection::Value& value, bool nested);
            // 005aba50 (external target, outside this unit): cdecl (const Value& at [ebp+8], lua_State* at [ebp+0xc])
            // returning the pushed count (type_info tests of the Value type, then e.g. 1 after a push); called only
            // through pushReturnValue from 0061c234.
            static int push(const Reflection::Value& value, lua_State* const L);
        };
    }
}
