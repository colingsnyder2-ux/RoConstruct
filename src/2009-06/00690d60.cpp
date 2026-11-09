// from server: 100% by tester
struct RBX_VBodyThrust_FactoryProduct {
    char pad[0x128];
    void* ctor(int flags);
};

extern "C" void __cdecl sub_6906E0();
extern "C" void __cdecl sub_718A32(void*);

void* RBX_VBodyThrust_FactoryProduct::ctor(int flags) {
    *(int*)((char*)this + 0x00) = 0x8e6b7c;
    *(int*)((char*)this + 0x14) = 0x8e6b6c;
    *(int*)((char*)this + 0x18) = 0x8e6b64;
    *(int*)((char*)this + 0x20) = 0x8e6b5c;
    *(int*)((char*)this + 0x8c) = 0x8e6b14;
    *(int*)((char*)this + 0xac) = 0x8e6af4;
    *(int*)((char*)this + 0x124) = 0x8e6ad8;
    sub_6906E0();
    if (flags & 1) {
        sub_718A32(this);
    }
    return this;
}
