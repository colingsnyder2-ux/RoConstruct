// from server: 100% by colin
struct Vftable
{
    void* entries[8];
};

const Vftable S_vftable = {0, 0, 0, 0, 0, 0, 0, 0};

struct Base
{
    char storage[0xF4];
};

struct S : Base
{
    unsigned int fields[8];
    S();
};

extern "C" void __stdcall sub_6a10fa();

S::S()
{
    sub_6a10fa();
    *(volatile void**)this = (void*)&S_vftable;
    volatile unsigned int* f = fields;
    f[0] = 0;
    f[1] = 0;
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    f[5] = 0;
    f[6] = 0;
    f[7] = 0;
}