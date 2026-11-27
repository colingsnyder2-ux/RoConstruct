// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct lua_State;
extern "C" void* luaL_checkudata(lua_State* L, int ud, const char* tname);
namespace RBX { namespace Lua {
extern const char* slotWrapperTypeName;
void releaseSlot(char* p);
int collectSlotWrapper(lua_State* L)
{
    char** p = (char**)luaL_checkudata(L, 1, slotWrapperTypeName);
    if (*p)
        releaseSlot(*p + 5);
    return 0;
}
} }