// from server: 100% by atomic.potato
extern "C" void __cdecl Function_0078e3a0(void*, void*, int);

struct S
{
    void __cdecl f(void*, int);
};

void S::f(void* a, int n)
{
    if (n != 4)
    {
        Function_0078e3a0(this, a, n);
        return;
    }

    *(unsigned long*)a = 0x00dc1568;
    *((unsigned char*)a + 4) = 0;
    *((unsigned char*)a + 5) = 0;
}
