// from server: 65% by atomic.potato
extern "C" void* __cdecl sub_007F3860(unsigned int);

struct VUDim2Holder
{
    void* operator new(unsigned int);
    void* clone();
    char pad0[4];
    int x;
    int y;
    int z;
    int w;
};

void* VUDim2Holder::clone()
{
    VUDim2Holder* p = (VUDim2Holder*)sub_007F3860(0x14);
    if (p)
    {
        *(void**)p = (void*)0x9BD198;
        p->x = this->x;
        p->y = this->y;
        p->z = this->z;
        p->w = this->w;
    }
    return p;
}
