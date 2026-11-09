// from server: 54% by tester
struct CXTPControlEdit {
    char pad[0x1b0];
    int f();
};

extern "C" void __stdcall sub_9872F0();
extern "C" void __stdcall sub_A9958A();
extern "C" void __stdcall sub_B24784();
extern "C" void __stdcall sub_B24778();

int CXTPControlEdit::f()
{
    sub_9872F0();
    *(int*)this = 0xc1d0ec;
    *(int*)((char*)this + 0x20) = 0xc1d08c;
    sub_B24784();
    sub_B24784();
    sub_B24784();
    sub_A9958A();
    *(int*)((char*)this + 0xfc) = 6;
    *(int*)((char*)this + 0x160) = 0x64;
    *(int*)((char*)this + 0x180) = 0;
    *(int*)((char*)this + 0x178) = 0;
    sub_B24778();
    *(int*)((char*)this + 0x174) = 0;
    *(int*)((char*)this + 0x17c) = 0;
    *(int*)((char*)this + 0x184) = 0;
    *(int*)((char*)this + 0x188) = 0;
    *(int*)((char*)this + 0x190) = 0;
    *(int*)((char*)this + 0x1a0) = 0;
    *(int*)((char*)this + 0x1a4) = 0;
    *(int*)((char*)this + 0x19c) = 1;
    *(int*)((char*)this + 0x1a8) = 0;
    *(int*)((char*)this + 0x1ac) = 0;
    return (int)this;
}
