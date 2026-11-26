// from server: 100% by Xemicl
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
typedef struct lua_State lua_State;
typedef double lua_Number;
typedef int lua_Integer;
int luaL_checkoption(lua_State *L, int narg, const char *def, const char *const lst[]);
lua_Integer luaL_optinteger(lua_State *L, int nArg, lua_Integer def);
int lua_gc(lua_State *L, int what, int data);
void lua_pushnumber(lua_State *L, lua_Number n);
void lua_pushboolean(lua_State *L, int b);
#define LUA_GCCOUNT 3
#define LUA_GCCOUNTB 4
#define LUA_GCSTEP 5
int luaB_collectgarbage (lua_State *L) {
  static const char *const opts[] = {"count", 0};
  static const int optsnum[] = {LUA_GCCOUNT};
  int o = luaL_checkoption(L, 1, "collect", opts);
  int ex = (int)luaL_optinteger(L, 2, 0);
  int res = lua_gc(L, optsnum[o], ex);
  switch (optsnum[o]) {
    case LUA_GCCOUNT: {
      int b = lua_gc(L, LUA_GCCOUNTB, 0);
      lua_pushnumber(L, res + ((lua_Number)b/1024));
      return 1;
    }
    case LUA_GCSTEP: {
      lua_pushboolean(L, res);
      return 1;
    }
    default: {
      lua_pushnumber(L, res);
      return 1;
    }
  }
}