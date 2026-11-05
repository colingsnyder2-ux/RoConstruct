// from server: 100% by colin
struct Base {
    void construct(int);
};

struct FactoryProduct : Base {
    char pad0[0x10];
    void* vtable_10;
    void* vtable_14;
    char pad1[0x14];
    void* vtable_2c;
    char pad2[0x14];
    void* vtable_44;
    char pad3[0x14];
    void* vtable_5c;
    char pad4[0x14];
    void* vtable_74;
    char pad5[0x14];
    void* vtable_8c;
    char pad6[0x58];
    void* vtable_e8;
    FactoryProduct(int);
};

FactoryProduct::FactoryProduct(int arg) {
    Base::construct(arg);
    *(void**)((char*)this + 0) = (void*)0x7bbfdc;
    *(void**)((char*)this + 4) = (void*)0x7bbfd4;
    vtable_10 = (void*)0x7bbfcc;
    vtable_14 = (void*)0x7bbfbc;
    vtable_2c = (void*)0x7bbfac;
    vtable_44 = (void*)0x7bbf9c;
    vtable_5c = (void*)0x7bbf8c;
    vtable_74 = (void*)0x7bbf7c;
    vtable_8c = (void*)0x7bbf6c;
    vtable_e8 = (void*)0x7bbf54;
}
