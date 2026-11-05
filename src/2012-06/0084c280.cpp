// from server: 100% by intel
struct LuaArguments {
    int* field0;
    int method(int a, int b);
};

extern "C" void* __cdecl sub_832B40(int* a, int b);
extern "C" void __cdecl sub_832340(int a, int b, int c);
extern "C" void __cdecl sub_8326D0(int a, int b);

extern int dword_DE13BC;

int LuaArguments::method(int a, int b)
{
    int* p = (int*)a;
    int v0 = p[0];
    int v4 = p[1];
    int v8 = p[2];
    int* esi = field0;
    int* mem = (int*)sub_832B40(esi, 12);
    if (mem)
    {
        mem[0] = v0;
        mem[1] = v4;
        mem[2] = v8;
    }
    sub_832340((int)esi, -10000, dword_DE13BC);
    sub_8326D0((int)esi, -2);
    return 1;
}
