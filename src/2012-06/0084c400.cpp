// from server: 50% by atomic.potato
struct LuaArguments {
    int* field0;
    int method(float* a, int b);
};

extern "C" void* __cdecl sub_832B40(int* a, int b);
extern "C" void __cdecl sub_832340(int a, int b, int c);
extern "C" void __cdecl sub_8326D0(int a, int b);

extern int dword_DE13B0;

int LuaArguments::method(float* a, int b)
{
    float v0 = a[0];
    float v4 = a[1];
    float v8 = a[2];
    int* esi = field0;
    float* mem = (float*)sub_832B40(esi, 12);
    if (mem)
    {
        mem[0] = v0;
        mem[1] = v4;
        mem[2] = v8;
    }
    sub_832340((int)esi, -10000, dword_DE13B0);
    sub_8326D0((int)esi, -2);
    return 1;
}
