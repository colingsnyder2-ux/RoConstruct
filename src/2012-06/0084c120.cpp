// from server: 51% by Intel
struct LuaState;

extern "C" int __cdecl func_00831fd0(LuaState* L, int idx);
extern "C" int __cdecl func_00832480(LuaState* L, int idx);
extern "C" void __cdecl func_00832340(void* a1, int a2, LuaState* L);
extern "C" int __cdecl func_00831dc0(LuaState* L, int idx, int a3);
extern "C" void __cdecl func_00831b00(void* a1, int idx);

int* g_global_ptr = reinterpret_cast<int*>(0xDE13BC);

struct LuaArguments {
    bool func_0084C120(int arg1, LuaState* L, int* out_ptr);
};

bool LuaArguments::func_0084C120(int arg1, LuaState* L, int* out_ptr) {
    int v1 = func_00831fd0(L, arg1);
    if (!v1)
        return false;

    if (!func_00832480(L, arg1))
        return false;

    func_00832340(g_global_ptr, -10000, L);

    int v2 = func_00831dc0(L, arg1, -2);
    if (!v2) {
        func_00831b00(out_ptr, -3);
    } else {
        func_00831b00(out_ptr, -3);
        *out_ptr = *reinterpret_cast<int*>(v1);
        out_ptr[1] = *reinterpret_cast<int*>(v1 + 4);
        out_ptr[2] = *reinterpret_cast<int*>(v1 + 8);
    }
    return true;
}
