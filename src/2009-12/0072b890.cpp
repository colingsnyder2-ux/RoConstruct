// from server: 92% by atomic.potato
struct PoolData {
    void* vfptr;
    char pad[4];
    void* field8;
    void* fieldC;
    void* destroy(unsigned int flags);
};

extern "C" void __fastcall sub_7E78E0(void*);
extern "C" void __stdcall sub_7F385A(void*);

void* PoolData::destroy(unsigned int flags)
{
    vfptr = (void*)0x9E059C;
    sub_7E78E0(&field8);
    sub_7E78E0(&fieldC);
    if (flags & 1)
        sub_7F385A(this);
    return this;
}
