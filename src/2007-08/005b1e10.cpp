// from server: 100% by colin
struct S_005b1e10
{
    char pad[0xec];
    S_005b1e10* ctor(int);
};

extern void __stdcall G1_func_005b1950(int);

S_005b1e10* S_005b1e10::ctor(int arg)
{
    G1_func_005b1950(arg);
    *(int*)((char*)this + 0x00) = 0x7b7624;
    *(int*)((char*)this + 0x04) = 0x7b761c;
    *(int*)((char*)this + 0x10) = 0x7b7614;
    *(int*)((char*)this + 0x14) = 0x7b7604;
    *(int*)((char*)this + 0x2c) = 0x7b75f4;
    *(int*)((char*)this + 0x44) = 0x7b75e4;
    *(int*)((char*)this + 0x5c) = 0x7b75d4;
    *(int*)((char*)this + 0x74) = 0x7b75c4;
    *(int*)((char*)this + 0x8c) = 0x7b75b4;
    *(int*)((char*)this + 0xe8) = 0x7b759c;
    return this;
}
