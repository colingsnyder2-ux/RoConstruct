// from server: 100% by atomic.potato
struct S
{
    void __cdecl f(void*, int);
};

extern "C" void __cdecl G1_func_006fe1b0(void*, void*, int);

void __cdecl S::f(void* a, int b)
{
    if (b != 4)
    {
        G1_func_006fe1b0(this, a, b);
        return;
    }

    *(unsigned long*)a = 0x00bdfe00;
    ((unsigned char*)a)[4] = 0;
    ((unsigned char*)a)[5] = 0;
}
