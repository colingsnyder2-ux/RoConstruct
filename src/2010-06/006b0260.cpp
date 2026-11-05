// from server: 100% by atomic.potato
extern "C" void __cdecl Function_006b00b0(void*, void*, int);

struct S
{
    void __cdecl f(void*, int);
};

void __cdecl S::f(void* a, int value)
{
    if (value != 4)
    {
        Function_006b00b0(this, a, value);
        return;
    }

    *(unsigned long*)a = 0x00bcb870;
    *((unsigned char*)a + 4) = 0;
    *((unsigned char*)a + 5) = 0;
}
