// from server: 67% by atomic.potato
struct S_005e6770 {
    char pad[0x44];
    void* field_44;
    void release();
};

extern "C" void __stdcall sub_0048d4d0(void*);
extern "C" void __stdcall sub_0080b2ea(void*, void*, void*, void*, void*);

void S_005e6770::release()
{
    if (this == 0)
        return;
    if (field_44 != 0)
        sub_0048d4d0(field_44);
    sub_0080b2ea(this, 0, (void*)0xc071f8, (void*)0xc17c14, 0);
}
