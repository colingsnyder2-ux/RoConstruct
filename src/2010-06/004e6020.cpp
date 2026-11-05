// from server: 65% by atomic.potato
extern "C" void* __cdecl sub_007a79a0(unsigned int);

struct VUDim2Holder
{
    void* create();
    char pad[4];
    int x;
    int y;
    int z;
    int w;
};

void* VUDim2Holder::create()
{
    void* p = sub_007a79a0(0x14);
    if (p)
    {
        *(int*)p = 0xa1b078;
        *(int*)((char*)p + 4) = x;
        *(int*)((char*)p + 8) = y;
        *(int*)((char*)p + 12) = z;
        *(int*)((char*)p + 16) = w;
    }
    return p;
}
