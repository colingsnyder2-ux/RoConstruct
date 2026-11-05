// from server: 50% by atomic.potato
extern "C" void __cdecl GenericSlotWrapper(void*, int);

struct S
{
    void __stdcall f(void*, int);
};

void __stdcall S::f(void* a, int b)
{
    if (b == 4)
    {
        *(unsigned long*)a = 0x00da6560;
        *((unsigned char*)a + 4) = 0;
        *((unsigned char*)a + 5) = 0;
    }
    else
    {
        GenericSlotWrapper(a, b);
    }
}
