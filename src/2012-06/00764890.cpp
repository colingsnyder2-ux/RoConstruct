// from server: 63% by atomic.potato
extern "C" void __cdecl sub_764720(void*, void*, int);

struct EventDesc
{
    void __cdecl f(void*, void*, int);
};

void __cdecl EventDesc::f(void* a, void* b, int c)
{
    if (c != 4)
    {
        sub_764720(a, b, c);
        return;
    }

    *(int*)b = 0xDB98F0;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
