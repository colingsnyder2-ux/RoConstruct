// from server: 100% by atomic.potato
extern "C" void G1_func_006d8610(void*, void*, int);

struct S
{
    void __cdecl f(void*, int);
};

void __cdecl S::f(void* a, int b)
{
    if (b != 4)
    {
        G1_func_006d8610(this, a, b);
        return;
    }

    *(unsigned long*)a = 0x00c72128;
    *((unsigned char*)a + 4) = 0;
    *((unsigned char*)a + 5) = 0;
}
