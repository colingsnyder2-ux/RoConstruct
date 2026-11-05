// from server: 100% by colin
struct S_005b2640
{
    char pad[0xec];
    S_005b2640* ctor(int);
};

extern void __stdcall G1_func_005b1e90(int);

S_005b2640* S_005b2640::ctor(int arg)
{
    G1_func_005b1e90(arg);
    *(int*)((char*)this + 0x00) = 0x7b7cac;
    *(int*)((char*)this + 0x04) = 0x7b7ca4;
    *(int*)((char*)this + 0x10) = 0x7b7c9c;
    *(int*)((char*)this + 0x14) = 0x7b7c8c;
    *(int*)((char*)this + 0x2c) = 0x7b7c7c;
    *(int*)((char*)this + 0x44) = 0x7b7c6c;
    *(int*)((char*)this + 0x5c) = 0x7b7c5c;
    *(int*)((char*)this + 0x74) = 0x7b7c4c;
    *(int*)((char*)this + 0x8c) = 0x7b7c3c;
    *(int*)((char*)this + 0xe8) = 0x7b7c24;
    return this;
}
