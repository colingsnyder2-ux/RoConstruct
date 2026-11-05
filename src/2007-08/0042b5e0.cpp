// from server: 81% by colin
struct VCLuaFunction {
    int f(int);
};

extern "C" void __stdcall func_00413d90();
extern "C" void __cdecl func_0062fc62(void*);

int VCLuaFunction::f(int arg)
{
    int* p = (int*)arg;
    int old = p[2];
    p[2] = old - 1;
    int result = p[2];
    if (result == 0 && p != 0) {
        p[0] = 0x78a270;
        p[1] = 0x78a248;
        p[2] = (int)0xc0000001;
        func_00413d90();
        func_0062fc62(p);
    }
    return result;
}
