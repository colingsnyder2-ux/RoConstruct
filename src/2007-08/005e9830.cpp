// from server: 100% by colin
struct VExplosionSignalDesc {
    void construct();
};

extern "C" void __stdcall sub_576480();

void VExplosionSignalDesc::construct()
{
    int* p = *(int**)((char*)this + 0xec);
    *(int*)((char*)this + 0x00) = 0x7bdd74;
    *(int*)((char*)this + 0x04) = 0x7bdd68;
    *(int*)((char*)this + 0x10) = 0x7bdd60;
    *(int*)((char*)this + 0x14) = 0x7bdd50;
    *(int*)((char*)this + 0x2c) = 0x7bdd40;
    *(int*)((char*)this + 0x44) = 0x7bdd30;
    *(int*)((char*)this + 0x5c) = 0x7bdd20;
    *(int*)((char*)this + 0x74) = 0x7bdd10;
    *(int*)((char*)this + 0x8c) = 0x7bdd00;
    *(int*)((char*)this + 0xe8) = 0x7bdcf4;
    *(int*)((char*)this + 0x158) = 0x7bdce4;
    *(int*)((char*)this + 0x170) = 0x7bdcd8;
    *(int*)((char*)this + 0x17c) = 0x7bdcc0;

    int* q = *(int**)((char*)p + 4);
    *(int*)((char*)q + (int)this + 0xec) = 0x7bdcb4;

    p = *(int**)((char*)this + 0xec);
    q = *(int**)((char*)p + 8);
    *(int*)((char*)q + (int)this + 0xec) = 0x7bdcac;

    p = *(int**)((char*)this + 0xec);
    q = *(int**)((char*)p + 0xc);
    *(int*)((char*)q + (int)this + 0xec) = 0x7bdc90;

    p = *(int**)((char*)this + 0xec);
    q = *(int**)((char*)p + 4);
    *(int*)((char*)q + (int)this + 0xe8) = (int)q - 0x198;

    p = *(int**)((char*)this + 0xec);
    q = *(int**)((char*)p + 8);
    *(int*)((char*)q + (int)this + 0xe8) = (int)q - 0x1a0;

    p = *(int**)((char*)this + 0xec);
    q = *(int**)((char*)p + 0xc);
    *(int*)((char*)q + (int)this + 0xe8) = (int)q - 0x1a8;

    sub_576480();
}
