// from server: 65% by Intel
struct lua_State;

extern "C" void __cdecl func_832ed0(int, lua_State*);
extern "C" void __cdecl func_6a2240(int, lua_State*);
extern "C" void __cdecl func_832130(int, lua_State*);
extern "C" void __cdecl func_832200(int, int, lua_State*);
extern "C" void __cdecl func_832550(int, lua_State*);
extern "C" void __cdecl func_832460(int, int, lua_State*);
extern "C" void __cdecl func_831b00(int, lua_State*);

int g_global_da9e58;
int g_ptr_b94214 = 0xB94214;
int g_ptr_b94208 = 0xB94208;
int g_ptr_bd1b68 = 0xBD1B68;
int g_ptr_845190 = 0x845190;
int g_ptr_bd1b60 = 0xBD1B60;
int g_ptr_844d80 = 0x844D80;
int g_ptr_bd1b54 = 0xBD1B54;
int g_ptr_843d00 = 0x843D00;

int __cdecl sub_845480(lua_State* L, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16)
{
    int v = g_global_da9e58;
    func_832ed0(v, L);
    func_6a2240(-1, L);
    func_832130(g_ptr_b94214, L);
    func_832200(0, arg1, L);
    func_832550(-3, L);
    func_832130(g_ptr_b94208, L);
    func_832200(0, arg2, L);
    func_832550(-3, L);
    func_832130(g_ptr_bd1b68, L);
    func_832200(0, g_ptr_845190, L);
    func_832550(-3, L);
    func_832130(g_ptr_bd1b60, L);
    func_832200(0, g_ptr_844d80, L);
    func_832550(-3, L);
    func_832130(g_ptr_bd1b54, L);
    func_832200(0, g_ptr_843d00, L);
    func_832550(-3, L);
    func_832460(1, -1, L);
    func_831b00(-2, L);
    return 0;
}
