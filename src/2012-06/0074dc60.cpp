// from server: 100% by atomic.potato
extern "C" void __cdecl sub_982114(void*);
extern "C" void __fastcall sub_591EF0(void*);

struct VPlayerBoundYieldFuncDesc {
    char pad[0x38];
    void* field_38;
    void* destroy(unsigned int flags);
};

void* VPlayerBoundYieldFuncDesc::destroy(unsigned int flags)
{
    sub_982114(field_38);
    sub_591EF0(this);
    if (flags & 1) {
        sub_982114(this);
    }
    return this;
}
