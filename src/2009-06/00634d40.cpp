// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" {
struct lua_State;
void* luaL_checkudata(lua_State* L, int ud, const char* tname);
void lua_pushstring(lua_State* L, const char* s);
}
namespace RBX { namespace Lua {
struct EnumsBridge {
    static const char* className;
    static int on_tostring(lua_State* L);
};
int EnumsBridge::on_tostring(lua_State* L)
{
    luaL_checkudata(L, 1, className);
    lua_pushstring(L, "Enums");
    return 1;
}
}}
