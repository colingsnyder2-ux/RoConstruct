// from server: 100% by atomic.potato
struct Accoutrement {
    void init();
    char pad0[0xb4];
    void* field_b4;
};

void tail();

void Accoutrement::init() {
    void* p = field_b4;
    *(void**)this = (void*)0xa31d6c;
    *(void**)((char*)this + 4) = (void*)0xa31d64;
    *(void**)((char*)this + 0x18) = (void*)0xa31d58;
    *(void**)((char*)this + 0x1c) = (void*)0xa31d4c;
    *(void**)((char*)this + 0x94) = (void*)0xa31d44;
    *(void**)((char*)this + 0xa0) = (void*)0xa31d2c;
    *(void**)((char*)this + 0xb0) = (void*)0xa31d04;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0xb4) = (void*)0xa31cfc;
    void* r = *(void**)((char*)field_b4 + 4);
    *(void**)((char*)r + (int)this + 0xb0) = (char*)r - 0x60;
    tail();
}
