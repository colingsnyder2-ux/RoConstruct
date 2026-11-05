// from server: 36% by atomic.potato
extern "C" void* __cdecl sub_80a05e(unsigned int);
extern "C" void __stdcall sub_5e3da0(void*, void*);

struct S {
    void ctor();
    void addProp(int, void*);
    void* makeNode();
};

void* S::makeNode() {
    return sub_80a05e(0x18);
}

void S::addProp(int a, void* b) {
    void* p = sub_80a05e(0x18);
    (void)p;
    (void)a;
    (void)b;
}

void S::ctor() {
    void* p;
    void* q;
    sub_5e3da0(this, (void*)0xc3d31c);
    *(void**)this = (void*)0xa8eb10;
    p = sub_80a05e(0x18);
    *(void**)((char*)this + 0x30) = p;
    *(unsigned char*)((char*)p + 0x15) = 1;
    p = *(void**)((char*)this + 0x30);
    *(void**)((char*)p + 4) = p;
    p = *(void**)((char*)this + 0x30);
    *(void**)p = p;
    p = *(void**)((char*)this + 0x30);
    *(void**)((char*)p + 8) = p;
    *(void**)((char*)this + 0x34) = 0;
    q = sub_80a05e(0x18);
    *(void**)((char*)this + 0x3c) = q;
    *(unsigned char*)((char*)q + 0x15) = 1;
    q = *(void**)((char*)this + 0x3c);
    *(void**)((char*)q + 4) = q;
    q = *(void**)((char*)this + 0x3c);
    *(void**)q = q;
    q = *(void**)((char*)this + 0x3c);
    *(void**)((char*)q + 8) = q;
    *(void**)((char*)this + 0x40) = 0;
    *(void**)((char*)this + 0x48) = 0;
    *(void**)((char*)this + 0x4c) = 0;
    *(void**)((char*)this + 0x50) = 0;
    *(void**)((char*)this + 0x58) = 0;
    *(void**)((char*)this + 0x5c) = 0;
    *(void**)((char*)this + 0x60) = 0;
    *(void**)((char*)this + 0x68) = 0;
    *(void**)((char*)this + 0x6c) = 0;
    *(void**)((char*)this + 0x70) = 0;
    *(void**)((char*)this + 0x78) = 0;
    *(void**)((char*)this + 0x7c) = 0;
    *(void**)((char*)this + 0x80) = 0;
    *(void**)((char*)this + 0x88) = 0;
    *(void**)((char*)this + 0x8c) = 0;
    *(void**)((char*)this + 0x90) = 0;
    *(void**)((char*)this + 0x98) = 0;
    *(void**)((char*)this + 0x9c) = 0;
    *(void**)((char*)this + 0xa0) = 0;
    addProp(0, (void*)0xaa33e8);
    addProp(1, (void*)0xaa33e0);
    addProp(2, (void*)0xa6b59c);
    addProp(3, (void*)0xaa33d8);
    addProp(4, (void*)0xaa33d0);
    addProp(5, (void*)0xaa33c8);
    addProp(6, (void*)0xaa33c0);
    addProp(7, (void*)0xaa33b8);
}
