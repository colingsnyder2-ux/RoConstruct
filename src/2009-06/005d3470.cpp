// from server: 100% by atomic.potato
struct FactoryProduct {
    void* field0;
    unsigned char pad_04[0x10];
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
    void sub_5d2b60();
    void* destroy(unsigned int flags);
};

void __cdecl sub_718a32(void* p);

void* FactoryProduct::destroy(unsigned int flags)
{
    field0 = (void*)0x8d5234;
    field14 = (void*)0x8d5228;
    field18 = (void*)0x8d5220;
    field20 = (void*)0x8d5218;
    sub_5d2b60();
    if (flags & 1)
        sub_718a32(this);
    return this;
}
