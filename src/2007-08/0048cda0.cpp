// from server: 10% by colin
// roc 2007-08 0048cda0  unit: RBX::VHumanoid::?$FactoryProduct::Creator
// Make this compile to the exact bytes below, then: roc check 2007-08 0048cda0

struct CreatorList {
    void* begin;
    void* end;
    void* cap;
};

struct FactoryProduct {
    char pad[0x130];
    CreatorList creators;
    FactoryProduct();
};

extern "C" void __cdecl sub_725520(void*, void*);
extern "C" void __cdecl sub_487430();

extern unsigned char byte_8bdcc8;

FactoryProduct::FactoryProduct()
{
    sub_725520(&byte_8bdcc8, (void*)0x487be0);
    sub_487430();
}
