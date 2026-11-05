// from server: 100% by atomic.potato
struct RBX_BaseClass {
    void construct(int);
};

struct RBX_VAccoutrement : RBX_BaseClass {
    char pad[0xf8];
    void* field_f8;
    char pad2[0x80];
    void* field_17c;
    void* construct(int);
};

void* RBX_VAccoutrement::construct(int b) {
    if (b) {
        field_f8 = (void*)0x7ac5c0;
        field_17c = (void*)0x7a4ccc;
    }
    RBX_BaseClass::construct(0);
    void* p = field_f8;
    *(void**)this = (void*)0x7ac2ac;
    *(void**)((char*)this + 4) = (void*)0x7ac2a4;
    *(void**)((char*)this + 0x10) = (void*)0x7ac29c;
    *(void**)((char*)this + 0x14) = (void*)0x7ac28c;
    *(void**)((char*)this + 0x2c) = (void*)0x7ac27c;
    *(void**)((char*)this + 0x44) = (void*)0x7ac26c;
    *(void**)((char*)this + 0x5c) = (void*)0x7ac25c;
    *(void**)((char*)this + 0x74) = (void*)0x7ac24c;
    *(void**)((char*)this + 0x8c) = (void*)0x7ac23c;
    *(void**)((char*)this + 0xe8) = (void*)0x7ac224;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0xf8) = (void*)0x7ac21c;
    void* r = field_f8;
    void* s = *(void**)((char*)r + 4);
    *(void**)((char*)s + (int)this + 0xf4) = (void*)((char*)s - 0x84);
    return this;
}
