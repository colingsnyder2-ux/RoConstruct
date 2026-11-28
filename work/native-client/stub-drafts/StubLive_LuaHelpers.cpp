// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /DNDEBUG
// RBX::Lua::throwable_lua_tostring: declared extern by the donor property bridge (assignLuaValue string/Content cases),
// defined nowhere we have. INFERRED from its name and callers: the string at index, or a std::runtime_error when the
// value is not a string/number (a `return 0` stub handed NULL to std::string -> every `obj.Name = "x"` from Lua crashed).
#include <stdexcept>
#include <string>
struct lua_State;
const char* lua_tolstring(lua_State* L, int idx, unsigned int* len);   // C++ linkage: the rbx Lua build's spelling
namespace RBX { namespace Lua {
const char* throwable_lua_tostring(lua_State* L, int idx)
{
    const char* s = lua_tolstring(L, idx, 0);
    if (!s)
        throw std::runtime_error("Unable to cast value to std::string");   // INFERRED message
    return s;
}
} }
