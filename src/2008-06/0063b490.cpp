// from server: 100% by tester
struct S_func_0063b490 {
    char pad0[0x10];
    char pad10[0x10];
    char pad20[0x24];
    char pad44[0x20];
    char pad64[0x20];
    char pad84[0x20];
    char pada4[0x20];
    char padc4[0x4];
    S_func_0063b490* f(void* arg);
};

extern "C" void __stdcall sub_0055b960(void* arg);

S_func_0063b490* S_func_0063b490::f(void* arg)
{
    sub_0055b960(arg);
    *(int*)((char*)this + 0x00) = 0x84991c;
    *(int*)((char*)this + 0x10) = 0x84990c;
    *(int*)((char*)this + 0x14) = 0x849904;
    *(int*)((char*)this + 0x20) = 0x8498fc;
    *(int*)((char*)this + 0x24) = 0x8498ec;
    *(int*)((char*)this + 0x44) = 0x8498dc;
    *(int*)((char*)this + 0x64) = 0x8498cc;
    *(int*)((char*)this + 0x84) = 0x8498bc;
    *(int*)((char*)this + 0xa4) = 0x8498ac;
    *(int*)((char*)this + 0xc4) = 0x84989c;
    return this;
}
