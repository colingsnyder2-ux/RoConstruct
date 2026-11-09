// from server: 100% by atomic.potato
extern "C" void __cdecl sub_005cca40(void*, void*, unsigned int);

struct PartChunk
{
    void __cdecl f(void*, unsigned int);
};

void __cdecl PartChunk::f(void* a, unsigned int b)
{
    if (b != 4)
    {
        sub_005cca40(this, a, b);
        return;
    }

    *(unsigned long*)a = 0x00b25f80;
    *((unsigned char*)a + 4) = 0;
    *((unsigned char*)a + 5) = 0;
}
