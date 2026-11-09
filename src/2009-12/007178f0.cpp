// from server: 100% by atomic.potato
struct RBX_VRotate_FactoryProduct {
    char pad0[0x94];
    void* field94;
    void* construct(void*);
};

extern "C" void __stdcall sub_7177f0(void*);

void* RBX_VRotate_FactoryProduct::construct(void* arg) {
    sub_7177f0(arg);
    *(void**)this = (void*)0x9df3f4;
    *(void**)((char*)this + 4) = (void*)0x9df3e8;
    *(void**)((char*)this + 0x18) = (void*)0x9df3dc;
    *(void**)((char*)this + 0x1c) = (void*)0x9df3d4;
    *(void**)((char*)this + 0x94) = (void*)0x9df3bc;
    return this;
}
