// from server: 17% by atomic.potato
struct LuaState;

extern "C" int __cdecl lua_gettop(LuaState* L);
extern "C" int __cdecl lua_type(LuaState* L, int idx);
extern "C" int __cdecl lua_tostring(LuaState* L, int idx);

struct LuaArguments {
    char pad0[0x48];
    int m_base;
    LuaState* m_state;
    bool getString(int idx, const char** out);
};

bool LuaArguments::getString(int idx, const char** out) {
    int top = lua_gettop(m_state);
    int n = m_base + idx;
    if (n > top)
        return false;
    int t = lua_type(m_state, n);
    if (t == 0) {
        *out = 0;
        return true;
    }
    if (t != 7)
        return false;
    return lua_tostring(m_state, n) != 0;
}
