// from server: 100% by colin
struct RBX_Network_VServer_FactoryProduct {
    RBX_Network_VServer_FactoryProduct* construct();
};

extern void base_ctor_004b1870();

RBX_Network_VServer_FactoryProduct* RBX_Network_VServer_FactoryProduct::construct()
{
    base_ctor_004b1870();
    *(int*)((char*)this + 0x00) = 0x79c64c;
    *(int*)((char*)this + 0x04) = 0x79c640;
    *(int*)((char*)this + 0x10) = 0x79c638;
    *(int*)((char*)this + 0x14) = 0x79c628;
    *(int*)((char*)this + 0x2c) = 0x79c618;
    *(int*)((char*)this + 0x44) = 0x79c608;
    *(int*)((char*)this + 0x5c) = 0x79c5f8;
    *(int*)((char*)this + 0x74) = 0x79c5e8;
    *(int*)((char*)this + 0x8c) = 0x79c5d8;
    *(int*)((char*)this + 0xe8) = 0x79c5a8;
    *(int*)((char*)this + 0xec) = 0x79c59c;
    return this;
}
