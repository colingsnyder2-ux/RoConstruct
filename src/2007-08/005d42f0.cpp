// from server: 100% by colin
struct Mouse {
    char pad[0xec];
    Mouse();
};

extern "C" void __fastcall sub_59EC40(Mouse* self);

Mouse::Mouse()
{
    sub_59EC40(this);
    *(int*)((char*)this + 0x00) = 0x7bb074;
    *(int*)((char*)this + 0x04) = 0x7bb06c;
    *(int*)((char*)this + 0x10) = 0x7bb064;
    *(int*)((char*)this + 0x14) = 0x7bb054;
    *(int*)((char*)this + 0x2c) = 0x7bb044;
    *(int*)((char*)this + 0x44) = 0x7bb034;
    *(int*)((char*)this + 0x5c) = 0x7bb024;
    *(int*)((char*)this + 0x74) = 0x7bb014;
    *(int*)((char*)this + 0x8c) = 0x7bb004;
    *(int*)((char*)this + 0xe8) = 0x7baffc;
}
