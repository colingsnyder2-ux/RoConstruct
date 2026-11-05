// from server: 100% by colin
struct S_005b2520
{
    char pad[0xec];
    S_005b2520* ctor(int);
};

extern void __stdcall G1_func_005b1e10(int);

S_005b2520* S_005b2520::ctor(int arg)
{
    G1_func_005b1e10(arg);
    *(int*)((char*)this + 0x00) = 0x7b7bdc;
    *(int*)((char*)this + 0x04) = 0x7b7bd4;
    *(int*)((char*)this + 0x10) = 0x7b7bcc;
    *(int*)((char*)this + 0x14) = 0x7b7bbc;
    *(int*)((char*)this + 0x2c) = 0x7b7bac;
    *(int*)((char*)this + 0x44) = 0x7b7b9c;
    *(int*)((char*)this + 0x5c) = 0x7b7b8c;
    *(int*)((char*)this + 0x74) = 0x7b7b7c;
    *(int*)((char*)this + 0x8c) = 0x7b7b6c;
    *(int*)((char*)this + 0xe8) = 0x7b7b54;
    return this;
}
