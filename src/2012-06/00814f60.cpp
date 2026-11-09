// from server: 86% by Intel
extern "C" void __stdcall sub_811A80(void* obj);
extern "C" void __stdcall sub_982114(void* obj);

struct VMotor_FactoryProduct {
    void* vtable0;
    void* vtable1;
    char padding1[0x14];
    void* vtable2;
    void* vtable3;
    char padding2[0x60];
    void* vtable4;

    VMotor_FactoryProduct* __thiscall Initialize(int arg);
};

VMotor_FactoryProduct* __thiscall VMotor_FactoryProduct::Initialize(int arg) {
    this->vtable0 = (void*)0x00BC671C;
    this->vtable1 = (void*)0x00BC6710;
    this->vtable2 = (void*)0x00BC6704;
    this->vtable3 = (void*)0x00BC66F8;
    this->vtable4 = (void*)0x00BC66CC;

    sub_811A80(this);

    if (arg & 1) {
        sub_982114(this);
    }

    return this;
}
