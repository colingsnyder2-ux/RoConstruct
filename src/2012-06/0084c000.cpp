// from server: 83% by atomic.potato
struct LuaArguments {
    char pad0[0x48];
    int count;
    void* state;
    bool check(int idx, bool* out);
};

extern "C" int __cdecl lua_gettop(void* L);
extern "C" int __cdecl lua_type(void* L, int idx);
extern "C" int __cdecl lua_toboolean(void* L, int idx);

bool LuaArguments::check(int idx, bool* out) {
    int total = idx + count;
    if (total > lua_gettop(state)) {
        return false;
    }
    if (lua_type(state, total) - 1 != 0) {
        return false;
    }
    *out = lua_toboolean(state, total) != 0;
    return true;
}
