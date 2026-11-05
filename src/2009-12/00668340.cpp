// from server: 100% by atomic.potato
extern "C" void __cdecl sub_665ec0(void*, void*, int);

struct UEvents
{
    void __cdecl f(void*, int);
};

void __cdecl UEvents::f(void* a, int b)
{
    if (b != 4)
    {
        sub_665ec0(this, a, b);
        return;
    }

    *(unsigned long*)a = 0x00b33668;
    ((unsigned char*)a)[4] = 0;
    ((unsigned char*)a)[5] = 0;
}
