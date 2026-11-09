// from server: 58% by colin
struct S {
    char pad[0x100];
    int f();
};

extern "C" void __stdcall sub_444e20();
extern "C" void __stdcall sub_541bf0();
extern "C" void __stdcall sub_77e698();
extern "C" void __stdcall sub_77e6ac();

struct Str {
    char buf[0x1c];
    Str(const char*);
    ~Str();
};

int S::f()
{
    sub_444e20();
    *(int*)((char*)this + 0xe8) = 0x7a9184;
    *(int*)((char*)this + 0x00) = 0x7a92a4;
    *(int*)((char*)this + 0x04) = 0x7a9298;
    *(int*)((char*)this + 0x10) = 0x7a9290;
    *(int*)((char*)this + 0x14) = 0x7a9280;
    *(int*)((char*)this + 0x2c) = 0x7a9270;
    *(int*)((char*)this + 0x44) = 0x7a9260;
    *(int*)((char*)this + 0x5c) = 0x7a9250;
    *(int*)((char*)this + 0x74) = 0x7a9240;
    *(int*)((char*)this + 0x8c) = 0x7a9230;
    *(int*)((char*)this + 0xe8) = 0x7a9228;
    *(int*)((char*)this + 0xec) = 0;
    *(int*)((char*)this + 0xf0) = 0;
    *(int*)((char*)this + 0xf8) = 0;
    *(int*)((char*)this + 0xfc) = 0;
    *(int*)((char*)this + 0x100) = 0;
    {
        Str s((const char*)0x7a9210);
        sub_541bf0();
    }
    return (int)this;
}
