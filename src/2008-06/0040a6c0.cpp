// from server: 100% by colin
struct TypedPropertyDescriptor {
    char pad0[0x10];
    void* p10;
    void* p14;
    char pad18[0x8];
    void* p20;
    void* p24;
    char pad28[0x1c];
    void* p44;
    char pad48[0x1c];
    void* p64;
    char pad68[0x1c];
    void* p84;
    char pad88[0x1c];
    void* pa4;
    char pada8[0x1c];
    void* pc4;
    void init();
};

extern int g_96c39c;

void sub_40a0e0();

void TypedPropertyDescriptor::init()
{
    *(void**)this = (void*)0x80bb14;
    p10 = (void*)0x80bb04;
    p14 = (void*)0x80bafc;
    p20 = (void*)0x80baf4;
    p24 = (void*)0x80bae4;
    p44 = (void*)0x80bad4;
    p64 = (void*)0x80bac4;
    p84 = (void*)0x80bab4;
    pa4 = (void*)0x80baa4;
    pc4 = (void*)0x80ba94;
    g_96c39c = 0;
    sub_40a0e0();
}
