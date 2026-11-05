// from server: 100% by tester
struct S {
    char pad0[0x10];
    char pad10[0x10];
    char pad20[0x10];
    char pad30[0x14];
    char pad44[0x20];
    char pad64[0x20];
    char pad84[0x20];
    char padA4[0x20];
    char padC4[4];
    S* ctor(int);
};

extern "C" void __stdcall sub_55B960(int);

S* S::ctor(int a) {
    sub_55B960(a);
    *(int*)((char*)this + 0x00) = 0x8310dc;
    *(int*)((char*)this + 0x10) = 0x8310cc;
    *(int*)((char*)this + 0x14) = 0x8310c4;
    *(int*)((char*)this + 0x20) = 0x8310bc;
    *(int*)((char*)this + 0x24) = 0x8310ac;
    *(int*)((char*)this + 0x44) = 0x83109c;
    *(int*)((char*)this + 0x64) = 0x83108c;
    *(int*)((char*)this + 0x84) = 0x83107c;
    *(int*)((char*)this + 0xa4) = 0x83106c;
    *(int*)((char*)this + 0xc4) = 0x83105c;
    return this;
}
