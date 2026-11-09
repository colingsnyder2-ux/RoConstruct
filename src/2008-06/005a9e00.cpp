// from server: 100% by king_originala
struct lua_State;

extern "C" void* __cdecl check_value(lua_State*, int, const char*);
extern "C" void __cdecl push_string(lua_State*, const char*);

int __cdecl on_tostring(lua_State* state)
{
    check_value(state, 1, *reinterpret_cast<const char**>(0x0095b1d4));
    push_string(state, reinterpret_cast<const char*>(0x00834370));
    return 1;
}
