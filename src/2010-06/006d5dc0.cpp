// from server: 100% by atomic.potato
extern "C" void __cdecl Function006d59a0(void*, void*, unsigned int);

struct S
{
    void __cdecl f(void*, unsigned int);
};

void __cdecl S::f(void* a, unsigned int state)
{
    if (state != 4)
    {
        Function006d59a0(this, a, state);
        return;
    }

    *(unsigned int*)a = 0x00bd4d30;
    ((unsigned char*)a)[4] = 0;
    ((unsigned char*)a)[5] = 0;
}
