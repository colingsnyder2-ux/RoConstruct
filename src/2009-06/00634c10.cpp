// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct lua_State;
typedef int (*lua_CFunction)(lua_State* L);
extern "C" {
int luaL_newmetatable(lua_State* L, const char* tname);
void lua_pushstring(lua_State* L, const char* s);
void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
void lua_settable(lua_State* L, int idx);
void lua_setreadonly(lua_State* L, int idx, int enabled);
void lua_settop(lua_State* L, int idx);
}
#define lua_pushcfunction(L,f) lua_pushcclosure(L, (f), 0)
#define lua_pop(L,n) lua_settop(L, -(n)-1)
namespace RBX { namespace Lua {
template<class T> class Bridge {
public:
    static const char* className;
    static int on_index(lua_State* L);
    static int on_newindex(lua_State* L);
    static int on_gc(lua_State* L);
    static int on_eq(lua_State* L);
    static int on_tostring(lua_State* L);
    static void registerClass(lua_State* L);
};
template<class T> void Bridge<T>::registerClass(lua_State* L)
{
    luaL_newmetatable(L, className);
    lua_pushstring(L, "__index");
    lua_pushcfunction(L, on_index);
    lua_settable(L, -3);
    lua_pushstring(L, "__newindex");
    lua_pushcfunction(L, on_newindex);
    lua_settable(L, -3);
    lua_pushstring(L, "__gc");
    lua_pushcfunction(L, on_gc);
    lua_settable(L, -3);
    lua_pushstring(L, "__eq");
    lua_pushcfunction(L, on_eq);
    lua_settable(L, -3);
    lua_pushstring(L, "__tostring");
    lua_pushcfunction(L, on_tostring);
    lua_settable(L, -3);
    lua_setreadonly(L, -1, 1);
    lua_pop(L, 1);
}
struct Tag {};
template class Bridge<Tag>;
} }
