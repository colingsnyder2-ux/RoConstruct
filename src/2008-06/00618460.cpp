// from server: 100% by atomic.potato
struct Flag {
    char pad0[0x10];
    void* vt10;
    void* vt14;
    char pad18[8];
    void* vt20;
    void* vt24;
    char pad28[0x1c];
    void* vt44;
    char pad48[0x1c];
    void* vt64;
    char pad68[0x1c];
    void* vt84;
    char pad88[0x1c];
    void* vta4;
    char padA8[0x1c];
    void* vtc4;
    char padC8[0x68];
    void* vt130;
    char pad134[0x6c];
    void* vt1a0;
    char pad1a4[0xc];
    void* vt1b0;
    char pad1b4[0xc];
    void* vt1c0;
    Flag* init(int);
};

extern "C" void __stdcall sub_600240(int);

Flag* Flag::init(int a) {
    if (a != 0) {
        *(void**)((char*)this + 0x1c0) = (void*)0x843de0;
    }
    sub_600240(0);
    void* p = *(void**)((char*)this + 0x1c0);
    *(void**)this = (void*)0x843d4c;
    *(void**)((char*)this + 0x10) = (void*)0x843d3c;
    *(void**)((char*)this + 0x14) = (void*)0x843d34;
    *(void**)((char*)this + 0x20) = (void*)0x843d2c;
    *(void**)((char*)this + 0x24) = (void*)0x843d1c;
    *(void**)((char*)this + 0x44) = (void*)0x843d0c;
    *(void**)((char*)this + 0x64) = (void*)0x843cfc;
    *(void**)((char*)this + 0x84) = (void*)0x843cec;
    *(void**)((char*)this + 0xa4) = (void*)0x843cdc;
    *(void**)((char*)this + 0xc4) = (void*)0x843ccc;
    *(void**)((char*)this + 0x130) = (void*)0x843cc4;
    *(void**)((char*)this + 0x1a0) = (void*)0x843cbc;
    *(void**)((char*)this + 0x1b0) = (void*)0x843ca4;
    int* q = *(int**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0x1c0) = (void*)0x843c9c;
    void* r = *(void**)((char*)this + 0x1c0);
    int* s = *(int**)((char*)r + 4);
    int t = (int)s - 0xac;
    *(int*)((char*)s + (int)this + 0x1bc) = t;
    return this;
}
