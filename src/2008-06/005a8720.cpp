// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <string>
struct lua_State; extern "C" void lua_pushstring(lua_State* L, const char* s);
namespace RBX { extern std::string version; int getVersion(lua_State* L) { lua_pushstring(L, version.c_str()); return 1; } }
