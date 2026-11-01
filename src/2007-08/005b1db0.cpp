// from server: 100% by colin
struct S_func_005b1db0
{
    char pad[0x100];
    S_func_005b1db0* ctor(int);
};

extern void __stdcall G1_func_005b18b0(int);

S_func_005b1db0* S_func_005b1db0::ctor(int a)
{
    G1_func_005b18b0(a);
    *(int*)((char*)this + 0x00) = 0x7b7554;
    *(int*)((char*)this + 0x04) = 0x7b754c;
    *(int*)((char*)this + 0x10) = 0x7b7544;
    *(int*)((char*)this + 0x14) = 0x7b7534;
    *(int*)((char*)this + 0x2c) = 0x7b7524;
    *(int*)((char*)this + 0x44) = 0x7b7514;
    *(int*)((char*)this + 0x5c) = 0x7b7504;
    *(int*)((char*)this + 0x74) = 0x7b74f4;
    *(int*)((char*)this + 0x8c) = 0x7b74e4;
    *(int*)((char*)this + 0xe8) = 0x7b74cc;
    return this;
}
