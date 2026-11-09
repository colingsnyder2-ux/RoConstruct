// from server: 100% by colin
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD

typedef struct lua_State lua_State;

extern int _luaL_checkoption(lua_State *L, int n, const char *def,
                             const char *const lst[]);
extern int _luaL_optinteger(lua_State *L, int n, int d);
extern int _lua_gc(lua_State *L, int what, int data);
extern void _lua_pushboolean(lua_State *L, int b);
extern void _lua_pushnumber(lua_State *L, double n);

int _luaB_collectgarbage(lua_State *L) {
  static const char *const opts[] = {"stop", "restart", "collect",
    "count", "step", "setpause", "setstepmul", 0};
  static const int optsnum[] = {0, 1, 2, 3, 5, 6, 7};
  int o = _luaL_checkoption(L, 1, "collect", opts);
  int ex = _luaL_optinteger(L, 2, 0);
  int res = _lua_gc(L, optsnum[o], ex);
  switch (optsnum[o]) {
    case 3: {
      int b = _lua_gc(L, 4, 0);
      _lua_pushnumber(L, res + ((double)b/1024));
      return 1;
    }
    case 5: {
      _lua_pushboolean(L, res);
      return 1;
    }
    default: {
      _lua_pushnumber(L, res);
      return 1;
    }
  }
}