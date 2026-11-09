// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct lua_State;
extern "C" void* luaL_checkudata(lua_State* L, int ud, const char* tname);
extern "C" void lua_pushstring(lua_State* L, const char* s);
struct Named { int id; const std::string* name; };
extern const char* className;
int toString(lua_State* L)
{
    Named*& n = *static_cast<Named**>(luaL_checkudata(L, 1, className));
    lua_pushstring(L, n->name->c_str());
    return 1;
}
