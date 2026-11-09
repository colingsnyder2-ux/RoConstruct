// from server: 100% by atomic.potato
struct LuaState;

extern "C" void __cdecl sub_00612280(LuaState* state, int value);
extern "C" void __cdecl sub_005a9a90(LuaState* state, const char* name);
extern "C" void __cdecl sub_00612680(LuaState* state, int value);

void __cdecl sub_0061f050(LuaState* state)
{
    sub_00612280(state, 0x844590);
    sub_005a9a90(state, (const char*)0x97bf5c);
    sub_00612680(state, -0x2712);
}
