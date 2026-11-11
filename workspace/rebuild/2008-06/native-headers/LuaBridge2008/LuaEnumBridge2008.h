#pragma once
// >>> native-status (generated) -- do not edit >>>
// LuaEnumBridge2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 023f9ac6 | roc native-status --write
// 2008-06 Lua enum bridges (Enums / Enum / EnumItem), inactive native recovery. Unit range 0061edb0..0061f0f0 inside
// the bridge range documented in LuaBridge2008.h; its .data block is the bad_alloc message 0095b1d0 followed by the
// constant-initialized className statics 0095b1d4 "Enums", 0095b1d8 "Enum", 0095b1dc "EnumItem".
// Shapes (SingletonBridge, the three bridge classes and their pointer typedefs) are the later donor reconstruction's,
// bound to 2008-06 by the byte-exact bodies recorded in tests/record_native_lua_bridge2008.py:
//   SingletonBridge<T>::push: ScriptContext-unit instances 005a9a90 (Enums), 005a9b30 (Enum), 005a9bd0 (EnumItem);
//   each keys a registry table by its own address (push 0x5a9a90 at 005a9a9c) and stores the 4-byte pointer T in a
//   4-byte userdata (push 4 / lua_newuserdata 00612c40 at 005a9adf).
//   Bridge<T>::on_newindex(T&, name, L) specializations 0061edb0 / 0061ee00 / 0061ef70 (called from the ScriptContext
//   wrappers 005a9e53 / 005a9f63 / 005a8bd3), on_index specializations 0061ee50 (EnumItem), 0061efc0 (Enum),
//   0061f0f0 (Enums), Enums::declareAllEnums 0061f050 (called from ScriptContext::openState 005af7a8).
// The declarations are codegen analogs, not the original header.
#include "LuaBridge2008/LuaBridge2008.h"
#include "reflection/enumconverter.h"

namespace RBX
{
    namespace Lua
    {
        template<class T>
        class SingletonBridge : protected Bridge<T, false>
        {
        public:
            static void registerClass(lua_State* L)
            {
                Bridge<T, false>::registerClass(L);
            }

            static void registerClassLibrary(lua_State* L)
            {
                lua_pushlightuserdata(L, (void*)&push);
                lua_newtable(L);
                lua_rawset(L, LUA_REGISTRYINDEX);
            }

            static void push(lua_State* L, T item)
            {
                // the instances call lua_gettop (00611c10 at 005a9a97) and discard the result (the donor's debug
                // stack-depth check without its assert).
                lua_gettop(L);
                lua_pushlightuserdata(L, (void*)&push);
                lua_rawget(L, LUA_REGISTRYINDEX);

                lua_pushlightuserdata(L, (void*)item);
                lua_rawget(L, -2);

                if (lua_isnil(L, -1))
                {
                    lua_pop(L, 1);
                    Bridge<T, false>::pushNewObject(L, item);
                    lua_pushlightuserdata(L, (void*)item);
                    lua_pushvalue(L, -2);
                    lua_rawset(L, -4);
                }
                lua_remove(L, -2);
            }
        };

        // Lua's global "Enum" table object: one static instance (0097bf5c, pushed by declareAllEnums 0061f050).
        class AllEnumDescriptors
        {
        };
        typedef const AllEnumDescriptors* AllEnumDescriptorsPtr;

        class Enums : public SingletonBridge<AllEnumDescriptorsPtr>
        {
        public:
            static void declareAllEnums(lua_State* L);
        };

        typedef const Reflection::EnumDescriptor* EnumDescriptorPtr;

        class Enum : public SingletonBridge<EnumDescriptorPtr>
        {
        };

        typedef const Reflection::EnumDescriptor::Item* EnumDescriptorItemPtr;

        class EnumItem : public SingletonBridge<EnumDescriptorItemPtr>
        {
        };
    }
}
