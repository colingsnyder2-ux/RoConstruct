// from server: 100% by tajop
struct lua_State;
struct V { int a; int b; int c; };

void* lua_newuserdata(lua_State* L, unsigned size);
void lua_getfield(lua_State* L, int idx, const char* k);
int lua_setmetatable(lua_State* L, int idx);

extern const char* className;

V* pushNew(lua_State* L, V v)
{
    V* r = (V*)lua_newuserdata(L, sizeof(V));
    if (r)
    {
        r->a = v.a;
        r->b = v.b;
        r->c = v.c;
    }
    lua_getfield(L, -10000, className);
    lua_setmetatable(L, -2);
    return r;
}
