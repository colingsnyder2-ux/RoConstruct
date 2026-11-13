// Inactive 2008-06 native recovery: RBX::Lua enum bridges (Enums / Enum / EnumItem), unit 0061edb0..0061f0f0.
// Body shapes are codegen analogs; counted rows are proven by tests/record_native_lua_bridge2008.py.
// >>> native-status (generated) -- do not edit >>>
// LuaBridge2008Enum | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b05a5a75 | roc native-status --write
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "G3D/format.h"
#include <string.h>

using namespace RBX;
using namespace RBX::Lua;
using namespace RBX::Reflection;

namespace RBX { namespace Lua {
// 0095b1d4 / 0095b1d8 / 0095b1dc: this unit's constant-initialized className statics (after bad_alloc 0095b1d0).
template<> const char* Bridge<AllEnumDescriptorsPtr, false>::className = "Enums";
template<> const char* Bridge<EnumDescriptorPtr, false>::className = "Enum";
template<> const char* Bridge<EnumDescriptorItemPtr, false>::className = "EnumItem";
}}

// 0061edb0 (called from the ScriptContext __newindex wrapper 005a9e53).
template<>
void Bridge<AllEnumDescriptorsPtr, false>::on_newindex(AllEnumDescriptorsPtr& object, const char* name, lua_State* L)
{
    throw std::runtime_error(G3D::format("Enums cannot be modified"));
}

// 0061ee00 (called from 005a9f63).
template<>
void Bridge<EnumDescriptorPtr, false>::on_newindex(EnumDescriptorPtr& object, const char* name, lua_State* L)
{
    throw std::runtime_error(G3D::format("Enum cannot be modified"));
}

// 0061ee50: Item::name (Descriptor +4) and Item::value (+0xc).
template<>
int Bridge<EnumDescriptorItemPtr, false>::on_index(const EnumDescriptorItemPtr& object, const char* name, lua_State* L)
{
    if (strcmp(name, "Name") == 0)
    {
        lua_pushstring(L, object->name.c_str());
        return 1;
    }

    if (strcmp(name, "Value") == 0)
    {
        lua_pushnumber(L, object->value);
        return 1;
    }

    throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

// 0061ef70 (called from 005a8bd3).
template<>
void Bridge<EnumDescriptorItemPtr, false>::on_newindex(EnumDescriptorItemPtr& object, const char* name, lua_State* L)
{
    throw std::runtime_error(G3D::format("EnumItem cannot be modified"));
}

// 0061efc0: EnumDescriptor::lookup (vtable slot 1), pushed through EnumItem::push 005a9bd0.
template<>
int Bridge<EnumDescriptorPtr, false>::on_index(const EnumDescriptorPtr& object, const char* name, lua_State* L)
{
    if (const EnumDescriptor::Item* item = object->lookup(name))
    {
        EnumItem::push(L, item);
        return 1;
    }

    throw std::runtime_error(G3D::format("%s is not a valid EnumItem", name));
}

// 0097bf5c: the single AllEnumDescriptors object (zero-initialized, referenced only by 0061f061).
static AllEnumDescriptors allEnumDescriptors;

// 0061f050 (called from ScriptContext::openState 005af7a8): global "Enum" = Enums::push 005a9a90.
void Enums::declareAllEnums(lua_State* L)
{
    lua_pushstring(L, "Enum");
    push(L, &allEnumDescriptors);
    lua_settable(L, LUA_GLOBALSINDEX);
}

// MSVC treats an explicit specialization of a member defined inside the class template (lua/LuaBridge.h defines
// Bridge<T>::on_newindex(T&, name, L) in the class body) as inline and emits it only when referenced: the
// __newindex wrappers that reference them (ScriptContext unit 005a9e30 / 005a9f50 / 005a8bc0) are instantiated here.
namespace RBX { namespace Lua {
template int Bridge<AllEnumDescriptorsPtr, false>::on_newindex(lua_State*);
template int Bridge<EnumDescriptorPtr, false>::on_newindex(lua_State*);
template int Bridge<EnumDescriptorItemPtr, false>::on_newindex(lua_State*);
}}

#ifdef NATIVE_LUABRIDGE_PENDING
// 0061f080 / 0061f0f0 need EnumDescriptor::allEnumsByName() (0056c520), private in the read-only native
// reflection/enumconverter.h; the proposal adds the public inline EnumDescriptor::lookupDescriptor(const Name&).
template<>
int Bridge<AllEnumDescriptorsPtr, false>::on_index(const AllEnumDescriptorsPtr& object, const char* name, lua_State* L)
{
    if (const EnumDescriptor* desc = EnumDescriptor::lookupDescriptor(Name::lookup(name)))
    {
        Enum::push(L, desc);
        return 1;
    }

    throw std::runtime_error(G3D::format("%s is not a valid EnumItem", name));
}
#endif
