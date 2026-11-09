// from server: 65% by atomic.potato
extern "C" void* __cdecl func_0080a05e(unsigned int size);

struct VUDim2Holder {
    void* operator new(unsigned int size);
    void* clone();
    char pad0[4];
    int x;
    int y;
    int z;
    int w;
};

void* VUDim2Holder::clone()
{
    VUDim2Holder* p = (VUDim2Holder*)func_0080a05e(0x14);
    if (p)
    {
        *(void**)p = (void*)0xa7b420;
        p->x = this->x;
        p->y = this->y;
        p->z = this->z;
        p->w = this->w;
    }
    return p;
}
