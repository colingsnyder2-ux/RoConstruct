// from server: 42% by colin
struct VReplicatorBoundFuncDesc {
    char pad[0x100];
    int field_f4;
    int field_f8;
    int ctor();
};

extern "C" void __stdcall sub_4b10e0();
extern "C" void __stdcall sub_4992e0();
extern "C" void __stdcall sub_62fef6(unsigned int);
extern "C" void __stdcall sub_591c80();
extern "C" void __stdcall sub_4be7d0();

int VReplicatorBoundFuncDesc::ctor()
{
    sub_4b10e0();
    sub_4992e0();
    *(int*)((char*)this + 0xec) = 0x795b60;
    *(int*)((char*)this + 0x00) = 0x79d704;
    *(int*)((char*)this + 0x04) = 0x79d6f8;
    *(int*)((char*)this + 0x10) = 0x79d6f0;
    *(int*)((char*)this + 0x14) = 0x79d6e0;
    *(int*)((char*)this + 0x2c) = 0x79d6d0;
    *(int*)((char*)this + 0x44) = 0x79d6c0;
    *(int*)((char*)this + 0x5c) = 0x79d6b0;
    *(int*)((char*)this + 0x74) = 0x79d6a0;
    *(int*)((char*)this + 0x8c) = 0x79d690;
    *(int*)((char*)this + 0xe8) = 0x79d660;
    *(int*)((char*)this + 0xec) = 0x79d654;
    *(int*)((char*)this + 0xf0) = 0;

    sub_62fef6(0x20040);
    void* p1 = (void*)0;
    if (p1) {
        sub_591c80();
    }
    *(int*)((char*)this + 0xf4) = (int)p1;

    sub_62fef6(0x900);
    void* p2 = (void*)0;
    if (p2) {
        sub_4be7d0();
    }
    *(int*)((char*)this + 0xf8) = (int)p2;

    void* p3 = (void*)*(int*)((char*)this + 0xf8);
    void** vtbl = *(void***)p3;
    void (*fn)(void*, void*) = (void (*)(void*, void*))vtbl[0xe8/4];
    fn(p3, (void*)((char*)this + 0xe8));

    return (int)this;
}
