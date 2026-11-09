// from server: 100% by tester
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /fp:fast
#include <math.h>
typedef struct lua_State lua_State;
typedef double lua_Number;
lua_Number luaL_checknumber(lua_State *L, int numArg);
void lua_pushnumber(lua_State *L, lua_Number n);
static int math_tan (lua_State *L) {
  lua_pushnumber(L, tan(luaL_checknumber(L, 1)));
  return 1;
}
static int math_atan (lua_State *L) {
  lua_pushnumber(L, atan(luaL_checknumber(L, 1)));
  return 1;
}
static int math_log (lua_State *L) {
  lua_pushnumber(L, log(luaL_checknumber(L, 1)));
  return 1;
}
static int math_log10 (lua_State *L) {
  lua_pushnumber(L, log10(luaL_checknumber(L, 1)));
  return 1;
}
int (*tab[])(lua_State*) = { math_tan, math_atan, math_log, math_log10 };
