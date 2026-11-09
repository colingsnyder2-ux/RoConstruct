// from server: 100% by colin
struct CXTPControlCheckBox {
    int pad0;
    int pad4;
    int pad8;
    int padc;
    int pad10;
    int pad14;
    int pad18;
    int pad1c;
    int field20;
    char pad24[0xf8 - 0x24];
    int fieldf8;
    CXTPControlCheckBox* ctor();
};

extern void base_ctor_6ca460();

CXTPControlCheckBox* CXTPControlCheckBox::ctor()
{
    base_ctor_6ca460();
    *(int*)this = 0x7ce59c;
    *(int*)((char*)this + 0x20) = 0x7ce53c;
    *(int*)((char*)this + 0xf8) = 9;
    return this;
}
