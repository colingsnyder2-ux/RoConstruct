// from server: 72% by atomic.potato
extern "C" void __cdecl Target(void*);

struct S
{
    void __cdecl f(void* a, int b);
};

void S::f(void* a, int b)
{
    if (b != 4)
    {
        Target(0);
        b = b;
    }

    if (b == 4)
    {
        *(int*)a = 0x00da7c38;
        *((char*)a + 4) = 0;
        *((char*)a + 5) = 0;
    }
}
