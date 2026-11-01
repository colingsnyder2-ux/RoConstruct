// from server: 100% by colin
struct FactoryProduct {
    char pad[0x90];
    FactoryProduct* construct(int arg);
};

extern "C" void __stdcall sub_53daf0(int arg);

FactoryProduct* FactoryProduct::construct(int arg) {
    sub_53daf0(arg);
    *(int*)((char*)this + 0x00) = 0x7a61ac;
    *(int*)((char*)this + 0x04) = 0x7a61a4;
    *(int*)((char*)this + 0x10) = 0x7a619c;
    *(int*)((char*)this + 0x14) = 0x7a618c;
    *(int*)((char*)this + 0x2c) = 0x7a617c;
    *(int*)((char*)this + 0x44) = 0x7a616c;
    *(int*)((char*)this + 0x5c) = 0x7a615c;
    *(int*)((char*)this + 0x74) = 0x7a614c;
    *(int*)((char*)this + 0x8c) = 0x7a613c;
    return this;
}
