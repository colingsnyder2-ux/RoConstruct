// from server: 45% by colin
struct BaseClass {
    BaseClass();
    void* vtable;
};

struct FactoryProduct : BaseClass {
    char pad_0x08[0xe0];
    unsigned char field_0xe8;
    unsigned char field_0xe9;
    unsigned char field_0xea;
    char pad_0xeb[0x01];
    void* field_0xec;

    FactoryProduct();
};

extern "C" void __stdcall sub_426620();
extern "C" void* __stdcall sub_77e6a4();

FactoryProduct::FactoryProduct()
{
    sub_426620();
    this->vtable = (void*)0x789a0c;
    *(void**)((char*)this + 4) = (void*)0x789a04;
    *(void**)((char*)this + 0x10) = (void*)0x7899fc;
    *(void**)((char*)this + 0x14) = (void*)0x7899ec;
    *(void**)((char*)this + 0x2c) = (void*)0x7899dc;
    *(void**)((char*)this + 0x44) = (void*)0x7899cc;
    *(void**)((char*)this + 0x5c) = (void*)0x7899bc;
    *(void**)((char*)this + 0x74) = (void*)0x7899ac;
    *(void**)((char*)this + 0x8c) = (void*)0x78999c;
    this->field_0xe8 = 1;
    this->field_0xe9 = 0;
    this->field_0xea = 0;
    sub_77e6a4();
}
