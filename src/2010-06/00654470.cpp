// from server: 100% by atomic.potato
struct RBX_ExtrudedPartInstance {
    char pad0[0x18];
    void* field18;
    void* field1c;
    char pad20[0x74];
    void* field94;
    void* field98;
    char pad9c[0x8];
    void* fielda4;
    char pada8[0x8];
    void* fieldb0;
    char padb4[0xc];
    void* fieldc0;
    void sub_0063db40();
    void sub_00654470();
};

void RBX_ExtrudedPartInstance::sub_00654470()
{
    void* p = field98;
    *(void**)this = (void*)0xa39864;
    *(void**)((char*)this + 4) = (void*)0xa39858;
    field18 = (void*)0xa3984c;
    field1c = (void*)0xa39840;
    field94 = (void*)0xa39838;
    fielda4 = (void*)0xa39824;
    fieldb0 = (void*)0xa3980c;
    fieldc0 = (void*)0xa397e4;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0x98) = (void*)0xa397dc;
    void* r = field98;
    void* s = *(void**)((char*)r + 4);
    *(void**)((char*)s + (int)this + 0x94) = (void*)((char*)s - 0x1ec);
    sub_0063db40();
}
