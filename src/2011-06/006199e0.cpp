// from server: 100% by Viper
extern "C" void* __cdecl sub_764190(void* a, int b, int c);
extern "C" void* __cdecl sub_764080(void* a, int b, void* c);
extern "C" int __cdecl sub_62ac20(void* a, void* b, void* c);
extern void* g_00c8efc8;

int func_00619800(void* a) {
    void* v = sub_764190(a, 2, 0);
    void* r = sub_764080(a, 1, g_00c8efc8);
    sub_62ac20(r, v, a);
    return 0;
}
