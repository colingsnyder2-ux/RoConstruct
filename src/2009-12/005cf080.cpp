// from server: 100% by atomic.potato
extern "C" void __cdecl Function_005ccab0(void*, void*, unsigned int);

struct PartChunk
{
    void __cdecl f(void*, unsigned int);
};

void __cdecl PartChunk::f(void* a, unsigned int b)
{
    if (b != 4)
    {
        Function_005ccab0(this, a, b);
        return;
    }

    *(unsigned int*)a = 0x00b26038;
    ((unsigned char*)a)[4] = 0;
    ((unsigned char*)a)[5] = 0;
}
